#include<bits/stdc++.h>
using namespace std;
int ma[101][101],bf[101][101],fi[101][101],vis[101];
  int n,m;
void re(){
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    ma[i][j]=bf[i][j];
  }
}
void f(int i){
  for(int j=1;j<=m;j++){
    ma[i][j]=1-ma[i][j];
  }
}
void go(int j){
  for(int i=1;i<=n;i++){
    if(ma[i][j]!=fi[i][1])f(i);
  }
}
bool check(int x){
  memset(vis,0,sizeof(vis));
  vis[x]=1;
  for(int j=2;j<=m;j++){
    bool fl=0;
    for(int k=1;k<=m;k++){
      if(vis[k])continue;
      bool flag=1;
      for(int i=1;i<=n;i++){
        if(fi[i][j]!=ma[i][k]){
          flag=0;
          break;
        }
      }
      if(flag==1){
        vis[k]=1;
        fl=1;
        break;
      }
    }
    if(!fl)return 0;
  }
  return 1;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      scanf("%d",&ma[i][j]);
      bf[i][j]=ma[i][j];
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      scanf("%d",&fi[i][j]);
    }
    bool flag=0;
    for(int j=1;j<=m;j++){
      go(j);
      if(check(j)){
        puts("YES");
        flag=1;
        break;
      }
      re();
    }
    if(!flag){
      puts("NO");
    }
  }
  return 0;
}
