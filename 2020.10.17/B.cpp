#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,m;
int w[100001];
vector<int>v[100001];
int sum[100001],ans;
void dfs(int now,int fa){
    sum[now]=w[now];
    int mx=-1,mxx=-1;
    for(auto i:v[now]){
        if(i==fa)continue;
        dfs(i,now);
        if(sum[i]>=mx){
            mxx=mx;
            mx=sum[i];
        }
        else if(sum[i]>mxx){
            mxx=sum[i];
        }
        sum[now]+=sum[i];
    }
    if(mx!=-1&&mxx!=-1){
        ans=max(ans,mxx+mx);
    }
}
signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%lld%lld",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ans=-1;
        for(int i=1;i<=n;i++){
            dfs(i,i);   
        }
        if(ans==-1){
            puts("Impossible");
        }
        else{
            printf("%lld\n",ans);
        }
    }
    return 0;
}