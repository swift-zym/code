//
// Created by swift on 2020/7/18.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[2001][2001];
int sum[2001][2001];
int t,k;
int n,m;
signed main(){
    s[0][0]=1;
    scanf("%lld%lld",&t,&k);
    for(int i=1;i<=2000;i++)
        for(int j=1;j<=i;j++){
            s[i][j]=s[i-1][j-1]+((j*s[i-1][j])%k);
            s[i][j]%=k;
        }
    for(int i=0;i<=2000;i++)
        for(int j=0;j<=i;j++){
            s[i][j]=(s[i][j]==0);
        }
    for(int i=1;i<=2000;i++){
        sum[0][i]=sum[0][i-1]+s[0][i];
        sum[i][0]=sum[i-1][0]+s[i][0];
    }
    for(int i=1;i<=2000;i++)
        for(int j=1;j<=2000;j++){
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+s[i][j];
        }
    while(t--){
        int n,m;
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",sum[n][m]);
    }
    return 0;
}