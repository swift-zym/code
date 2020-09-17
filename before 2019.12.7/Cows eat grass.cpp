#include<bits/stdc++.h>
using namespace std;
int n,x[1001],dp[1001][1001][2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<n;i++)
    for(int j=1;j<=n-i+1;j++){
        dp[i][j][0]=min(dp[i+1][j][1]+(n-j+l)*(x[i+1]-x[i]),);
    }
}