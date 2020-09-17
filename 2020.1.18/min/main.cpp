#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,B,C,D,a[200001][21],dp[200001];
int f(int x){
  return x*x*x*A+x*x*B+x*C+D;
}
signed main(){
  freopen("example_min3.in","r",stdin);
  freopen("example_min3.out","w",stdout);
  scanf("%lld%lld%lld%lld%lld",&n,&A,&B,&C,&D);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i][0]);
  for(int j=1;j<=20;j++)
  for(int i=1;i<=n;i++){
    a[i][j]=min(a[i][j-1],a[min(i+(1<<(j-1)),n)][j-1]);
  }
  for(int i=1;i<=n;i++){
    int k=log2(i);
    dp[i]=f(min(a[1][k],a[i-(1<<k)+1][k]));
    for(int j=1;j<i;j++){
      int k=log2(i-j);
      dp[i]=max(dp[i],dp[j]+f(min(a[j+1][k],a[i-(1<<k)+1][k])));
    }
  }
  printf("%lld\n",dp[n]);
  return 0;
}
