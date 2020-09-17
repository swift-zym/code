#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,dp[301][301],tmp[301][301],a[301];
int q[301][2];
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=2;i<=n;i++)
  for(int j=1;j<=n-i+1;j++){
    int r=j+i-1;
    for(int k=j;k<r;k++){
      //cout<<i<<" "<<j<<" "<<k<<endl;
      int v=dp[j][k]+dp[k+1][r]+(a[j]+a[r])*a[k];
      if(dp[j][k]+dp[k+1][r]+(a[j]+a[r])*a[k]>dp[j][r]){
        dp[j][r]=v;
        tmp[j][j+i-1]=k;
        //cout<<dp[j][k]+dp[j+1][j+i-1]+(a[j]*a[j+i-1])*a[k]<<endl;
      }
    }
  }
  printf("%lld\n",dp[1][n]);
  int l=1,r=1;
  q[1][0]=1;q[1][1]=n;
  int num=0;
  while(l<=r){
    int now=tmp[q[l][0]][q[l][1]];
    if(num!=0){
      putchar(' ');
    }
    num++;
    printf("%lld",now);
    if(q[l][0]!=now){
      r++;
      q[r][0]=q[l][0];
      q[r][1]=now;
    }
    if(q[l][1]!=now+1){
      r++;
      q[r][0]=now+1;
      q[r][1]=q[l][1];
    }
    l++;
  }
  putchar(10);
  return 0;
}
