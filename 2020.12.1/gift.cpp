#include<bits/stdc++.h>
#define N 4000000
#define MOD 1000000007
#define int long long
using namespace std;
int n,a[100001],b[100001];
int jc[4000001],inv[4000001],jcinv[4000001];
int C(int m,int n){
    return jc[m]*jcinv[n]%MOD*jcinv[m-n]%MOD;
}
signed main(){
    freopen("gift.in","r",stdin);
    freopen("gift.out","w",stdout);
    jc[0]=inv[0]=jcinv[0]=jc[1]=inv[1]=jcinv[1]=1;
    for(int i=2;i<=N;i++){
        jc[i]=jc[i-1]*i%MOD;
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
        jcinv[i]=jcinv[i-1]*inv[i]%MOD;
    }
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i==j)continue;
        ans+=C(a[i]+a[j]+b[i]+b[j],a[i]+a[j]);
        ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}