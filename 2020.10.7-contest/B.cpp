#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int head[100001],nxt[200001],to[200001],cnt;
int type;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
namespace seg{
    struct tree{
        struct node{
            int l,r,v,ls,rs;
        }a[2000000];
        int tot;
        void pushup(int now){
            a[now].v=a[a[now].ls].v+a[a[now].rs].v;
        }
        int build(int l,int r){
            int now=++tot;
            a[now].l=l;a[now].r=r;
            if(l==r)return now;
            int mid=(l+r)/2;
            a[now].ls=build(l,mid);
            a[now].rs=build(mid+1,r);
            return now;
        }
        int query(int now,int pos){
            if(a[now].l==a[now].r)return a[now].v;
            int mid=(a[now].l+a[now].r)/2;
            if(pos<=mid){
                return query(a[now].ls,pos);
            }
            else{
                return query(a[now].rs,pos);
            }
        }
        int add(int from,int pos){
            int now=++tot;
            a[now]=a[from];
            if(a[now].l==a[now].r){
                a[now].v=1-a[now].v;
                return now;
            }
            int mid=(a[now].l+a[now].r)/2;
            if(pos<=mid){
                a[now].ls=add(a[now].ls,pos);
            }
            else{
                a[now].rs=add(a[now].rs,pos);
            }
            pushup(now);
            return now;
        }
        int sum(int now,int l,int r){
            if(l>r)return 0;
            if(a[now].l==l&&a[now].r==r)return a[now].v;
            int mid=(a[now].l+a[now].r)/2;
            if(r<=mid)return sum(a[now].ls,l,r);
            else if(l>mid)return sum(a[now].rs,l,r);
            else return sum(a[now].ls,l,mid)+sum(a[now].rs,mid+1,r);
        }
        int kth(int now,int pos){
            if(a[now].l==a[now].r)return a[now].l;
            if(pos<=a[a[now].ls].v)return kth(a[now].ls,pos);
            else return kth(a[now].rs,pos-a[a[now].ls].v);
        }
    }base;
}
using namespace seg;
namespace subtask1
{   
    int now,lastans,ver;
    int col[1001][1001];
    int ans;
    void dfs(int x,int fa,int len){
        if(col[now][x]==1){
            ans=min(ans,len);
        }
        for(int i=head[x];i;i=nxt[i]){
            if(to[i]==fa)continue;
            dfs(to[i],x,len+1);
        }
    }
    void solve(){
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int tp,x;
            scanf("%d%d",&tp,&x);
            x^=(lastans*type);
            if(tp==1){
                for(int j=1;j<=n;j++)col[ver+1][j]=col[now][j];
                now=++ver;
                col[now][x]=1-col[now][x];
            }
            else if(tp==2){
                ans=1e9;
                dfs(x,x,0);
                lastans=ans;
                printf("%d\n",ans);
            }
            else{
                now=x;
            }
        }
    }
} // namespace subtask1
namespace subtask2
{
    int roots[100001];
    int ver,maxver,lastans;
    void solve(){
        scanf("%d",&m);
        roots[0]=base.build(1,n);
        for(int i=1;i<=m;i++){
            int tp,x;
            scanf("%d%d",&tp,&x);
            x^=(lastans*type);
            if(tp==1){
                maxver++;
                roots[maxver]=base.tot+1;
                base.add(roots[ver],x);
                ver=maxver;
            }
            else if(tp==2){
                if(x==1){
                    if(base.query(roots[ver],1)){
                        lastans=0;
                    }
                    else if(base.a[roots[ver]].v){
                        lastans=1;
                    }
                    else{
                        lastans=1e9;
                    }
                }
                else{
                    if(base.query(roots[ver],x)){
                        lastans=0;
                    }
                    else if(base.query(roots[ver],1)){
                        lastans=1;
                    }
                    else if(base.a[roots[ver]].v){
                        lastans=2;
                    }
                    else{
                        lastans=1e9;
                    }
                }
                printf("%d\n",lastans);
            }
            else{
                ver=x;
            }
        }
    }
} // namespace subtask2
namespace subtask3
{
    int lastans,ver,maxver;
    int roots[100001];
    void solve(){
        roots[0]=base.build(1,n);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int tp,x;
            scanf("%d%d",&tp,&x);
            x^=(lastans*type);
            if(tp==1){
                maxver++;
                roots[maxver]=base.tot+1;
                base.add(roots[ver],x);
                ver=maxver;
            }
            else if(tp==2){
                if(base.query(roots[ver],x)){
                    lastans=0;
                }
                else{
                    int mi=1e9;
                    int pre_siz=base.sum(roots[ver],1,x-1);
                    if(pre_siz!=0){
                        int pos=base.kth(roots[ver],pre_siz);
                        //cout<<"pre>"<<pos<<endl;
                        mi=min(mi,x-pos);
                    }
                    if(pre_siz!=base.a[roots[ver]].v){
                        int pos=base.kth(roots[ver],pre_siz+1);
                        //cout<<"nxt>"<<pos<<endl;
                        mi=min(mi,pos-x);
                    }
                    lastans=mi;
                }
                printf("%d\n",lastans);
            }
            else{
                ver=x;
            }
        }
    }
} // namespace subtask3

int main(){
    //freopen("B.in","r",stdin);
    //freopen("B.ans","w",stdout);
    scanf("%d%d",&type,&n);
    bool flag1=1,flag2=1;
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a!=1&&b!=1)flag1=0;
        if(abs(a-b)!=1)flag2=0;
        add(a,b);
        add(b,a);
    }
    if(flag1){
        subtask2::solve();
        return 0;
    }
    else if(flag2){
        subtask3::solve();
    }
    else{
        subtask1::solve();
    }
    return 0;
}
/*
0 5
1 2
2 3
3 4
4 5
3
1 1
1 5
2 3
*/