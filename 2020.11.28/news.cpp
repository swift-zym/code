#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
#define dis(a,b) (abs(x[a]-x[b])+abs(y[a]-y[b]))
using namespace std;
int n,d,ans,x[101],y[101],dp[101][101];
signed main(){
    freopen("news.in","r",stdin);
    freopen("news.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    scanf("%lld",&d);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        for(int k=0;k<i;k++){
            dp[i][j]=min(dp[i][j],dp[k][j-1]+dis(k,i));
        }
        if(dp[i][j]+dis(i,0)<=d){
            ans=max(ans,j);
        }
    }
    printf("%lld\n",ans);
    return 0;
}