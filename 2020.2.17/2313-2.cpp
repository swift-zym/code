#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,e[100001],sum[100001],dp[100001][2];
struct node{
  int id,v;
};
deque<node>q;
signed main(){
  scanf("%lld%lld",&n,&k);
  for(int i=1;i<=n;i++){
    scanf("%lld",&e[i]);
    sum[i]=sum[i-1]+e[i];
  }
  q.push_back({0,0});
  for(int i=1;i<=n;i++){
    while(q.empty()==0&&q.back().id<i-k)q.pop_back();
    dp[i][1]=sum[i]+q.back().v;
    dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    int tmp=dp[i][0]-sum[i];
    while(q.empty()==0&&q.front().v<tmp)q.pop_front();
    q.push_front({i,tmp});
  }
  printf("%lld\n",max(dp[n][0],dp[n][1]));
  return 0;
}
