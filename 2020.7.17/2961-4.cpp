//
// Created by swift on 2020/7/17.
//

#include<bits/stdc++.h>
#define MOD 1000000007ll
#define int long long
using namespace std;
int n,k,a[100001];
int qpow(int a,int b){
    if(!b)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=k;i<2*k;i++)a[i]=i;
    for(int i=2*k;i<=n;i++){
        a[i]=a[i-1]+a[i-k]+1;
        a[i]%=MOD;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[gcd(n,i)];
        ans%=MOD;
    }
    ans*=qpow(n,MOD-2);
    ans%=MOD;
    printf("%lld\n%lld\n",a[n],ans);
    return 0;
}