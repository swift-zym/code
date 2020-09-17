#include<bits/stdc++.h>
#define n 9
using namespace std;
int bel[10][10]={{0,0,0,0,0,0,0,0,0,0},
                 {0,1,1,1,2,2,2,3,3,3},
                 {0,1,1,1,2,2,2,3,3,3},
                 {0,1,1,1,2,2,2,3,3,3},
                 {0,4,4,4,5,5,5,6,6,6},
                 {0,4,4,4,5,5,5,6,6,6},
                 {0,4,4,4,5,5,5,6,6,6},
                 {0,7,7,7,8,8,8,9,9,9},
                 {0,7,7,7,8,8,8,9,9,9},
                 {0,7,7,7,8,8,8,9,9,9}};
struct node{
  int x,y;
};

int has[10][10][3],a[10][10],vis[10][10];
node decode(int a){
  int x=a/n,y=a%n;
  if(y==0){
    y=n;
  }
  else{
    x++;
  }
  return {x,y};
}

void dfs(int deep){
  if(deep==n*n+1){
    puts("find answer:");
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%d ",a[i][j]);
    }
    putchar(10);
    }
    puts("output:");
    for(int k=1;k<=9;k++){
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++){
      if(bel[i][j]==k&&vis[i][j]==0)putchar('0'+a[i][j]);
    }
    putchar(10);
    }
    exit(0);
  }
  int x=decode(deep).x,y=decode(deep).y;
  if(a[x][y]){
    dfs(deep+1);
    return;
  }
  for(int i=1;i<=9;i++){

    if(has[x][i][0]==0&&has[y][i][1]==0&&has[bel[x][y]][i][2]==0){

      a[x][y]=i;
      has[x][i][0]=1;
      has[y][i][1]=1;
      has[bel[x][y]][i][2]=1;
      dfs(deep+1);
      a[x][y]=0;
      has[x][i][0]=0;
      has[y][i][1]=0;
      has[bel[x][y]][i][2]=0;
    }
  }
}
int main(){
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    scanf("%d",&a[i][j]);
    if(a[i][j]){
      vis[i][j]=1;
      has[i][a[i][j]][0]=1;
      has[j][a[i][j]][1]=1;
      has[bel[i][j]][a[i][j]][2]=1;
    }
  }
  dfs(1);
  return 0;
}
