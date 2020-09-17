#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 2333
int C[3001][3001],sum[3001][3001];
int lucas(int m,int n){
  if(m<n)return 0;
  if(n==0)return 1;
  return C[m%MOD][n%MOD]*lucas(m/MOD,n/MOD)%MOD;
}
int solve(int n,int k){
  if(k<0)return 0;
  if(n==0||k==0)return 1;
  if(n<MOD&&k<MOD)return sum[n][k];
  return (solve(n/MOD,k/MOD-1)*sum[n%MOD][MOD-1]%MOD+lucas(n/MOD,k/MOD)*sum[n%MOD][k%MOD]%MOD)%MOD;
}
signed main(){
  C[0][0]=1;
  for(int i=1;i<=3000;i++)
  C[i][i]=C[i][0]=1;
  for(int i=1;i<=3000;i++)
  for(int j=1;j<i;j++)
  C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
  for(int i=0;i<=3000;i++)
  sum[i][0]=1;
  for(int i=0;i<=3000;i++)
  for(int j=1;j<=3000;j++)
  sum[i][j]=(C[i][j]+sum[i][j-1])%MOD;
  int T;
  scanf("%lld",&T);
  while(T--){
    int n,k;
    scanf("%lld%lld",&n,&k);
    printf("%lld\n",solve(n,k));
  }
}
