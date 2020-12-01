#pragma GCC optimize("Ofast")
#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int n,m,x[301],dp[301][301][2];
int solve(int mx){
    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i][i][0]=dp[i][i][1]=abs(x[i])*mx;
        if(mx==1)
        ans=max(ans,m-min(dp[i][i][0],dp[i][i][1]));
    }
    for(int len=2;len<=n;len++)
    for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        dp[i][j][0]=min(dp[i+1][j][0]+(x[i+1]-x[i])*(mx-len+1),\
                    min(dp[i+1][j][1]+(x[j]-x[i])*(mx-len+1),\
                    min(dp[i][j-1][0]+(x[j]-x[i])*(mx-len+1)+(x[j]-x[i])*(mx-len),\
                    dp[i][j-1][1]+(x[j]-x[j-1])*(mx-len+1)+(x[j]-x[i])*(mx-len)\
                    )));
        dp[i][j][1]=min(dp[i][j-1][1]+(x[j]-x[j-1])*(mx-len+1),\
                    min(dp[i][j-1][0]+(x[j]-x[i])*(mx-len+1),\
                    min(dp[i+1][j][1]+(x[j]-x[i])*(mx-len+1)+(x[j]-x[i])*(mx-len),\
                    dp[i+1][j][0]+(x[i+1]-x[i])*(mx-len+1)+(x[j]-x[i])*(mx-len)\
                    )));
        if(len==mx)
        ans=max(ans,len*m-min(dp[i][j][0],dp[i][j][1]));
        //cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<len*m-min(dp[i][j][0],dp[i][j][1])<<endl;
    }
    return ans;
}
signed main(){
    freopen("beetle.in","r",stdin);
    freopen("beetle.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    sort(x+1,x+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
    }
    printf("%lld\n",ans);
    return 0;
}