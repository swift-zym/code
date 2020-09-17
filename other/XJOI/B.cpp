#include<bits/stdc++.h>
using namespace std;
int n,a[2001],ans,mx,id;
vector<int>v[2001];
void dfs(int now,int deep,int rt,int fa){
  if(deep>mx)mx=deep,id=now;
  ans=max(ans,deep*(a[now]));
  for(int i=0;i<v[now].size();i++){
    if(v[now][i]==fa)continue;
    dfs(v[now][i],deep+1,rt,now);
  }
}
int main(){
  freopen("out.txt","r",stdin);
  freopen("ans.std.txt","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1;i<=n;i++){
    mx=0;
    dfs(i,0,i,i);
    cout<<id<<" "<<mx<<endl;
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
