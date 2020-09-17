#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define bas1 23333
#define bas2 19260817
#define int unsigned long long
vector<int>v[100001],ans[100001];
unordered_map<int,int>ma;
int n,du[100001],num;
void dfs(int now,int fa){
  ans[now].push_back(du[now]);
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs(v[now][i],now);
    for(int j=0;j<ans[v[now][i]].size();j++){
      ans[now].push_back(ans[v[now][i]][j]*bas1+du[now]*bas2);
    }
  }
  for(int i=0;i<ans[now].size();i++){
    if(!ma[ans[now][i]]){
      ma[ans[now][i]]=1;
      num++;
    }
  }
}
signed main(){
  scanf("%llu",&n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%llu%llu",&a,&b);
    v[b].push_back(a);
    du[a]++;du[b]++;
  }
  dfs(1,1);
  printf("%llu\n",num);
  return 0;
}
