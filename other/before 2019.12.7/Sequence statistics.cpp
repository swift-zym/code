//题目名：序列统计
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000003
#define ll long long
ll jc[MOD],inv[MOD];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll t=x;
    x=y,y=t-a/b*x;
}
ll C(ll n,ll m){
    if(n<m)return 0;
    if(n<MOD&&m<MOD)return jc[n]*inv[m]%MOD*inv[n-m]%MOD;
    return C(n/MOD,m/MOD)*C(n%MOD,m%MOD)%MOD;
}
int main(){
    jc[0]=1;
    for(int i=1;i<=MOD;i++){
    jc[i]=i*jc[i-1]%MOD;
    }
    for(int i=0;i<=MOD;i++){
    ll x,y;
    exgcd(jc[i],MOD,x,y);
    inv[i]=(x%MOD+MOD)%MOD;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,l,r;
        scanf("%lld%lld%lld",&n,&l,&r);
        printf("%lld\n",(C(n+r-l+1,r-l+1)+MOD-1)%MOD);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}