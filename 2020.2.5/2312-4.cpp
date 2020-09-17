#include<bits/stdc++.h>
using namespace std;
int n,L,l=1,r=0,q[50001];
double s[50001],dp[50001];
double a(int idx){
  return s[idx]+idx;
}
double b(int idx){
  return a(idx)+L+1;
}
double X(int idx){
  return b(idx);
}
double Y(int idx){
  return dp[idx]+b(idx)*b(idx);
}
double slope(int i,int j){
  return (Y(i)-Y(j))/(X(i)-X(j));
}
int main(){
  scanf("%d%d",&n,&L);
  for(int i=1;i<=n;i++){
    scanf("%lf",&s[i]);
    s[i]+=s[i-1];
  }
  q[++r]=0;
  for(int i=1;i<=n;i++){
    while(l<r&&slope(q[l],q[l+1])<2*a(i))l++;
    dp[i]=dp[q[l]]+(a(i)-b(q[l]))*(a(i)-b(q[l]));
    while(l<r&&slope(i,q[r-1])<slope(q[r-1],q[r]))r--;
    q[++r]=i;
  }
  printf("%0.0lf\n",dp[n]);
  return 0;
}
