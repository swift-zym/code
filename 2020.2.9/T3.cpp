#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
};
struct sta{
  node pla,box;
  int num;
};
int n,m,visa[101][101],visb[101][101],ansa[101][101],ansb[101][101];
int mx[]={1,0,-1,0},my[]={0,1,0,-1};
void bfs(int x,int y){
  memset(visb,0,sizeof(visb));
  memset(ansb,0,sizeof(ansb));
  queue<node>q;
  queue<int>a;
  q.push({x,y});
  a.push(0);
  while(!q.empty()){
    node now=q.front();
    int tmp=a.front();
    a.pop();q.pop();
    visb[now.x][now.y]=1;
    ansb[now.x][now.y]=tmp;
    for(int i=0;i<=3;i++){
      int nx=now.x+mx[i],ny=now.y+my[i];
      if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&visa[nx][ny]!=2&&visb[nx][ny]!=1){
        q.push({nx,ny});
        a.push(tmp+1);
      }
    }
  }
}
int main(){
  scanf("%d%d",&n,&m);
  sta tmp;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    char c=getchar();
    while(c!='S'&&c!='w'&&c!='M'&&c!='P')c=getchar();
    if(c=='S'){
      visa[i][j]=2;
    }
    else if(c=='M'){
      tmp.pla.x=i;
      tmp.pla.y=j;
    }
    else if(c=='P'){
      tmp.box.x=i;
      tmp.box.y=j;
    }
  }
  queue<sta>q;
  tmp.num=0;
  q.push(tmp);
  while(!q.empty()){
    sta now=q.front();
    q.pop();
    visa[now.box.x][now.box.y]=2;
    bfs(now.pla.x,now.pla.y);
    ansa[now.box.x][now.box.y]=now.num;
    cout<<now.pla.x<<" "<<now.pla.y<<endl;
    cout<<now.box.x<<" "<<now.box.y<<endl;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(j!=1)putchar(' ');
      printf("%d",visb[i][j]);
      if(j==m)putchar(10);
    }
    for(int i=0;i<=3;i++){
      int x=now.box.x,y=now.box.y;
      if(x+mx[i]>=1&&x-mx[i]>=1&&x+mx[i]<=n&&x-mx[i]<=n)
      if(y+my[i]>=1&&y-my[i]>=1&&y+my[i]<=m&&y-my[i]<=m)
      if(visa[x+mx[i]][y+my[i]]!=2&&visa[x-mx[i]][y-my[i]]!=2)
      if(visa[x+mx[i]][y+my[i]]!=1&&visb[x-mx[i]][y-my[i]]==1){
        cout<<"mv "<<now.pla.x<<" "<<now.pla.y<<"to"<<x-mx[i]<<" "<<y-my[i]<<"isok"<<endl;
        sta ttmp;
        ttmp.pla.x=x;
        ttmp.pla.y=y;
        ttmp.box.x=x+mx[i];
        ttmp.box.y=y+my[i];
        ttmp.num=tmp.num+ansb[x-mx[i]][y-my[i]]+1;
        q.push(ttmp);
      }
    }
    visa[now.box.x][now.box.y]=1;
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    if(j!=1)putchar(' ');
    printf("%d",visa[i][j]!=1?-1:ansa[i][j]);
    if(j==m)putchar(10);
  }
  return 0;
}
