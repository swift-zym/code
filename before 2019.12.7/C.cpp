//题目名：C君的疑惑
#include<bits/stdc++.h>
using namespace std;
int n,m,v,c[10001],w[10001],dp1[1001][10001],dp2[1001][10001],no[10001];
int main(){
    scanf("%d%d%d",&n,&m,&v);
    for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=v;j++){
            if(j>=w[i])
                dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-w[i]]+c[i]);
            else dp1[i][j]=dp1[i-1][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<=v;j++){
            if(j>=w[i])
                dp2[i][j]=max(dp2[i+1][j],dp2[i+1][j-w[i]]+c[i]);
            else dp2[i][j]=dp2[i+1][j];
        }
    }
    for(int i=1;i<=m;i++){
        int l,r,ans=-1;
        scanf("%d%d",&l,&r);
        if(r<l){
            printf("%d\n",dp1[n][v]);
            continue;
        }
        for(int i=0;i<=v;i++)ans=max(ans,dp1[l-1][i]+dp2[r+1][v-i]);
        printf("%d\n",ans);
    }
    return 0;
}