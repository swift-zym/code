#include<bits/stdc++.h>
using namespace std;
int k,tmp,vis[3000],ans[3000];
bool dfs(int now,int deep){
  if(vis[now])return 0;
  vis[now]=1;
  ans[deep]=now&1;
  if(deep==(1<<k))return 1;
  if(dfs((now<<1)&tmp,deep+1))return 1;
  if(dfs(((now<<1)|1)&tmp,deep+1))return 1;
  vis[now]=0;
  return 0;
}
int main(){
  scanf("%d",&k);
  printf("%d ",1<<k);
  tmp=(1<<k)-1;
  dfs((1<<k)-2,1);
  for(int i=1;i<=(1<<k);i++){
    printf("%d",ans[i]);
  }
  putchar(10);
  return 0;
}
