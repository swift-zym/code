#include<bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int T,MaxP,W;
int main(){
  scanf("%d%d%d",&T,&MaxP,&W);
  memset(dp,128,sizeof(dp));
  for(int i=1;i<=T;i++){
    int AP,BP,AS,BS;
    int q[2001];
    memset(q,0,sizeof(q));
    int l,r;
    scanf("%d%d%d%d",&AP,&BP,&AS,&BS);
    for(int j=0;j<=AS;j++){
      dp[i][j]=-j*AP;
    }
    for(int j=0;j<=MaxP;j++){
      dp[i][j]=max(dp[i][j],dp[i-1][j]);
    }
    if(i>W){
      l=1;r=0;
      for(int j=0;j<=MaxP;j++){
        while(l<=r&&q[l]<j-AS)l++;
        if(l<=r){
          dp[i][j]=max(dp[i][j],dp[i-W-1][q[l]]+q[l]*AP-j*AP);
        }
        while(l<=r&&dp[i-W-1][q[r]]+q[r]*AP<=dp[i-W-1][j]+j*AP)r--;
        q[++r]=j;
      }
      l=1;r=0;
      for(int j=MaxP;j>=0;j--){
        while(l<=r&&q[l]>j+BS)l++;
        if(l<=r){
          dp[i][j]=max(dp[i][j],dp[i-W-1][q[l]]+q[l]*BP-j*BP);
        }
        while(l<=r&&dp[i-W-1][q[r]]+q[r]*BP<=dp[i-W-1][j]+j*BP)r--;
        q[++r]=j;
      }
    }
  }
  printf("%d\n",dp[T][0]);
  return 0;
}
