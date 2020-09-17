#pragma GCC optimize(2)
#include<iostream>
using namespace std;
int n,m,k;
int x[101],y[101],vis[101][101],ans;
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=n;i++)scanf("%d",&x[i]);
  for(int i=1;i<=m;i++)scanf("%d",&y[i]);
  for(int i=1;i<=k;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    vis[a][b]=1;
  }
  bool flag;
  while(1){
    int a1,b1,a2,b2;
    a1=b1=a2=b2=-1;
    flag=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(x[i]>0||y[j]>0)flag=1;
      if(vis[i][j])continue;
      if(x[i]>0&&y[j]>0){
        a2=i;
        b2=j;
      }
      else if(x[i]>0||y[i]>0){
        a1=i;
        b1=j;
      }
    }
    if(a1==-1&&a2==-1)break;
    if(a2!=-1){
      x[a2]--;y[b2]--;
      vis[a2][b2]=1;
    }
    else{
      x[a1]--;y[b1]--;
      vis[a1][b1]=1;
    }
    ans++;
  }
  if(flag){
    puts("No Solution");
  }
  else{
  printf("%d\n",ans);
  }
  return 0;
}
