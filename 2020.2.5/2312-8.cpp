#include<bits/stdc++.h>
using namespace std;
int n,w[20001],c[20001],s[20001],sum,ans=2e9+1;
int q[20001],l=1,r=0;
double slope(int i,int j){
  return double(c[i]*s[i]-c[j]*s[j])/(s[i]-s[j]);
}
int solve(int i,int j){
  return sum-c[j]*s[j]-c[i]*(s[i]-s[j]);
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&w[i],&c[i]);
  }
  for(int i=n;i>=1;i--){
    c[i]+=c[i+1];
  }
  for(int i=1;i<=n;i++){
  s[i]=s[i-1]+w[i],sum+=c[i]*w[i];
  }
  q[++r]=0;
  for(int i=1;i<=n;i++){
    while(l<r&&slope(q[l],q[l+1])>c[i])l++;
    ans=min(ans,solve(i,q[l]));
    while(l<r&&slope(q[r-1],q[r])<slope(q[r],i))r--;
    q[++r]=i;
  }
  printf("%d\n",ans);
  return 0;
}
