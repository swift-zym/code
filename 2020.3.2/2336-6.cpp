#include<bits/stdc++.h>
using namespace std;
struct r{
  int x1,x2,y1,y2,c;
}a[17];
int n,vis[17],ans;
bool check(int x){
  for(int i=1;i<=n;i++){
    if(x==i)continue;
    if(a[x].y1==a[i].y2&&a[i].x2>a[x].x1&&a[i].x1<a[x].x2){
      if(!vis[i])return 0;
    }
  }
  return 1;
}
void dfs(int deep,int tmp,int c){
  if(tmp>=ans)return;
  if(deep==n+1)ans=tmp;
  for(int i=1;i<=n;i++){

    if(vis[i]==0&&check(i)==1){
      if(a[i].c==c){
        vis[i]=1;
        dfs(deep+1,tmp,c);
        vis[i]=0;
      }
      else{
        vis[i]=1;
        dfs(deep+1,tmp+1,a[i].c);
        vis[i]=0;
      }
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d%d%d%d%d",&a[i].y1,&a[i].x1,&a[i].y2,&a[i].x2,&a[i].c);
  }
  ans=1e8;
  dfs(1,0,0);
  printf("%d\n",ans);
  return 0;
}
