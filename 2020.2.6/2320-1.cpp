#include<bits/stdc++.h>
using namespace std;
int n,m,fa[100001][21],dep[100001],tmp[100001],ans;
vector<int>v[100001];
void dfs(int now,int f){
  fa[now][0]=f;
  for(int i=0;i<v[now].size();i++){
    if(f!=v[now][i]){
      dep[v[now][i]]=dep[now]+1;
      dfs(v[now][i],now);
    }
  }
}
void solve(int now,int f){
  for(int i=0;i<v[now].size();i++){
    if(f!=v[now][i]){
      solve(v[now][i],now);
      tmp[now]+=tmp[v[now][i]];
    }
  }
  if(now!=1){
    if(tmp[now]==0)ans+=m;
    else if(tmp[now]==1)ans+=1;
  }
}
int lca(int a,int b){
  if(dep[a]<dep[b])swap(a,b);
  for(int i=20;i>=0;i--){
    if(dep[fa[a][i]]>=dep[b]){
      a=fa[a][i];
    }
  }
  if(a==b)return a;
  for(int i=20;i>=0;i--){
    if(fa[a][i]!=fa[b][i]){
      a=fa[a][i];
      b=fa[b][i];
    }
  }
  return fa[a][0];
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1,1);
  for(int j=1;j<=20;j++)
  for(int i=1;i<=n;i++){
    fa[i][j]=fa[fa[i][j-1]][j-1];
  }
  for(int j=1;j<=m;j++){
    int a,b;
    scanf("%d%d",&a,&b);
    tmp[a]++;
    tmp[b]++;
    tmp[lca(a,b)]-=2;
  }
  solve(1,1);
  printf("%d\n",ans);
  return 0;
}
