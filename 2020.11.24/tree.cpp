#include<iostream>
#include<vector>
#define int long long
#define MOD 1000000007
using namespace std;
int siz[300001],hs[300001],son[300001],dfn[300001];
vector<int>v[300001];
int top[300001];
int f[300001];
void dfs1(int now){
    siz[now]=1;
    for(auto to:v[now]){
        dfs1(to);
        siz[now]+=siz[to];
        if(siz[to]>siz[son[now]]){
            son[now]=to;
        }
    }
}
int T;
int n,m;
void dfs2(int now,int tp){
    dfn[now]=++T;
    top[now]=tp;
    if(son[now])dfs2(son[now],tp);
    for(auto to:v[now]){
        if(to!=son[now])dfs2(to,to);
    }
}
struct node{
    int tag,sum;
}a[1400000];
void pushup(int now){
    a[now].sum=(a[now*2].sum+a[now*2+1].sum)%MOD;
}
void pushdown(int now,int l,int r){
    int mid=(l+r)/2;
    a[now*2].sum+=a[now].tag*(mid-l+1)%MOD;
    a[now*2+1].sum+=a[now].tag*(r-mid)%MOD;
    a[now*2].tag+=a[now].tag;
    a[now*2+1].tag+=a[now].tag;
    a[now].tag=0;
    a[now*2].sum%=MOD;a[now*2+1].sum%=MOD;
    a[now*2].tag%=MOD;a[now*2+1].tag%=MOD;
}
void add(int now,int l,int r,int L,int R,int v){
    if(l==L&&r==R){
        a[now].sum+=(r-l+1)*v;
        a[now].tag+=v;
        return;
    }
    pushdown(now,l,r);
    int mid=(l+r)/2;
    if(R<=mid)add(now*2,l,mid,L,R,v);
    else if(L>mid)add(now*2+1,mid+1,r,L,R,v);
    else{
        add(now*2,l,mid,L,mid,v);
        add(now*2+1,mid+1,r,mid+1,R,v);
    }
    pushup(now);
}
int query(int now,int l,int r,int L,int R){
    if(l==L&&r==R)return a[now].sum;
    pushdown(now,l,r);
    int mid=(l+r)/2;
    if(R<=mid)return query(now*2,l,mid,L,R);
    else if(L>mid)return query(now*2+1,mid+1,r,L,R);
    else return(query(now*2,l,mid,L,mid)+query(now*2+1,mid+1,r,mid+1,R))%MOD;
}
signed main(){
    scanf("%lld",&n);
    for(int i=2;i<=n;i++){
        scanf("%lld",&f[i]);
        v[f[i]].push_back(i);
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int opt;
        scanf("%lld",&opt);
        if(opt==1){
            int v,x,k;
            scanf("%lld%lld%lld",&v,&x,&k);
            add(1,1,n,dfn[v],dfn[v]+siz[v]-1,-k);
            add(1,1,n,dfn[v],dfn[v],x+k);
        }
        else{
            int v;
            scanf("%lld",&v);
            int ans=0;
            while(top[v]!=1){
                ans+=query(1,1,n,dfn[top[v]],dfn[v]);ans%=MOD;
                v=f[top[v]];
            }
            ans+=query(1,1,n,dfn[1],dfn[v]);ans%=MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}