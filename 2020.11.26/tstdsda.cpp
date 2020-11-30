#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MOD 19260817
#define int long long
using namespace std;
int n,m,q;
int jc[4000000];
int qpow(int a,int b){
    if(!b)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int C(int m,int n){
    if(m<n)return 0;
    return jc[m]*qpow(jc[n],MOD-2)%MOD*qpow(jc[m-n],MOD-2)%MOD;
}
int head[200000],nxt[500000],to[500000],cnt;
int added[200000];
void add(int a,int b){
    if(a>n||b>n){
        exit(0);
    }
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int f[200000];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
struct seg{
    struct node{
        int ls,rs,sum;
    }a[4000000];
    int tot=0;
    int newNode(){
        a[++tot]={-1,-1,0};
        return tot;
    }
    void pushup(int now){
        a[now].sum=0;
        if(a[now].ls!=-1)a[now].sum+=a[a[now].ls].sum;
        if(a[now].rs!=-1)a[now].sum+=a[a[now].rs].sum;
    }
    void add(int now,int l,int r,int pos,int v){
        if(l==r){
            a[now].sum+=v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid){
            if(a[now].ls==-1)a[now].ls=newNode();
            add(a[now].ls,l,mid,pos,v);
        }
        else{
            if(a[now].rs==-1)a[now].rs=newNode();
            add(a[now].rs,mid+1,r,pos,v);
        }
        pushup(now);
    }
    int query(int now,int l,int r,int L,int R){
        if(l==L&&r==R){
            return a[now].sum;
        }
        int mid=(l+r)/2;
        if(R<=mid){
            if(a[now].ls==-1)return 0;
            return query(a[now].ls,l,mid,L,R);
        }
        else if(L>mid){
            if(a[now].rs==-1)return 0;
            return query(a[now].rs,mid+1,r,L,R);
        }
        else{
            int sum=0;
            if(a[now].ls!=-1)sum+=query(a[now].ls,l,mid,L,mid);
            if(a[now].rs!=-1)sum+=query(a[now].rs,mid+1,r,mid+1,R);
            return sum;    
        }
    }
    int merge(int x,int y){
        if(x==y)return x;
        if(x==-1)return y;
        if(y==-1)return x;
        a[x].sum+=a[y].sum;
        a[x].ls=merge(a[x].ls,a[y].ls);
        a[x].rs=merge(a[x].rs,a[y].rs);
        return x;
    }
}base;
int root[200000];
int u[200000],v[200000];
int med[200000];
void dfs(int now){
    med[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(!med[to[i]]){
            dfs(to[i]);
            root[now]=base.merge(root[gf(now)],root[gf(to[i])]);
            f[gf(to[i])]=gf(now);
        }
    }
}
int del[200000];
struct query{
    int opt,a,b,c;
}que[200000];
int del_num[200000];
signed main(){
    freopen("mc.in","r",stdin);
    freopen("mc.out","w",stdout);
    jc[0]=1;
    for(int i=1;i<=2000000;i++){
        jc[i]=jc[i-1]*i%MOD;
    }
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        root[i]=base.newNode();
        base.add(root[i],0,n,b,a);
        f[i]=i;
        //cerr<<"making "<<i<<endl;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&u[i],&v[i]);
    }
    for(int i=1;i<=q;i++){
        scanf("%lld",&que[i].opt);
        if(que[i].opt==1){
            scanf("%lld%lld%lld",&que[i].a,&que[i].b,&que[i].c);
            base.add(root[gf(que[i].a)],0,n,que[i].c,que[i].b);
        }
        else if(que[i].opt==2){
            scanf("%lld",&que[i].a);
            del[que[i].a]=1;
            del_num[que[i].a]++;
        }
        else{
            scanf("%lld%lld%lld",&que[i].a,&que[i].b,&que[i].c);
        }
    }
    for(int i=1;i<=m;i++){
        if(!del[i]){
            add(u[i],v[i]);
            add(v[i],u[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(!med[i])dfs(i);
    }
    vector<int>sol;
    for(int i=q;i>=1;i--){
        if(que[i].opt==1){
            base.add(root[gf(que[i].a)],0,n,que[i].c,-que[i].b);
        }
        else if(que[i].opt==2){
            del_num[que[i].a]--;
            if(del_num[que[i].a])continue;
            root[gf(u[que[i].a])]=base.merge(root[gf(u[que[i].a])],root[gf(v[que[i].a])]);
            f[gf(v[que[i].a])]=gf(u[que[i].a]);
        }
        else{
            int tot=base.query(root[gf(que[i].a)],0,n,0,n);
            int cur=base.query(root[gf(que[i].a)],0,n,que[i].c,que[i].c);
            /*for(int i=1;i<=n;i++){
                cout<<gf(i)<<" ";
            }
            cout<<endl;
            cout<<que[i].a<<" "<<gf(que[i].a)<<" "<<tot<<" "<<cur<<endl;*/
            int ans=C(cur,que[i].b)*qpow(C(tot,que[i].b),MOD-2)%MOD;
            sol.push_back(ans);
        }
    }
    reverse(sol.begin(),sol.end());
    for(auto s:sol){
        printf("%lld\n",s);
    }
    return 0;
}
/*
5 5 5
5 1
9 2
8 1
8 1
6 2
5 2
1 2
2 2
1 1
5 3
1 1 3 2
2 1
3 3 4 1
3 2 3 1
3 1 2 1*/