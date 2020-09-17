#include<bits/stdc++.h>
#define int long long
using namespace std;
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

int n;
__int128 a[201],dp[201][201],ans;
inline __int128 read()
{
   int X=0,w=0; char ch=0;
   while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
   while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
   return w?-X:X;
}
inline void print(__int128 x)
{
   if(x<0){putchar('-');x=-x;}
   if(x>9) print(x/10);
   putchar(x%10+'0');
}
signed main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    a[i]=read();
    a[i+n]=a[i];
  }
  for(int i=1;i<=2*n;i++)
  for(int j=i;j<=2*n;j++){
    dp[i][j]=-1;
  }
  for(int i=1;i<n*2;i++){
    dp[i][i+1]=0;
  }
  for(int l=3;l<=n;l++){
    for(int i=1;i<=n*2-l+1;i++)
    for(int j=i+1;j<i+l-1;j++){
      if(dp[i][i+l-1]==-1)dp[i][i+l-1]=dp[i][j]+dp[j][i+l-1]+a[i]*a[j]*a[i+l-1];
      else dp[i][i+l-1]=min(dp[i][i+l-1],dp[i][j]+dp[j][i+l-1]+a[i]*a[j]*a[i+l-1]);
    }
  }
  ans=dp[1][n];
  for(int i=1;i<=n;i++){
    ans=min(ans,dp[i][i+n-1]);
  }
  print(ans);
  return 0;
}
