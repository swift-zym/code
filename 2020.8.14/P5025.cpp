#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
LL x[510000],r[510000];
struct node{
    int l,r;
}a[4100000];
int id[4100000];
vector<int>v[4100000];
int mx;
int ll[4100000],rr[4100000];
int le[4100000],ri[4100000];
void build(int now,int l,int r){
    ll[now]=l;rr[now]=r;
    a[now].l=l;
    a[now].r=r;
    mx=max(mx,now);
    if(l==r){
        id[l]=now;
        return;
    }
    int mid=(l+r)/2;
    v[now].push_back(now*2);
    v[now].push_back(now*2+1);
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
}
void add(int now,int l,int r,int st){
    int L=a[now].l,R=a[now].r;
    //cout<<now<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(L==l&&R==r){
        if(l==r&&st==now)return;
        v[st].push_back(now);
        return;
    }
    int mid=(L+R)/2;
    if(r<=mid){
        add(now*2,l,r,st);
    }
    else if(l>mid){
        add(now*2+1,l,r,st);
    }
    else{
        add(now*2,l,mid,st);
        add(now*2+1,mid+1,r,st);
    }
}
int dfn[2100000],low[2100000];
int T;
int vis[2100000];
stack<int>s;
int num;
int bel[2100000];
void tarjan(int now){
    low[now]=dfn[now]=++T;
    s.push(now);
    vis[now]=1;
    for(int i=0;i<v[now].size();i++){
        if(!dfn[v[now][i]]){
            tarjan(v[now][i]);
            low[now]=min(low[now],low[v[now][i]]);
        }
        else if(vis[v[now][i]]){
            low[now]=min(low[now],dfn[v[now][i]]);
        }
    }
    if(low[now]==dfn[now]){
        num++;
        int tp;
        le[num]=1e9+1;
        do{
           tp=s.top();
           s.pop();
           vis[tp]=0;
           bel[tp]=num;
           le[num]=min(le[num],ll[tp]);
           ri[num]=max(ri[num],rr[tp]);
        }while(tp!=now);
    }
}
vector<int>vv[2100000];
void dfs(int now){
    vis[now]=1;
    for(int i=0;i<vv[now].size();i++){
        le[now]=min(le[now],le[vv[now][i]]);
        ri[now]=max(ri[now],ri[vv[now][i]]);
        if(vis[vv[now][i]])continue;
        dfs(vv[now][i]);
    }
}
signed main(){
    scanf("%d",&n);
    build(1,1,n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&r[i]);
    }
    x[n+1]=1e18+1;
    for(int i=1;i<=n;i++){
        if(!r[i])continue;
        int L=lower_bound(x+1,x+n+1,x[i]-r[i])-x;
        int R=upper_bound(x+1,x+n+1,x[i]+r[i])-x-1;
        ll[id[i]]=L;rr[id[i]]=R;
        add(1,L,R,id[i]);
    }
    tarjan(1);
    for(int i=1;i<=mx;i++)
    for(int j=0;j<v[i].size();j++){
        int x=bel[i],y=bel[v[i][j]];
        if(x!=y){
            vv[x].push_back(y);
        }
    }
    for(int i=1;i<=num;i++){
        sort(vv[i].begin(),vv[i].end());
        unique(vv[i].begin(),vv[i].end());
    }
    for(int i=1;i<=num;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=(LL)i*(ri[bel[id[i]]]-le[bel[id[i]]]+1);
        ans%=1000000007;
    }
    printf("%lld\n",ans);
    return 0;
}
