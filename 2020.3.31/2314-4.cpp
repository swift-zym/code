#include<bits/stdc++.h>
#define int long long
using namespace std;
int tmp[10001][32],dp[10001][32],n,c;
signed main(){
  scanf("%lld%lld",&n,&c);
  for(int j=1;j<=c;j++){
    int e,f,l,x=0,y=0;
    scanf("%lld%lld%lld",&e,&f,&l);
    for(int i=1;i<=f;i++){
      int id;
      scanf("%lld",&id);
      id=(id-e+n)%n;
      x|=(1<<id);
    }
    for(int i=1;i<=l;i++){
      int id;
      scanf("%lld",&id);
      id=(id-e+n)%n;
      y|=(1<<id);
    }
    for(int i=0;i<(1<<5);i++){
      if((i&x)||((~i)&y))tmp[e][i]++;
    }
  }
  int ans=0;
  for(int i=0;i<(1<<5);i++){
    for(int j=0;j<(1<<5);j++){
      dp[0][j]=-1e8;
    }
    dp[0][i]=0;
    for(int j=1;j<=n;j++){
      for(int k=0;k<(1<<5);k++){
        dp[j][k]=max(dp[j-1][(k&15)<<1],dp[j-1][((k&15)<<1)|1])+tmp[j][k];
      }
    }
    ans=max(ans,dp[n][i]);
  }
  printf("%lld\n",ans);
  return 0;
}
