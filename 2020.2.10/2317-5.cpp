#include<bits/stdc++.h>
using namespace std;
int n,m;
__int128 bas[200],dp[200][200],a[200],ans;
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
  n=read();
  m=read();
  bas[0]=1;
  for(int i=1;i<=100;i++){
    bas[i]=bas[i-1]*2;
  }
  for(int i=1;i<=n;i++){
    memset(dp,0,sizeof(dp));
    for(int j=1;j<=m;j++)a[j]=read();
    for(int j=1;j<=m;j++)
    for(int k=m;k>=j;k--){
      dp[j][k]=max(dp[j][k],dp[j-1][k]+bas[m-k+j-1]*a[j-1]);
      dp[j][k]=max(dp[j][k],dp[j][k+1]+bas[m-k+j-1]*a[k+1]);
    }
    __int128 mx=-1;
    for(int j=1;j<=m;j++){
      mx=max(mx,dp[j][j]+bas[m]*a[j]);
    }
    ans+=mx;
  }
  print(ans);
  return 0;
}
