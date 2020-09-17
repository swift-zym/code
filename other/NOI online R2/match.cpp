//
// Created by zhangyiming on 2020/4/25.
//

#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n;
char s[6000];

signed main(){
    scanf("%lld",&n);
    scanf("%s",s);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
    }
    int ans=1;
    for(int i=n/2;i>=1;i--){
        ans*=i;
        ans%=MOD;
        ans*=i;
        ans%=MOD;
    }
    for(int i=1;i<=n/2;i++){
        printf("0 ");
    }
    printf("%d",ans);
    return 0;
}