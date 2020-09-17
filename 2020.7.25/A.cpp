//
// Created by swift on 2020/7/25.
//
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[1<<20][21];
int head[21],nxt[1000],to[1000],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int n,m,k;
int trans[1<<20][21];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(b,a);
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            for(int ii=head[j+1];ii;ii=nxt[ii]){
                if((i&(1<<(to[ii]-1)))==0){
                    trans[i][j]++;
                }
            }
        }
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<=k;j++){
            if(dp[i][j]){
                for(int ii=0;ii<n;ii++){
                    if((i&(1<<ii))==0){
                        if(j+trans[i][ii]<=k) {
                            dp[i | (1 << ii)][j + trans[i][ii]] += dp[i][j];
                            dp[i | (1 << ii)][j + trans[i][ii]] %= MOD;
                        }
                    }
                }
            }
        }
    int sum=0;
    for(int i=0;i<=k;i++){
        sum+=dp[(1<<n)-1][i];
        sum%=MOD;
    }
    printf("%d\n",sum);
    return 0;
}
//400