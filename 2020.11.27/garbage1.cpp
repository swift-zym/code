#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
vector<int>v[100001];
int n,r,a[100001],f[100001][21],dep[100001];
void dfs(int now,int fa,int deep){
    f[now][0]=fa;dep[now]=deep;
    for(int i=1;i<=20;i++){
        f[now][i]=f[f[now][i-1]][i-1];
    }
    for(auto to:v[now]){
        if(to==fa)continue;
        dfs(to,now,deep+1);
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int i=20;i>=0;i--){
        if(dep[f[a][i]]>=dep[b]){
            a=f[a][i];
        }
    }
    if(a==b)return a;
    for(int i=20;i>=0;i--){
        if(f[a][i]!=f[b][i]){
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
int fin[100001],ans,vis[100001];
void solve(int now,int tim,int id){
    vis[now]=1;
    tim=max(tim,fin[now]+1);
    //cout<<now<<" "<<tim<<" "<<fin[now]<<" "<<id<<endl;
    if(id==now){
        fin[now]=tim+a[now];
        ans=max(ans,fin[now]);
        //cout<<id<<"finish at time%"<<fin[now]<<endl;
        return;
    }
    for(auto to:v[now]){
        //cout<<now<<">"<<to<<" "<<lca(to,id)<<endl;
        if(lca(to,id)==to&&!vis[to]){
            fin[now]=max(tim,fin[to]);
            solve(to,tim+1,id);
            break;
        }
    }
}
signed main(){
    freopen("garbage.in","r",stdin);
    freopen("garbage.out","w",stdout);
    scanf("%lld%lld",&n,&r);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);v[b].push_back(a);
    }
    dfs(r,r,1);
    for(int i=1;i<=n;i++){
        //cout<<"%"<<i<<endl;
        memset(vis,0,sizeof(vis));
        solve(r,1,i);
    }
    printf("%lld\n",ans);
    return 0;
}