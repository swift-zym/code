#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod MOD
#define ll long long
ll dp[1000006],jc[1000006],inv[1000006];
ll qpow(ll a,ll b){
    if(!b)return 1;
    ll tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int main(){
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=1000005;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])%MOD;
    }
    jc[0]=1;
    for(int i=1;i<=1000005;i++){
    jc[i]=i*jc[i-1]%mod;
    inv[i]=qpow(jc[i],mod-2);
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        if(m-n==0)printf("1\n");
        else if(n-m==1)printf("0\n");
        else if(m==0)printf("%lld\n",dp[n]);
        else printf("%lld\n",jc[n]*inv[m]%MOD*inv[n-m]%MOD*dp[n-m]%MOD);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}