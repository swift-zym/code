//
// Created by 张成 on 2020/5/24.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt,k[1000000],dp[550000];
int main(){
    freopen("watch.in","r",stdin);
    freopen("watch.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int bas=1;
        while(y>=bas){
            y-=bas;
            k[++cnt]=bas*x;
            bas*=2;
        }
        if(y){
            k[++cnt]=y*x;
        }
    }
    for(int i=1;i<=500000;i++){
        dp[i]=1e9;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=500000;j>=k[i];j--){
            dp[j]=min(dp[j],dp[j-k[i]]+1);
        }
    }

    for(int i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        if(dp[t]==1e9){
            puts("No");
        }
        else{
            puts("Yes");
        }
    }
    return 0;
}