//
// Created by zhangyiming on 2020/4/25.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int p1,p2,k;
signed main(){
    //freopen("color.in","r",stdin);
    //freopen("color.out","w",stdout);
    int t;
    scanf("%lld",&t);
    //3 2 2
    //2 3
    for(int i=1;i<=t;i++){
        scanf("%lld%lld%lld",&p1,&p2,&k);
        if (p1 > p2)swap(p1, p2);
        if(p1==1&&p2==1){
            puts("No");
            continue;
        }
        int a = p2 / p1, b = p2 % p1;
        if(a<k-1){
            puts("Yes");
            continue;
        }
        if(a>k){
            puts("No");
            continue;
        }
        if(b==0&&a<=k){
            puts("Yes");
            continue;
        }
        if(b==0){
            puts("No");
            continue;
        }
        if(a==k){
            puts("No");
            continue;
        }
        puts("No");
    }
    return 0;
}