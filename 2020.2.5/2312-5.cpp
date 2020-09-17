#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x[1000001],p[1000001],c[1000001],dp[1000001],sum[1000001],summ[1000001];
int l=1,r=0,q[1000001];
inline double Y(int idx){
  return dp[idx]+sum[idx];
}
inline double X(int idx){
  return summ[idx];
}
inline double slope(int i,int j){
  return (Y(i)-Y(j))/(X(i)-X(j));
}
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld%lld",&x[i],&p[i],&c[i]);
    summ[i]=summ[i-1]+p[i];
    sum[i]=sum[i-1]+x[i]*p[i];
  }
  q[++r]=0;
  for(int i=1;i<=n;i++){
    while(l<r&&slope(q[l+1],q[l])<x[i])l++;
    dp[i]=dp[q[l]]+x[i]*(summ[i]-summ[q[l]])-sum[i]+sum[q[l]]+c[i];
    while(l<r&&slope(q[r],q[r-1])>slope(i,q[r]))r--;
    q[++r]=i;
  }
  printf("%lld\n",dp[n]);
  return 0;
}
