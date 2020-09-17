//
// Created by swift on 2020/6/26.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[501][501][20];
int sum[501];
int n,c,s[501],x[501];
signed main(){
    scanf("%lld%lld",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&s[i]);
        sum[i]=s[i]+sum[i-1];
        if(i!=c){
            dp[i][i][0]=dp[i][i][1]=1e8;
        }
    }
    for(int l=2;l<=n;l++)
        for(int i=1;i<=n;i++){
            int j=i+l-1;
            if(i>c||j<c){
                dp[i][j][0]=dp[i][j][1]=1e8;
                continue;
            }
            if(j>n)continue;
            int v1,v2,v3,v4;
            v1=(dp[i][j-1][0])+(sum[i-1]+sum[n]-sum[j-1])*(x[j]-x[i]);
            v2=(dp[i][j-1][1])+(sum[i-1]+sum[n]-sum[j-1])*(x[j]-x[j-1]);
            v3=(dp[i+1][j][0])+(sum[i]+sum[n]-sum[j])*(x[i+1]-x[i]);
            v4=(dp[i+1][j][1])+(sum[i]+sum[n]-sum[j])*(x[j]-x[i]);
            dp[i][j][0]=min(v3,v4);
            dp[i][j][1]=min(v1,v2);
        }
    printf("%lld\n",min(dp[1][n][1],dp[1][n][0]));
    return 0;
}