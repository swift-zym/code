//
// Created by swift on 2020/8/2.
//

#include<bits/stdc++.h>
#define MOD 1000000009
#define int long long
using namespace std;
int n,k,a[2001],b[2001],jc[2001],inv[2001],jcinv[2001];
int C(int M,int N){return jc[M]*jcinv[N]%MOD*jcinv[M-N]%MOD;}
int dp[2001][2001],l[2001],g[2001];
signed main(){
    jc[0]=inv[0]=jcinv[0]=1;
    jc[1]=inv[1]=jcinv[1]=1;
    for(int i=2;i<=2000;i++){
        jc[i]=jc[i-1]*i%MOD;
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
        jcinv[i]=jcinv[i-1]*inv[i]%MOD;
    }
    scanf("%lld%lld",&n,&k);
    if((n+k)%2){
        puts("0");
        return 0;
    }
    else{
        k=(n+k)/2;
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int loc=0;
    for(int i=1;i<=n;i++){
        while(loc<n&&a[i]>b[loc+1])loc++;
        l[i]=loc;
        //cout<<i<<" "<<l[i]<<endl;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= i;j++) {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*max(0ll,l[i]-j+1)%MOD;
            dp[i][j]%=MOD;
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    for(int i=0;i<=n;i++)g[i]=dp[n][i]*jc[n-i]%MOD;
    int ans=0;
    for(int i=k;i<=n;i++){
        if((i-k)%2==0){
            ans+=C(i,k)*g[i]%MOD;
            ans%=MOD;
        }
        else{
            ans-=C(i,k)*g[i]%MOD;
            ans=(ans+MOD)%MOD;
        }
        //cout<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
 * 5 15 35 45
 * 10 20 30 40
 */