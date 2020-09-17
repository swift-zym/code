#include<bits/stdc++.h>
using namespace std;
int n,k,dp[100001],sum[100001];
int main(){
  scanf("%d%d",&n,&k);
  dp[0]=sum[0]=1;
  for(int i=1;i<=n;i++){
    dp[i]=sum[max(0,i-k-1)];
    sum[i]=sum[i-1]+dp[i];
    sum[i]%=5000011;
  }
  printf("%d\n",sum[n]);
  return 0;
}
