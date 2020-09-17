//
// Created by 张成 on 2020/5/24.
//

#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int n,a[1000001];
int qpow(int a,int b){
    if(b==0)return 1;
    int v=qpow(a,b/2);
    return b%2?(((v*v)%MOD)*a)%MOD:(v*v)%MOD;
}
signed main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%lld",&n);
    int tmp=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==0){
            tmp++;
        }
    }
    printf("%lld\n",((n-tmp+1)*qpow(2,tmp))%MOD);
    return 0;
}