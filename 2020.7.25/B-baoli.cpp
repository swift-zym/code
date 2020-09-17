//
// Created by swift on 2020/7/25.
//
#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
int a[5000];
int n;
signed main(){
    freopen("data.in","r",stdin);
    freopen("data.ans","w",stdout);
    int ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) {
        for (int j = i; j <= n; j++) {
            int mi=1e9+1,mx=-1;
            for(int k=i;k<=j;k++)
            mi=min(mi,a[k]),mx=max(mx,a[k]);
            ans+=mi*mx%MOD;
            ans%=MOD;
        }
    }
    printf("%lld\n",ans);
    return 0;
}