#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y,ans;
};
int mx[]={1,1,-1,-1,2,2,-2,-2},my[]={2,-2,2,-2,1,-1,1,-1};
int vis[310][310];
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    memset(vis,0,sizeof(vis));
    int n;
    scanf("%d",&n);
    n++;
    int sx,sy,ex,ey;
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&ex,&ey);
    queue<node>q;
    sx++;sy++;
    ex++;ey++;
    q.push({sx,sy,0});
    vis[sx][sy]=1;
    while(!q.empty()){
      node now=q.front();
      q.pop();
      if(now.x==ex&&now.y==ey){
        printf("%d\n",now.ans);
        break;
      }
      for(int i=0;i<=7;i++){
        int nx=now.x+mx[i],ny=now.y+my[i];
        if(nx<1||ny<1||nx>n||ny>n)continue;
        if(!vis[nx][ny]){
          vis[nx][ny]=1;
          q.push({nx,ny,now.ans+1});
        }
      }
    }
  }
  return 0;
}
