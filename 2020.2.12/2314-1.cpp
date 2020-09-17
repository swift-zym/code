#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
int tmp[13],m,n;
int dp[13][5000];
int main(){
  scanf("%d%d",&m,&n);
  for(int i=1;i<=m;i++){
    for(int j=0;j<n;j++){
      int a;
      scanf("%d",&a);
      if(a==0)
      tmp[i]|=(1<<j);
    }
  }
  dp[0][0]=1;
  for(int i=1;i<=m;i++){
    for(int j=0;j<(1<<n);j++){
      if((j&(j>>1))|(j&(j<<1)))continue;
      if(j&tmp[i-1])continue;
      for(int k=0;k<(1<<n);k++){
        if((k&(k>>1))|(k&(k<<1)))continue;
        if(k&tmp[i])continue;
        if(j&k)continue;
        dp[i][k]+=dp[i-1][j];
        dp[i][k]%=MOD;
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<n);i++){
    ans+=dp[m][i];
    ans%=MOD;
  }
  printf("%d\n",ans);
  return 0;
}
