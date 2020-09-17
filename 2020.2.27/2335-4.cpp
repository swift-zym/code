#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
};
int r,c;
node nxt[51][51][4];
int b[51][51];
string s;
char a[51][51];
struct now{
  int x,y,now,ans;
};
int main(){
  ios::sync_with_stdio(0);
  while(cin>>r>>c){
  if(r==0&&c==0)break;
  memset(nxt,0,sizeof(nxt));
  for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++){
    cin>>a[i][j];
  }
  cin>>s;
  s+="*";
  for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++){
    for(int ii=i-1;ii>=1;ii--){
      if(a[ii][j]!=a[i][j]){
        nxt[i][j][0]={ii,j};
        break;
      }
    }
    for(int ii=i+1;ii<=r;ii++){
      if(a[ii][j]!=a[i][j]){
        nxt[i][j][1]={ii,j};
        break;
      }
    }
    for(int jj=j-1;jj>=1;jj--){
      if(a[i][jj]!=a[i][j]){
        nxt[i][j][2]={i,jj};
        break;
      }
    }
    for(int jj=j+1;jj<=c;jj++){
      if(a[i][jj]!=a[i][j]){
        nxt[i][j][3]={i,jj};
        break;
      }
    }
  }
  queue<now>q;
  memset(b,-1,sizeof(b));
  q.push({1,1,0,0});
  int len=s.length();
  while(!q.empty()){
    now tmp=q.front();
  //  cout<<tmp.x<<" "<<tmp.y<<endl;
    b[tmp.x][tmp.y]=tmp.now;
    q.pop();
    if(s[tmp.now]==a[tmp.x][tmp.y]){
      tmp.now++;
      tmp.ans++;
      q.push(tmp);
      continue;
    }
    //b[tmp.x][tmp.y]=tmp.now;
    if(tmp.now==len){
      printf("%d\n",tmp.ans);
      return 0;
    }
    for(int i=0;i<=3;i++){
      if(nxt[tmp.x][tmp.y][i].x!=0&&nxt[tmp.x][tmp.y][i].y!=0&&b[nxt[tmp.x][tmp.y][i].x][nxt[tmp.x][tmp.y][i].y]<tmp.now){
        b[nxt[tmp.x][tmp.y][i].x][nxt[tmp.x][tmp.y][i].y]=tmp.now;
        q.push({nxt[tmp.x][tmp.y][i].x,nxt[tmp.x][tmp.y][i].y,tmp.now,tmp.ans+1});
      }
    }
  }
  }
  return 0;
}
