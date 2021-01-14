#include<bits/stdc++.h>
#define ADD 1000000001
using namespace std;
struct node{
    int l,r,ls,rs,sum;
}a[20000000];
int tot;
void pushup(int now){
    a[now].sum=0;
    if(a[now].ls!=-1)a[now].sum+=a[a[now].ls].sum;
    if(a[now].rs!=-1)a[now].sum+=a[a[now].rs].sum;
}
int newNode(int l,int r){
    a[++tot]={l,r,-1,-1,0};
    return tot;
}
int copyNode(int from){
    a[++tot]=a[from];
    return tot;
}
int add(int old,int pos,int v,bool isNewNode=false){
    int now=old;
    if(!isNewNode){
        now=copyNode(old);
    }
    if(a[now].l==a[now].r){
        a[now].sum+=v;
        return now;
    }
    int mid=(a[now].l+a[now].r)>>1;
    if(pos<=mid){
        if(a[now].ls==-1){
            a[now].ls=newNode(a[now].l,mid);
            a[now].ls=add(a[now].ls,pos,true);
        }
        else a[now].ls=add(a[now].ls,pos,v);
    }
    else{
        if(a[now].rs==-1){
            a[now].rs=newNode(mid+1,a[now].r);
            a[now].rs=add(a[now].rs,pos,v,true);
        }
        else a[now].rs=add(a[now].rs,pos,v);
    }
    pushup(now);
    return now;
}
int query(int now,int old,int k){
    if(a[now].l==a[now].r){
        return a[now].l;
    }
    int lsiz=((now==-1||a[now].ls==-1)?0:a[a[now].ls].sum)-((old==-1||a[old].ls==-1)?0:a[a[old].ls].sum);
    if(lsiz>=k){
        return query(now==-1?-1:a[now].ls,old==-1?-1:a[old].ls,k);
    }
    else{
        return query(now==-1?-1:a[now].rs,old==-1?-1:a[old].rs,k-lsiz);
    }
}
int build(){
    a[++tot]={1,1000000001,-1,-1,0};
    return tot;
}
int roots[1000000];
void set_val(int idx,int v){
    v=ADD-v;
    roots[idx]=add(roots[idx-1],v,1);
}
int lastans;
void query_val(int l,int r,int k){
    printf("%d\n",lastans=ADD-query(roots[r],roots[l-1],k));
}
//------------------------------//
int n,m,q;
struct edge{
    int s,t,v;
    bool operator <(const edge &e)const{
        return v<e.v;
    }
};
vector<edge>v;
vector<int>g[200001];
int f[200001],h[200001],val[200001],vis[200001],cnt;
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
void init(){
    roots[0]=build();
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=2*n;i++)f[i]=i;
    cnt=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v.push_back({x,y,z});
    }
}
int fa[200001][20],dfn[200001],mi[200001],mx[200001],T;
void dfs(int now,int pre){
    vis[now]=1;
    if(now<=n){
        dfn[now]=mi[now]=mx[now]=++T;
        set_val(T,h[now]);
    }
    else{
        mi[now]=INT_MAX;mx[now]=INT_MIN;
    }
    fa[now][0]=pre;
    for(int i=1;i<=19;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for(auto to:g[now]){
        dfs(to,now);
        mi[now]=min(mi[now],mi[to]);
        mx[now]=max(mx[now],mx[to]);
    }
}
int main(){
    init();
    sort(v.begin(),v.end());
    for(auto e:v){
        int fs=gf(e.s),ft=gf(e.t);
        if(fs==ft)continue;
        cnt++;
        f[fs]=f[ft]=cnt;
        g[cnt].push_back(fs);
        g[cnt].push_back(ft);
        val[cnt]=e.v;
    }
    for(int i=cnt;i>=1;i--){
        if(!vis[i]){
            dfs(i,i);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x^=lastans;y^=lastans;z^=lastans;
        for(int i=19;i>=0;i--){
            if(val[fa[x][i]]<=y){
                x=fa[x][i];
            }
        }
        if(mx[x]-mi[x]+1<z){
            puts("-1");
            lastans=0;
        }
        else
        query_val(mi[x],mx[x],z);
    }
    return 0;
}