#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s,t[300001],c[300001],st[300001],sc[300001],dp[300001];
int q[300001],l=1,r=0;
int Y(int idx){
  return dp[idx];
}
int X(int idx){
  return sc[idx];
}
int K(int idx){
  return s+st[idx];
}
bool check(int x,int S){
  return Y(q[x+1])-Y(q[x])>S*(X(q[x+1])-X(q[x]));
}
int solve(int L,int R,int S){
  int ans=r;
  while(L<=R){
    int mid=(L+R)/2;
    if(check(mid,S)){
      R=mid-1;
      ans=mid;
    }
    else{
      L=mid+1;
    }
  }
  return q[ans];
}
signed main(){
  scanf("%lld",&n);
  scanf("%lld",&s);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld",&t[i],&c[i]);
    st[i]=st[i-1]+t[i];
    sc[i]=sc[i-1]+c[i];
  }
  q[++r]=0;
  for(int i=1;i<=n;i++){
    int j=solve(l,r,K(i));
    dp[i]=dp[j]+s*(sc[n]-sc[j])+st[i]*(sc[i]-sc[j]);
    while(l<r&&(Y(q[r])-Y(q[r-1]))*(X(i)-X(q[r]))>=(Y(i)-Y(q[r]))*(X(q[r])-X(q[r-1])))r--;
    q[++r]=i;
  }
  printf("%lld\n",dp[n]);
  return 0;
}
