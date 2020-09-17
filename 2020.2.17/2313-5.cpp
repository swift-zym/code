#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],dp[1000001];
struct node{
  int id,v;
};
deque<node>q;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  q.push_back({0,0});
  for(int i=1;i<=n;i++){
    while(q.empty()==0&&q.back().id<i-m)q.pop_back();
    dp[i]=a[i]+q.back().v;
    while(q.empty()==0&&q.front().v>dp[i])q.pop_front();
    q.push_front({i,dp[i]});
  }
  int mi=dp[n];
  for(int i=n-1;i>=n-m+1;i--){
    mi=min(mi,dp[i]);
  }
  printf("%d\n",mi);
  return 0;
}
