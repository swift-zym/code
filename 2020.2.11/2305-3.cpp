#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],b[15],sg[1005],vis[1005];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  scanf("%d",&m);
  for(int i=1;i<=m;i++)scanf("%d",&b[i]);
  for(int i=1;i<=1000;i++){
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
  int ans=0;
  for(int i=1;i<=n;i++)ans^=sg[a[i]];
  if(!ans){
    puts("NO");
  }
  else{
    puts("YES");
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(a[i]-b[j]>=0){
        if((ans^sg[a[i]]^sg[a[i]-b[j]])==0){
          printf("%d %d\n",i,b[j]);
          return 0;
        }
      }
    }
  }
  return 0;
}
