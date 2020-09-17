#include<bits/stdc++.h>
using namespace std;
int dp[15][10][2],len;
char s[101];
int dfs(int deep,int pre,bool lim){
  if(deep==len+1)return 1;
  if(dp[deep][pre][lim]!=-1)return dp[deep][pre][lim];
  int mx=lim?s[deep]-'0':9,tmp=0;
  for(int i=pre;i<=mx;i++)tmp+=dfs(deep+1,i,lim&&(i==mx));
  return dp[deep][pre][lim]=tmp;
}
int main(){
  int l,r;
  while(scanf("%d%d",&l,&r)!=EOF){
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
