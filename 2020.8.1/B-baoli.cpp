//
// Created by swift on 2020/8/1.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,f[100001],w[100001];
signed main(){
    freopen("data.in","r",stdin);
    freopen("data.ans","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&f[i]);
        f[i]++;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int s=0,m=1e8;
        int now=i;
        for(int j=1;j<=k;j++){
            s+=w[now];
            m=min(w[now],m);
            now=f[now];
        }
        printf("%lld %lld\n",s,m);
    }
    return 0;
}