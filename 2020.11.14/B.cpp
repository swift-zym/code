#include<bits/stdc++.h>
#define int long long
#define MOD 19260817
using namespace std;
int n,k;
vector<int>v[4000];
int a[4000],vis[4000],tmp[4000];
int dfs1(int now,int mi,int mx){
    vis[now]=1;
    tmp[now]=1;
    for(auto to:v[now]){
        if(!vis[to]){
            tmp[now]*=(dfs1(to,type,v)+1);
            tmp[now]%=MOD;
        }
    }
    vis[now]=0;
    if(a[now]>mx||a[now]<mi){
        return tmp[now]=0;
    }
    return tmp[now];
}
int qpow(int a,int b){
    if(!b)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int sum;
void dfs2(int now,int ans){
    if(now==pos){
        ans*=tmp[now];
        ans%=MOD;
        sum+=ans;
        sum%=MOD;
        return;
    }
    vis[now]=1;
    for(auto to:v[now]){
        if(!tmp[to])continue;
        dfs2(to,ans*tmp[now]%MOD*pow(tmp[to]+1,MOD-2)%MOD);
    }
    vis[now]=0;
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        dfs1(i,a[now],a[now]+k);
    }
    return 0;
}