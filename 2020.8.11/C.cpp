//
// Created by swift on 2020/8/11.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[9],ans;
#define MOD 10007
void dfs(int deep){
    if(deep==n+1){
        int tmp=1;
        for(int i=1;i<=n;i++)tmp*=a[i];
        if(tmp%k)return;
        tmp/=k;
        if(__gcd(tmp,k)==1){
            ans++;
            ans%=MOD;
        }
        return;
    }
    for(int i=1;i<=m;i++){
        a[deep]=i;
        dfs(deep+1);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}