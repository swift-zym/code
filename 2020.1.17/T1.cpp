#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int dp[301][301];
void solve(int n,int m){
  if(n==1&&m==1)dp[n][m]=1;
  if(dp[n][m])return;
  for(int i=2;i<=n;i++){
    solve(i-1,m);
    solve(n-i+1,m);
    dp[n][m]+=(dp[i-1][m]*dp[n-i+1][m])%MOD;
    dp[n][m]%=MOD;
    //printf("dp[%d][%d](%d)+=dp[%d][%d](%d)*dp[%d][%d](%d)\n",n,m,dp[n][m],i-1,m,dp[i-1][m],n-i+1,m,dp[n-i+1][m]);
  }
  for(int i=2;i<=m;i++){
    solve(n,i-1);
    solve(n,m-i+1);
    dp[n][m]+=(dp[n][i-1]*dp[n][m-i+1])%MOD;
    dp[n][m]%=MOD;
    //printf("dp[%d][%d](%d)+=dp[%d][%d](%d)*dp[%d][%d](%d)\n",n,m,dp[n][m],n,i-1,dp[n][i-1],n,m-i+1,dp[n][m-i+1]);
  }
}
signed main(){
  int n,m;
  scanf("%lld%lld",&n,&m);
  solve(n,m);
  printf("%lld\n",dp[n][m]);
  return 0;
}
