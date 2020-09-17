#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define MAXN 666666
using namespace std;
double dp[2][MAXN+5],sum[MAXN+5][25],sum1[MAXN+5][25],sum2[MAXN+5][25];
int now,n,m,a[400],on[25];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=n+1;i<=n+6;i++)a[i]=n;
  for(int i=1;i<=m;i++)scanf("%d",&on[i]);
  if(m==1){
    puts("1.000000");
    return 0;
  }
  dp[0][n]=1;
  for(int i=1;i<=MAXN;i++){
    now^=1;
    for(int j=1;j<=n;j++)dp[now][j]=0;
    for(int j=1;j<n;j++){
      for(int k=1;k<=6;k++){
        dp[now][j]+=dp[now^1][a[j+k]]*double(1)/double(6);
      }
    }
    for(int j=1;j<=m;j++)sum[i][j]=dp[now][on[j]];
  }
  for(int i=MAXN;i>=1;i--){
    for(int j=1;j<=m;j++){
      sum[i][j]+=sum[i+1][j];
    }
  }
  for(int i=1;i<=MAXN;i++){
    sum1[i][0]=sum2[i][m+1]=1;
    for(int j=1;j<=m;j++)sum1[i][j]=sum1[i][j-1]*sum[i][j];
    for(int j=m;j>=1;j--)sum2[i][j]=sum2[i][j+1]*sum[i][j];
  }
  for(int i=1;i<=m;i++){
    double ans=0;
    for(int j=1;j<=MAXN;j++){
      ans+=sum1[j+1][i-1]*sum2[j][i+1]*(sum[j][i]-sum[j+1][i]);
    }
    printf("%lf\n",ans);
  }
  return 0;
}
