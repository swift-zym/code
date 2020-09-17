#include<bits/stdc++.h>
#define int long long
int n,m,p,d[100001],a[100001],s[100001],dp[101][100001],tmp[100001];
int q[100001],l,r;
using namespace std;
signed main(){
  scanf("%lld%lld%lld",&n,&m,&p);
  for(int i=2;i<=n;i++){
    scanf("%lld",&d[i]);
    d[i]+=d[i-1];
  }
  for(int i=1;i<=m;i++){
    int x,y;
    scanf("%lld%lld",&x,&y);
    a[i]=y-d[x];
  }
  sort(a+1,a+m+1);
  for(int i=1;i<=m;i++)
  s[i]=s[i-1]+a[i];
  memset(dp,0x3f,sizeof(dp));
  dp[0][0]=0;
  for(int i=1;i<=p;i++){
    l=r=1;q[1]=0;
    for(int j=1;j<=m;j++)tmp[j]=dp[i-1][j]+s[j];
    for(int j=1;j<=m;j++){
      while(l<r&&tmp[q[l+1]]-tmp[q[l]]<=a[j]*(q[l+1]-q[l]))l++;
      dp[i][j]=min(dp[i-1][j],tmp[q[l]]+a[j]*(j-q[l])-s[j]);
      if(tmp[j]>=0x3f3f3f3f3f3f3f3fll)continue;
      while(l<r&&(tmp[j]-tmp[q[r]])*(q[r]-q[r-1])<=(tmp[q[r]]-tmp[q[r-1]])*(j-q[r]))r--;
      q[++r]=j;
    }
  }
  printf("%lld\n",dp[p][m]);
  return 0;
}
