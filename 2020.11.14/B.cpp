#include<bits/stdc++.h>
#define int long long
#define MOD 19260817
using namespace std;
int n,k,a[4000],sum;
vector<int>v[4000];
int dfs(int now,int fa,int mi,int mx,bool __isfirst=true){
    if(__isfirst)sum=0;
    int tmp=1;
    for(auto to:v[now]){
        if(to==fa)continue;
        tmp*=(dfs(to,now,mi,mx,false)+1);
        tmp%=MOD;
    }
    if(a[now]<mi||a[now]>mx){
        if(__isfirst){
            return sum;
        }
        return 0;
    }
    sum+=tmp;
    sum%=MOD;
    if(__isfirst){
        return sum;
    }
    return tmp;
}
int ans;
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<=n-k;i++){
        int j=i+k;
        int a1=dfs(1,1,i,j,true),a2=dfs(1,1,i+1,j,true),a3=dfs(1,1,i,j-1,true),a4=dfs(1,1,i+1,j-1,true);
        ans+=(a1-a2-a3+a4+MOD)%MOD;
        ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}