#include<bits/stdc++.h>
#define int long long
int dp[11][2000][101];
bool check(int a,int b){
  if((a&(a>>1))!=0)return 0;
  if((a&(a<<1))!=0)return 0;
  if((b&(b>>1))!=0)return 0;
  if((b&(b<<1))!=0)return 0;
  if((a&b)!=0)return 0;
  if((a&(b>>1))!=0)return 0;
  if((a&(b<<1))!=0)return 0;
  if((b&(a>>1))!=0)return 0;
  if((b&(a<<1))!=0)return 0;
  return 1;
}
int solve(int a){
  int ans=0;
  while(a){
    ans++;
    a-=(a&-a);
  }
  return ans;
}
signed main(){
  dp[0][0][0]=1;
  int n,K;
  scanf("%lld%lld",&n,&K);
  if(K>=n*n){
    puts("0");
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<(1<<n);j++){
      for(int k=solve(j);k<=K;k++){
        for(int ii=0;ii<(1<<n);ii++){
          if(check(ii,j)){
            dp[i][j][k]+=dp[i-1][ii][k-solve(j)];
          }
        }
      }
    }
  }
  //10*1024*100*1024
  int ans=0;
  for(int j=0;j<(1<<n);j++){
    ans+=dp[n][j][K];
  }
  printf("%lld\n",ans);
  return 0;
}
