//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m,k,dp[900][900][17][2],a[900][900];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dp[i][j][0][0]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            for(int ii=0;ii<=15;ii++){
                dp[i+1][j][(ii+a[i][j])%(k+1)][1]+=dp[i][j][ii][0];
                dp[i+1][j][(ii+a[i][j])%(k+1)][1]%=MOD;
                dp[i][j+1][(ii+a[i][j])%(k+1)][1]+=dp[i][j][ii][0];
                dp[i][j+1][(ii+a[i][j])%(k+1)][1]%=MOD;
                dp[i+1][j][(ii-a[i][j]+(k+1))%(k+1)][0]+=dp[i][j][ii][1];
                dp[i+1][j][(ii-a[i][j]+(k+1))%(k+1)][0]%=MOD;
                dp[i][j+1][(ii-a[i][j]+(k+1))%(k+1)][0]+=dp[i][j][ii][1];
                dp[i][j+1][(ii-a[i][j]+(k+1))%(k+1)][0]%=MOD;
                /*cout<<(ii-a[i][j]+(k+1))%(k+1)<<endl;
                printf("dp[%d][%d][%d][%d]=%d\n",i,j,ii,0,dp[i][j][ii][0]);
                printf("dp[%d][%d][%d][%d]=%d\n",i,j,ii,1,dp[i][j][ii][1]);*/
            }
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            ans+=dp[i][j][a[i][j]%(k+1)][1];
            ans%=MOD;
        }
    printf("%d\n",ans);
    return 0;
}