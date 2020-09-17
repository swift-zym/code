#include<bits/stdc++.h>
using namespace std;
int dp[15][1001][2],len;
char s[101];
int dfs(int deep,int pre,bool lim,bool zer){
  //cout<<deep<<" "<<pre<<" "<<lim<<endl;
  if(deep==len+1&&pre==1000)return 0;
  if(deep==len+1)return 1;
  if(dp[deep][pre][lim]!=-1)return dp[deep][pre][lim];
  int mx=lim?s[deep]-'0':9,tmp=0;
  for(int i=0;i<=mx;i++)if(abs(i-pre)>=2)tmp+=dfs(deep+1,(zer&&(i==0))?1000:i,lim&&(i==mx),zer&&(i==0));
  return dp[deep][pre][lim]=tmp;
}
int main(){
  int l,r;
  while(scanf("%d%d",&l,&r)!=EOF){
    if(l>r){puts("0");continue;}
    memset(dp,-1,sizeof(dp));
    sprintf(s+1,"%d",r);
    len=strlen(s+1);
    int sr=dfs(1,1000,1,1);
    //puts("----");
    memset(dp,-1,sizeof(dp));
    sprintf(s+1,"%d",l-1);
    len=strlen(s+1);
    int sl=dfs(1,1000,1,1);
    printf("%d\n",sr-sl);
  }
}
