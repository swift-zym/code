#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cf[2020][2020][2];
signed main(){
  freopen("T1.in","r",stdin);
  freopen("T1.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=m;i++){
    int r,c,l,s;
    scanf("%lld%lld%lld%lld",&r,&c,&l,&s);
    cf[r][c][0]+=s;
    cf[r+l][c+l][0]-=s;
    cf[r+l][c][1]-=s;
    cf[r+l][c+l][1]+=s;
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    cf[i][j][0]+=cf[i-1][j-1][0];
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    cf[i][j][1]+=cf[i][j-1][1];
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    cf[i][j][1]+=cf[i][j][0];
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    cf[i][j][1]+=cf[i-1][j][1];
  }
  /*for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%d ",cf[i][j][1]);
    }
    putchar(10);
  }*/
  int ans=0;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    ans^=cf[i][j][1];
  }
  printf("%lld\n",ans);
  return 0;
}
