//
// Created by swift on 2020/7/20.
//

#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
//C(N,M)*()
int T,n,m;
int f[1100000],jc[1100000],inv[1100000],jcinv[1100000];
void pre(){
    f[0]=1;
    f[2]=1;
    f[3]=2;
    for(int i=4;i<=1000000;i++){
        f[i]=f[i-1]*i+((i%2)?-1:1);
        f[i]%=MOD;
    }
    jc[0]=1;
    inv[0]=jcinv[0]=1;
    jc[1]=1;
    inv[1]=jcinv[1]=1;
    for(int i=2;i<=1000000;i++){
        jc[i]=jc[i-1]*i;
        jc[i]%=MOD;
        inv[i]=(MOD-MOD/i)*inv[MOD%i];
        inv[i]%=MOD;
        jcinv[i]=jcinv[i-1]*inv[i];
        jcinv[i]%=MOD;
    }
}
int C(int a,int b){
    if(a<b)return 0;
    return jc[a]*jcinv[b]%MOD*jcinv[a-b]%MOD;
}
signed main(){
    pre();
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",f[n-m]*C(n,m)%MOD);
    }
    return 0;
}