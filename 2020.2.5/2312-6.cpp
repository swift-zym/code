#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,c,s[1000001],dp[1000001];
int q[1000001],l=1,r=0;
int K(int idx){
  return 2*a*s[idx];
}
int X(int idx){
  return s[idx];
}
int B(int idx){
  return dp[idx]-a*s[idx]*s[idx]-b*s[idx]-c;
}
int Y(int idx){
  return dp[idx]+a*s[idx]*s[idx]-b*s[idx];
}
double slope(int i,int j){
  return double(Y(i)-Y(j))/double(X(i)-X(j));
}
signed main(){
  scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
  for(int i=1;i<=n;i++){
    scanf("%lld",&s[i]);
    s[i]+=s[i-1];
  }
  q[++r]=0;
  for(int i=1;i<=n;i++){
    while(l<r&&slope(q[l],q[l+1])>K(i))l++;
    dp[i]=-(K(i)*X(q[l])-Y(q[l])-a*s[i]*s[i]-b*s[i]-c);
    while(l<r&&slope(q[r-1],q[r])<=slope(q[r],i))r--;
    q[++r]=i;
  }
  printf("%lld\n",dp[n]);
  return 0;
}
