#include<bits/stdc++.h>
using namespace std;
int n,a[50001],mx,id,idd,x[50001],y[50001];
vector<int>v[50001];
void dfs(int now,int deep,int fa){
  if(deep>mx)id=now,mx=deep;
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs(v[now][i],deep+1,now);
  }
}
void dfs1(int now,int deep,int fa){
  x[now]=deep;
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs1(v[now][i],deep+1,now);
  }
}
void dfs2(int now,int deep,int fa){
  y[now]=deep;
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs2(v[now][i],deep+1,now);
  }
}
int main(){
  //freopen("out.txt","r",stdin);
  //freopen("ans.txt","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1,0,1);
  idd=id;
  mx=0;
  dfs(id,0,id);
  dfs1(id,0,id);
  dfs2(idd,0,idd);
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=max(ans,a[i]*max(x[i],y[i]));
  }
  printf("%d\n",ans);
  return 0;
}
/*
8
3 1 4 1 5 9 2 6
1 2
2 3
2 4
1 5
5 6
4 8
3 7
*/
