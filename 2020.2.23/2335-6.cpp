#include<bits/stdc++.h>
using namespace std;
int n,mp[1001][1001],vis[1001][1001];
bool flag1,flag2;
int mx[]={1,0,-1,0,1,1,-1,-1},my[]={0,1,0,-1,1,-1,1,-1};
void dfs(int x,int y){
  vis[x][y]=1;
  for(int i=0;i<=7;i++){
    int nx=x+mx[i],ny=y+my[i];
    if(nx<1||ny<1||nx>n||ny>n)continue;
    if(mp[x][y]!=mp[nx][ny]){
      if(mp[x][y]>mp[nx][ny])flag2=0;
      else flag1=0;
    }
    else if(!vis[nx][ny]){
      dfs(nx,ny);
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    scanf("%d",&mp[i][j]);
  }
  int ans1=0,ans2=0;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    if(!vis[i][j]){
      flag1=flag2=1;
      dfs(i,j);
      if(flag1)ans1++;
      if(flag2)ans2++;
    }
  }
  printf("%d %d\n",ans1,ans2);
  return 0;
}
