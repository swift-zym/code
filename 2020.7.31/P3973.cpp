//
// Created by swift on 2020/7/31.
//
//#import "lxxs.h"
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[501],b[501][501],c[501],d[501];
signed main(){
    srand(time(0));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%lld",&b[i][j]);
        }
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)a[i]=1;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            d[i]+=a[j]*b[i][j];
        }
    int v=0;
    for(int i=1;i<=n;i++){
        v+=(d[i]-c[i])*a[i];
    }
    printf("%lld\n",v);
    return 0;
}