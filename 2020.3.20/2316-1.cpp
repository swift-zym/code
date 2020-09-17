#include<bits/stdc++.h>
using namespace std;
int m,n,s[1001],dp[1001][1001];
vector<int>v[1001];
void dfs(int now,int fa){
  dp[now][1]=s[now];
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs(v[now][i],now);
    for(int j=m;j>=2;j--){
      for(int k=0;k<j;k++){
        dp[now][j]=max(dp[now][j],dp[v[now][i]][k]+dp[now][j-k]);
      }
      //printf("dp[%d][%d]=%d(upd:%d)\n",now,j,dp[now][j],v[now][i]);
    }
  }
}
int main(){
  scanf("%d%d",&m,&n);
  for(int i=1;i<=m;i++){
    int f;
    scanf("%d%d",&f,&s[i]);
    v[f].push_back(i);
  }
  dfs(0,0);
  printf("%d\n",dp[0][n+1]);
  return 0;
}
