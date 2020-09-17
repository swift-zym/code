#include<bits/stdc++.h>
using namespace std;
int score[10][10]={{0,0,0,0,0,0,0,0,0,0},{0,6,6,6,6,6,6,6,6,6},{0,6,7,7,7,7,7,7,7,6},{0,6,7,8,8,8,8,8,7,6},{0,6,7,8,9,9,9,8,7,6},{0,6,7,8,9,10,9,8,7,6},{0,6,7,8,9,9,9,8,7,6}, {0,6,7,8,8,8,8,8,7,6},{0,6,7,7,7,7,7,7,7,6},{0,6,6,6,6,6,6,6,6,6}};
int belong[10][10]={{0,0,0,0,0,0,0,0,0,0},{0,1,1,1,2,2,2,3,3,3},{0,1,1,1,2,2,2,3,3,3},{0,1,1,1,2,2,2,3,3,3},{0,4,4,4,5,5,5,6,6,6},{0,4,4,4,5,5,5,6,6,6},{0,4,4,4,5,5,5,6,6,6},{0,7,7,7,8,8,8,9,9,9},{0,7,7,7,8,8,8,9,9,9},{0,7,7,7,8,8,8,9,9,9}};
struct len{
  int id,num=0;
  bool operator <(const len &t)const{
    return num>t.num;
  }
}tmp[10];
int vis[3][10][10],idx[82],a[10][10],ans[10][10],mx=-1;
int solve(){
  int t=0;
  for(int i=1;i<=9;i++)
  for(int j=1;j<=9;j++){
    t+=ans[i][j]*score[i][j];
  }
  return t;
}
void dfs(int deep){
  int x=idx[deep]/9,y=9;
  if(idx[deep]%9){
    x++;
    y=idx[deep]%9;
  }
  if(deep==82){
    mx=max(mx,solve());
    return;
  }
  if(a[x][y]){
    dfs(deep+1);
    return;
  }
  else{
    for(int i=1;i<=9;i++){
      if(vis[0][x][i]||vis[1][y][i]||vis[2][belong[x][y]][i])continue;
      ans[x][y]=i;
      vis[0][x][i]=1;
      vis[1][y][i]=1;
      vis[2][belong[x][y]][i]=1;
      dfs(deep+1);
      vis[0][x][i]=0;
      vis[1][y][i]=0;
      vis[2][belong[x][y]][i]=0;
    }
  }
}
int main(){
  for(int i=1;i<=9;i++)
  for(int j=1;j<=9;j++){
    scanf("%d",&a[i][j]);
    tmp[i].id=i;
    if(a[i][j]){
      ans[i][j]=a[i][j];
      vis[0][i][a[i][j]]=1;
      vis[1][j][a[i][j]]=1;
      vis[2][belong[i][j]][a[i][j]]=1;
      tmp[i].num++;
    }
  }
  sort(tmp+1,tmp+9+1);
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      idx[(i-1)*9+j]=(tmp[i].id-1)*9+j;
    }
  }
  dfs(1);
  printf("%d\n",mx);
  return 0;
}
