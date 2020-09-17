#include<iostream>
using namespace std;
int T,n,k,l,a[101],p[201];
bool check(int t,int x){
  return a[x]+p[t%(2*k)]<=l;
}
int dp[20000][101];
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=0;i<=k;i++)p[i]=i;
    for(int i=k+1;i<2*k;i++)p[i]=k-i+k;
    bool flag=0;
    for(int i=1;i<=n*(k+5);i++){
      dp[i][1]=check(i,1);
      if(n==1&&dp[i][1]==1){
        flag=1;
        break;
      }
    }
    for(int i=1;i<=n*(k+5);i++)
    for(int j=2;j<=n;j++){
      dp[i][j]=check(i,j)&(dp[i-1][j-1]|dp[i-1][j]);
      if(j==n&&dp[i][j]==1){
        flag=1;
        break;
      }
    }
    if(flag){
      puts("Yes");
    }
    else{
      puts("No");
    }
  }
  return 0;
}
/*
1
50
0
*/
