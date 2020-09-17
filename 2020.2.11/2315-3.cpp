#include<bits/stdc++.h>
using namespace std;
int dp[15][101][2],len;
char s[101];
int l,r,n;
int dfs(int deep,int sum,bool lim){
  if(deep==len+1&&sum!=0)return 0;
  if(deep==len+1)return 1;
  if(dp[deep][sum][lim]!=-1)return dp[deep][sum][lim];
  int mx=lim?s[deep]-'0':9,tmp=0;
  for(int i=0;i<=mx;i++)tmp+=dfs(deep+1,(sum+i)%n,lim&&(i==mx));
  return dp[deep][sum][lim]=tmp;
}
int main(){
  while(scanf("%d%d%d",&l,&r,&n)!=EOF){
    memset(dp,-1,sizeof(dp));
    sprintf(s+1,"%d",r);
    len=strlen(s+1);
    int sr=dfs(1,0,1);
    memset(dp,-1,sizeof(dp));
    sprintf(s+1,"%d",l-1);
    len=strlen(s+1);
    int sl=dfs(1,0,1);
    printf("%d\n",sr-sl);
  }
}
