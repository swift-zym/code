#include<bits/stdc++.h>
#define MOD 100003
using namespace std;
int a,b,c,d,K,h[2001],dp[2001][2001];
int main(){
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&K);
  for(int i=1;i<=c;i++)h[i]=d,dp[i][0]=1;
  for(int i=c+1;i<=c+a;i++)h[i]=d+b,dp[i][0]=1;
  dp[0][0]=1;
  for(int i=1;i<=a+c;i++)
  for(int j=1;j<=K;j++){
    dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(h[i]-j+1);
    dp[i][j]%=MOD;
  }
  printf("%d\n",dp[a+c][K]);
  return 0;
}
