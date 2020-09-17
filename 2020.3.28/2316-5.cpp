#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,v[30],dp[30][30],tmp[30][30];
int solve(int l,int r){
  if(l>r)return 1;
  if(l==r){tmp[l][r]=l;return dp[l][r]=v[l];}
  if(dp[l][r]!=-1)return dp[l][r];
  for(int i=l;i<=r;i++){
    if(solve(l,i-1)*solve(i+1,r)+v[i]>dp[l][r]){
      dp[l][r]=solve(l,i-1)*solve(i+1,r)+v[i];
      tmp[l][r]=i;
    }
  }
  return dp[l][r];
}
vector<int>vv;
void print(int l,int r)#{
  if(l>r)return;
  vv.push_back(tmp[l][r]);
  print(l,tmp[l][r]-1);
  print(tmp[l][r]+1,r);
}
signed main(){
  scanf("%lld",&n);
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++){
    scanf("%lld",&v[i]);
  }
  printf("%lld\n",solve(1,n));
  print(1,n);
  for(int i=0;i<vv.size();i++){
    if(i)putchar(' ');
    printf("%lld",vv[i]);
  }
  putchar(10);
  return 0;
}
