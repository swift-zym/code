#include<bits/stdc++.h>
using namespace std;
int n,k,x[1001],dp[1001][1001][2]; 
int main(){
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	sort(x+1,x+n+1); 
	for(int i=1;i<=n;i++){
		dp[i][i][1]=dp[i][i][0]=abs(x[i]-k)*n;
	}
	for(int len=1;len<n;len++)
	for(int i=1;i+len<=n;i++){
		dp[i][i+len][0]=min(dp[i][i+len][0],dp[i+1][i+len][0]+(x[i+1]-x[i])*(n-len));
		dp[i][i+len][0]=min(dp[i][i+len][0],dp[i+1][i+len][1]+(x[i+len]-x[i])*(n-len));
		dp[i][i+len][1]=min(dp[i][i+len][1],dp[i][i+len-1][1]+(x[i+len]-x[i+len-1])*(n-len));
		dp[i][i+len][1]=min(dp[i][i+len][1],dp[i][i+len-1][0]+(x[i+len]-x[i])*(n-len));
	} 
	printf("%d\n",min(dp[1][n][1],dp[1][n][0])); 
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
} 