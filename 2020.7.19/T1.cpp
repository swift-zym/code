//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
using namespace std;
/*
 * a b c d
 * i j k
 * |i+j-c-d| -
 * |i+c-j-d| -
 * |i+d-j-c| ?
 */

#define MOD 1000000007
#define int long long
int n,T,a[3001],b[5000001],cnt;
signed main(){
    scanf("%lld",&T);
    while(T--){
        cnt=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                b[++cnt]=(a[i]+a[j])%MOD;
            }
        }
        int ansa=0,ansb=0;
        sort(a+1,a+n+1);
        sort(b+1,b+cnt+1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ansa+=(a[j]-a[i]);
                ansa%=MOD;
            }
        }
        for(int i=1;i<=cnt;i++){
            ansb+=((b[i]*(i-1))-(b[i]*(cnt-i)));
            //ansb%=MOD;
        }
        ansb=(ansb-(ansa*(n-2)));
        ansb*=2;
        ansb%=MOD;
        printf("%lld\n",(ansb+MOD)%MOD);
    }
    return 0;
}