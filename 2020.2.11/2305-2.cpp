#include<bits/stdc++.h>
using namespace std;
int n,m,k,du[6001],sg[6001],vis[6005];
vector<int>v[6001],vv[6001];
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    vv[b].push_back(a);
    du[a]++;
  }
  queue<int>q;
  for(int i=1;i<=n;i++){
    if(!du[i])q.push(i);
  }
  while(!q.empty()){
    int now=q.front();q.pop();
    memset(vis,0,sizeof(vis));
    int mx=0;
    for(int i=0;i<v[now].size();i++){
      mx=max(sg[v[now][i]],mx);
      vis[sg[v[now][i]]]=1;
    }
    for(int i=0;i<=mx+1;i++){
      if(!vis[i]){
        sg[now]=i;
        break;
      }
    }
    for(int i=0;i<vv[now].size();i++){
      du[vv[now][i]]--;
      if(!du[vv[now][i]]){
        q.push(vv[now][i]);
      }
    }
  }
  int ans=0;
  for(int i=1;i<=k;i++){
    int a;
    scanf("%d",&a);
    ans^=sg[a];
  }
  if(ans!=0){
    puts("win");
  }
  else{
    puts("lose");
  }
  return 0;
}
