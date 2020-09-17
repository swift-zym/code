#include<bits/stdc++.h>
using namespace std;
int dp[15][101][2],len;
char s[101];
int l,r;
int dfs(int deep,int pre,bool lim){
  if(deep==len+1)return 1;
  if(dp[deep][pre][lim]!=-1)return dp[deep][pre][lim];
  int mx=lim?s[deep]-'0':9,tmp=0;
  for(int i=0;i<=mx;i++){
    if(i==4)continue;
    if(i==2&&pre==6)continue;
    tmp+=dfs(deep+1,i,lim&&(i==mx));
  }
  return dp[deep][pre][lim]=tmp;
}
int main(){
  while(scanf("%d%d",&l,&r)!=EOF){
    if(l==r&&l==0)break;
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
