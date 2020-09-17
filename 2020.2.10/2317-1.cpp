#include<bits/stdc++.h>
using namespace std;
int n,a[201],dp[201][201],ans=-1;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    a[i+n]=a[i];
  }
  for(int i=2;i<2*n;i++)
    for(int j=i-1;i-j<n&&j>=1;j--){
      for(int k=j;k<i;k++){
        dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+a[j]*a[k+1]*a[i+1]);
        ans=max(ans,dp[j][i]);
      }
    }
  printf("%d\n",ans);
  return 0;
}
