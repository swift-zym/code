#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cf[2020][2020];
signed main(){
  freopen("T1.in","r",stdin);
  freopen("T1.ans","w",stdout);
  scanf("%lld%lld",&n,&m);
  for(int k=1;k<=m;k++){
    int r,c,l,s;
    scanf("%lld%lld%lld%lld",&r,&c,&l,&s);
    for(int i=r;i<=r+l-1;i++){
      for(int j=1;j<=i-r+1;j++){
        cf[i][c+j-1]+=s;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    ans^=cf[i][j];
  }
  }
  printf("%lld\n",ans);
  return 0;
}
