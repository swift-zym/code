#include<bits/stdc++.h>
using namespace std;
int n,b[40000],c[40000],tb[40000],tc[40000],cnt,k,dp[4000001];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&tb[i]);
  for(int i=1;i<=n;i++)scanf("%d",&tc[i]);
  for(int i=1;i<=n;i++){
    int bas=1;
    while(tc[i]>=bas){
      tc[i]-=bas;
      c[++cnt]=bas;
      b[cnt]=c[cnt]*tb[i];
      bas*=2;
    }
    if(tc[i]){
      c[++cnt]=tc[i];
      b[cnt]=c[cnt]*tb[i];
    }
  }
  memset(dp,0x3f,sizeof(dp));
  dp[0]=0;
  scanf("%d",&k);
  for(int i=1;i<=cnt;i++)
  for(int j=k;j>=b[i];j--){
    dp[j]=min(dp[j-b[i]]+c[i],dp[j]);
  }
  printf("%d\n",dp[k]);
  return 0;
}
