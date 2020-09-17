#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,p[50001],k[50001],vis[50001];
int tmp[50001],cnt;
int solve(){
  cnt=0;
  for(int i=1;i<=n;i++){
    if(!vis[i])continue;
    if(p[i]>tmp[cnt]){
      tmp[++cnt]=p[i];
    }
    else{
      *lower_bound(tmp+1,tmp+cnt+1,p[i])=p[i];
    }
  }
  return cnt;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&p[i]);
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&k[i]);
  }
  for(int i=1;i<=n;i++){
    vis[k[i]]=1;
    if(i!=1)putchar(' ');
    printf("%d",solve());
  }
  putchar(10);
  return 0;
}
/*
8
7 1 8 3 2 4 6 5
1 7 4 5 8 2 6 3
*/
