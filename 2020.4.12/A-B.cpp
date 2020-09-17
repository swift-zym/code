
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
  int p,t,idx;
}a[200001];
int l[200010],r[200010],q[200010],ll=0,rr=1,dp[200010];
bool byp(node a,node b){
  return a.p<b.p;
}
bool byt(node a,node b){
  return a.t<b.t;
}
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld",&a[i].p,&a[i].t);
  }
  sort(a+1,a+n+1,byt);
  for(int i=1;i<=n;i++)a[i].idx=i;
  sort(a+1,a+n+1,byp);
  int mx=-1,mi=1e8;
  for(int i=1;i<=n;i++){
    mx=max(a[i].idx,mx);
    r[i]=mx;
  }
  for(int i=n;i>=1;i--){
    mi=min(a[i].idx,mi);
    l[i]=mi;
  }
  l[0]=1;r[0]=0;dp[0]=1;
  l[n+1]=r[n+1]=n+1;
  int s=1;
  for(int i=1;i<=n+1;i++){
    while(ll<rr&&r[q[ll]]+1<l[i]){
      s-=dp[q[ll]];
      s+=66662333;
      s%=66662333;
      ll++;
    }
    dp[i]=s;
    s*=2;
    s%=66662333;
    q[rr++]=i;
  }
  printf("%lld\n",dp[n+1]);
  return 0;
}
