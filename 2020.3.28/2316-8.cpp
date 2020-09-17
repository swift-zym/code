#include<bits/stdc++.h>
using namespace std;
int m,n,c[10001],dp[10001][3];
vector<int>v[10001];
void dfs(int now,int fa){
  if(now<=n){
    if(c[now]){
      dp[now][0]=1e8;
      dp[now][1]=1;
      dp[now][2]=1;
    }
    else{
      dp[now][0]=1;
      dp[now][1]=1e8;
      dp[now][2]=1;
    }
  }
  else{
    dp[now][0]=dp[now][1]=1;
  }
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs(v[now][i],now);
    dp[now][0]+=min(dp[v[now][i]][0]-1,min(dp[v[now][i]][1],dp[v[now][i]][2]));
    dp[now][1]+=min(dp[v[now][i]][0],min(dp[v[now][i]][1]-1,dp[v[now][i]][2]));
    dp[now][2]+=min(dp[v[now][i]][0],min(dp[v[now][i]][1],dp[v[now][i]][2]));
  }
}
int main(){
  scanf("%d%d",&m,&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&c[i]);
  }
  for(int i=1;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1;i<=m;i++){
    if(v[i].size()>1){
      dfs(i,i);
      printf("%d\n",min(dp[i][0],min(dp[i][1],dp[i][2])));
      return 0;
    }
  }
  return 0;
}
