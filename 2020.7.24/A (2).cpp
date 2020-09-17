//
// Created by swift on 2020/7/24.
//

#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
char a[6000],b[6000];
int dp[5001][5001],ans[5001][5001];
int n,m;
signed main(){
    scanf("%s",a+1);
    scanf("%s",b+1);
    n=strlen(a+1);m=strlen(b+1);
    for(int i=0;i<=n;i++)ans[i][0]=1;
    for(int i=0;i<=m;i++)ans[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans[i][j]=ans[i-1][j-1];
                if(dp[i-1][j]==dp[i][j]){
                    ans[i][j]+=ans[i-1][j];ans[i][j]%=MOD;
                }
                if(dp[i][j-1]==dp[i][j]){
                    ans[i][j]+=ans[i][j-1];ans[i][j]%=MOD;
                }
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if(dp[i][j-1]>dp[i-1][j]){
                    ans[i][j]=ans[i][j-1];
                }
                else if(dp[i][j-1]<dp[i-1][j]){
                    ans[i][j]=ans[i-1][j];
                }
                else{
                    if(dp[i-1][j-1]==dp[i][j]) {
                        ans[i][j] = (ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1]+MOD);
                        ans[i][j]%=MOD;
                    }
                    else {
                        ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                        ans[i][j]%=MOD;
                    }
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",ans[i][j]);
        }
        putchar(10);
    }
    puts("---");;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        putchar(10);
    }*/
    printf("%lld\n%lld\n",dp[n][m],ans[n][m]);
    return 0;
}