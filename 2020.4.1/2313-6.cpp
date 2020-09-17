#include<bits/stdc++.h>
using namespace std;
int n,t,a[50001];
struct node{
  int id,v;
};
bool check(int m){
  int dp[50001],l=1,r=1;
  node q[50001];
  memset(dp,0,sizeof(dp));
  memset(q,0,sizeof(q));
  q[r]={0,0};
  for(int i=1;i<=n+1;i++){
    dp[i]=q[l].v+a[i];
    while(l<r&&q[r].v>dp[i])r--;
    q[++r]={i,dp[i]};
    while(l<r&&q[l].id<i-m)l++;
  }
  return dp[n+1]<=t;
}
int main(){
  scanf("%d%d",&n,&t);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  int l=0,r=n,ans;
  while(l<=r){
    int mid=(l+r)/2;
    if(check(mid)){
      ans=mid;
      r=mid-1;
    }
    else{
      l=mid+1;
    }
  }
  printf("%d\n",ans);
  return 0;
}
