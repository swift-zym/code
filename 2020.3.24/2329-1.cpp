#include<bits/stdc++.h>
using namespace std;
int vis[20][20][3000],key[20][20],go[20][20][20][20];
int n,m,p,k,s;
struct node{
  int x,y,ans,sta;
};
int mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
int main(){
  scanf("%d%d%d",&n,&m,&p);
  scanf("%d",&k);
  for(int i=1;i<=k;i++){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    go[a][b][c][d]=(1<<e);
    go[c][d][a][b]=(1<<e);
  }
  scanf("%d",&s);
  for(int i=1;i<=s;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    key[a][b]|=(1<<c);
  }
  queue<node>q;
  q.push({1,1,0,key[1][1]});
  vis[1][1][key[1][1]]=1;
  while(!q.empty()){
    node now=q.front();
    q.pop();
    if(now.x==n&&now.y==m){
      printf("%d\n",now.ans);
      return 0;
    }
    for(int i=0;i<=3;i++){
      int nx=now.x+mx[i],ny=now.y+my[i];
      if(nx<1||nx>n||ny<1||ny>m)continue;
      if(vis[nx][ny][now.sta|key[nx][ny]])continue;
      if((now.sta|go[now.x][now.y][nx][ny])!=now.sta)continue;
      vis[nx][ny][now.sta|key[nx][ny]]=1;
      q.push({nx,ny,now.ans+1,now.sta|key[nx][ny]});
    }
  }
  puts("-1");
  return 0;
}
