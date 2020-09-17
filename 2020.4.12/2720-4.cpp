#include<bits/stdc++.h>
using namespace std;
int w,h,a[1001][1001],vis[1001][1001],dis1[1001][1001],dis2[1001][1001];
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
int sx,sy,ex,ey;
struct node{
  int x,y,ans;
};
int main(){
  scanf("%d%d",&w,&h);
  swap(w,h);
  for(int i=1;i<=w;i++)
  for(int j=1;j<=h;j++){
    scanf("%d",&a[i][j]);
    if(a[i][j]==2){
      sx=i;
      sy=j;
    }
    if(a[i][j]==3){
      ex=i;
      ey=j;
    }
  }
  memset(vis,0,sizeof(vis));
  memset(dis1,0x3f,sizeof(dis1));
  memset(dis2,0x3f,sizeof(dis2));
  queue<node>q;
  vis[sx][sy]=1;
  q.push({sx,sy,0});
  while(!q.empty()){
    node now=q.front();
    dis1[now.x][now.y]=now.ans;
    q.pop();
    for(int i=0;i<=3;i++){
      int nx=now.x+mx[i],ny=now.y+my[i];
      if(vis[nx][ny]||nx<1||nx>w||ny<1||ny>h||a[nx][ny]==1||a[nx][ny]==3)continue;
      vis[nx][ny]=1;
      q.push({nx,ny,now.ans+1});
    }
  }
  memset(vis,0,sizeof(vis));
  vis[ex][ey]=1;
  q.push({ex,ey,0});
  while(!q.empty()){
    node now=q.front();
    dis2[now.x][now.y]=now.ans;
    q.pop();
    for(int i=0;i<=3;i++){
      int nx=now.x+mx[i],ny=now.y+my[i];
      if(vis[nx][ny]||nx<1||nx>w||ny<1||ny>h||a[nx][ny]==1)continue;
      vis[nx][ny]=1;
      q.push({nx,ny,now.ans+1});
    }
  }
  /*for(int i=1;i<=w;i++){
  for(int j=1;j<=h;j++){
    cout<<dis1[i][j]<<" ";
  }
  putchar(10);
  }
  for(int i=1;i<=w;i++){
  for(int j=1;j<=h;j++){
    cout<<dis2[i][j]<<" ";
  }
  putchar(10);
  }*/
  int ans=1e8;
  for(int i=1;i<=w;i++){
    for(int j=1;j<=h;j++)
    if(a[i][j]==4)
    ans=min(ans,dis1[i][j]+dis2[i][j]);
  }
  //a
  printf("%d\n",ans);
  return 0;
}
