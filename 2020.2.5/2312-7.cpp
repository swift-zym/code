#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],sum[500001],tmp[500001],dp[500001];
signed main(){
  while(scanf("%lld%lld",&n,&m)!=EOF){
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
    memset(dp,0,sizeof(dp));
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=n;i++){
      dp[i]=1e18;
      for(int j=tmp[i-1];j<=i;j++){
        if(dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m<=dp[i]){
          dp[i]=dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
          tmp[i]=j;
        }
      }
    }
    printf("%lld\n",dp[n]);
  }
  return 0;
}
