#include<bits/stdc++.h>
using namespace std;
struct node{
  int id,v;
};
deque<node>q;
int n,m,a[200001],sum,ans=-1e8;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  q.push_back({0,sum});
  for(int i=1;i<=n;i++){
    sum+=a[i];
    while(q.empty()==0&&q.back().id<i-m)q.pop_back();
    ans=max(ans,sum-q.back().v);
    while(q.empty()==0&&q.front().v>sum)q.pop_front();
    q.push_front({i,sum});
  }
  printf("%d\n",ans);
  return 0;
}
