#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
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
#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n,k;
int dp[1000][1000];
int a[1000],b[1000];
signed main(){
    freopen("clash.in","r",stdin);
    freopen("clash.out","w",stdout);
    memset(dp,0xef,sizeof(dp));
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
    }
    for(int i=1;i<n;i++){
        if(a[i]+a[i+1]<=k){
            dp[i][i+1]=b[i]+b[i+1];
        }
    }
    for(int len=4;len<=n;len++)
    for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        if(a[i]+a[j]<=k){
            dp[i][j]=dp[i+1][j-1]+b[i]+b[j];
        }
    }
    for(int len=4;len<=n;len++)
    for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        dp[i][j]=max(dp[i][j],dp[i+1][j]);
        dp[i][j]=max(dp[i][j],dp[i][j-1]);
        for(int k=i;k<j;k++){
            dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        ans=max(ans,dp[i][j]);
    }
    printf("%lld\n",ans);
    return 0;
}