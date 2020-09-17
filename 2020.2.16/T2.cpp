#include<bits/stdc++.h>
using namespace std;
vector<int>v[301];
int p[301];
int n;
int vis[301];
int tmp[301];
int mi=0;
void dfs(int deep){
  if(deep==n+1){
    memset(vis,0,sizeof(vis));
    int num=0,sum=0,x=0;
    for(int i=1;i<=n;i++){
      if(!tmp[i])continue;
      x++;
      for(int j=0;j<v[i].size();j++){
        if(!vis[v[i][j]]){
          num++;
          vis[v[i][j]]=1;
        }
      }
      sum+=p[i];
    }
    if(x!=num)return;
    mi=min(mi,sum);
    return;
  }
  tmp[deep]=0;
  dfs(deep+1);
  tmp[deep]=1;
  dfs(deep+1);
  tmp[deep]=0;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int t;
    scanf("%d",&t);
    while(t--){
      int a;
      scanf("%d",&a);
      v[i].push_back(a);
    }
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&p[i]);
  }
  if(n>20){
    int sum=0;
    for(int i=1;i<=n;i++){
      sum+=p[i];
    }
    printf("%d\n",sum);
  }
  else{
    dfs(1);
    printf("%d\n",mi);
  }
  return 0;
}
