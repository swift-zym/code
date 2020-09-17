#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll x,y,jc[2000005],inv[1000005];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    int t=x;x=y,y=t-a/b*x;
}
int main(){
    jc[1]=1;
    for(int i=2;i<=2000001;i++){
        jc[i]=i*jc[i-1]%MOD;
    }
    for(int i=1;i<=1000001;i++){
        ll x=0,y=0;
        exgcd(jc[i],MOD,x,y);
        inv[i]=(x%MOD+MOD)%MOD;
    }
    ll t,n;
    scanf("%lld",&t);
    for(ll i=1;i<=t;i++){
        scanf("%lld",&n);
        printf("%lld\n",jc[2*n]*inv[n]%MOD*inv[n]%MOD);
    }
    return 0;
}