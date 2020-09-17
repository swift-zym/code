#include<bits/stdc++.h>
using namespace std;
int n,l[10000],d[100000],dp[1100000];
int sum;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&l[i]);
        sum+=l[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }
    for(int i=1;i<=n;i++)
    for(int j=n;j>=l[i];j--){
        dp[j]=max(dp[j],dp[j-l[i]]+d[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}