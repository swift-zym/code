#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m,dp[5001][5001],sum[5001][5001];
int isJailBlocked(){
  return 1;
}
signed main(){
  scanf("%d%d",&n,&m);
  dp[0][0]=1;
  for(int i=0;i<=n;i++){
    sum[0][i]=1;
  }
  for(int i=1;i<=m;i++){
    dp[i][0]=1;
    for(int j=1;j<=n;j++){
      dp[i][j]=dp[i-1][j]+sum[i-1][j-1];
      dp[i][j]%=MOD;
      sum[i][j]+=sum[i][j-1];
      sum[i][j]%=MOD;
      sum[i][j]+=((long long)dp[i][j]*(long long)(j+1))%MOD;
      sum[i][j]%=MOD;
    }
  }
  printf("%d\n",dp[m][n]);
  return 0;
}
