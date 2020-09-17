#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],sg[10005],vis[10005];
int main(){
  while(scanf("%d",&m)!=EOF){
  if(!m)break;
  for(int i=1;i<=m;i++)scanf("%d",&b[i]);
  for(int i=1;i<=10000;i++){
    memset(vis,0,sizeof(vis));
    int mx=0;
    for(int j=1;j<=m;j++){
      if(i-b[j]>=0)vis[sg[i-b[j]]]=1,mx=max(mx,sg[i-b[j]]);
    }
    for(int j=0;j<=mx+1;j++){
      if(!vis[j]){
        sg[i]=j;
        break;
      }
    }
  }
  int T;
  scanf("%d",&T);
  while(T--){
  int ans=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans^=sg[a[i]];
  if(!ans){
    putchar('L');
  }
  else{
    putchar('W');
  }
  }
  putchar(10);
  }
  return 0;
}
