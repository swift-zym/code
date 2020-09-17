//
// Created by swift on 2020/7/25.
//

#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int n,a[500001];
int stmi[500001][20],stmx[500001][20];
int querymx(int l,int r){
    if(l>r)return 0;
    int k=log2(r-l+1);
    return max(stmx[l][k],stmx[r-(1<<k)+1][k]);
}
int querymi(int l,int r){
    if(l>r)return 0;
    int k=log2(r-l+1);
    return min(stmi[l][k],stmi[r-(1<<k)+1][k]);
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        stmi[i][0]=stmx[i][0]=a[i];
    }
    for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++){
            stmi[j][i]=min(stmi[j][i-1],stmi[min(j+(1<<(i-1)),n)][i-1]);
            stmx[j][i]=max(stmx[j][i-1],stmx[min(j+(1<<(i-1)),n)][i-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            ans+=(querymx(i,j)*querymi(i,j))%MOD;
            ans%=MOD;
        }
    printf("%lld\n",ans);
    return 0;
}