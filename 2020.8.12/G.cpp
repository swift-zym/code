#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[1001][31][2],a[1001];
int ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)a[i]--;
    dp[0][0][1]=-1e8;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=k;j++){
        dp[i][j][0]=dp[i-1][j][0]+(a[i]==0);
        dp[i][j][1]=dp[i-1][j][1]+(a[i]==1);
        ans=max(ans,dp[i][j][0]);
        ans=max(ans,dp[i][j][1]);
        if(j==0)continue;
        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][1]+(a[i]==0));
        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][0]+(a[i]==1));
        ans=max(ans,dp[i][j][0]);
        ans=max(ans,dp[i][j][1]);
    }
    printf("%d\n",ans);
    return 0;
}