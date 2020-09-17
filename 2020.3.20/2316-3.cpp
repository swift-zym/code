#include<bits/stdc++.h>
using namespace std;
int n,dp[1600][3],s[1600];
vector<int>v[1600];
void dfs(int now,int fa){
  int mi=1e9;
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs(v[now][i],now);
    dp[now][0]+=min(dp[v[now][i]][0],dp[v[now][i]][1]);
    mi=min(mi,dp[v[now][i]][1]-dp[v[now][i]][0]);
    dp[now][1]+=min(dp[v[now][i]][0],min(dp[v[now][i]][1],dp[v[now][i]][2]));
    dp[now][2]+=min(dp[v[now][i]][0],dp[v[now][i]][1]);
  }
  if(mi>0)dp[now][0]+=mi;
  dp[now][1]+=s[now];
  //cout<<now<<" "<<dp[now][0]<<" "<<dp[now][1]<<endl;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int id;
    scanf("%d",&id);
    scanf("%d",&s[id]);
    //id++;
    int k;
    scanf("%d",&k);
    for(int j=1;j<=k;j++){
      int a;
      scanf("%d",&a);
      //a++;
      v[id].push_back(a);
      v[a].push_back(id);
    }
  }
  dfs(1,1);
  if(n==1){
    printf("%d\n",dp[1][1]);
  }
  else{
    printf("%d\n",min(dp[1][0],dp[1][1]));
  }
  return 0;
}
