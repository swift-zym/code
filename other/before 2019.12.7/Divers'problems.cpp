//题目名称：潜水员的问题
#include<bits/stdc++.h>
using namespace std;
int main(){
int T,A,t[1001],a[1001],w[1001],n;
scanf("%d%d",&T,&A);
scanf("%d",&n);
for(int i=1;i<=n;i++){
    scanf("%d%d%d",&t[i],&a[i],&w[i]);
}
int dp[22][80];
memset(dp,0x3f,sizeof(dp));
dp[0][0]=0;
for(int i=1;i<=n;i++)
for(int ii=T;ii>=0;ii--)
for(int jj=A;jj>=0;jj--){
    dp[min(ii+t[i],T)][min(jj+a[i],A)]=min(dp[min(ii+t[i],T)][min(jj+a[i],A)],dp[ii][jj]+w[i]);
}
printf("%d\n",dp[T][A]);
#ifdef WIN32
system("pause");
#endif
    return 0;
}