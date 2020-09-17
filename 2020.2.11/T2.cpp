#include<bits/stdc++.h>
using namespace std;
int n,m,ok[101][101],D;
int vis[101],a[101],ans;
void dfs(int deep){
  if(deep==m+1){
    for(int i=1;i<=m;i++)
    for(int j=i+1;j<=m;j++){
      if(ok[i][j]==0&&abs(a[i]-a[j])<=D)return;
      if(ok[i][j]==1&&abs(a[i]-a[j])>D)return;
      ans%=1000000007;
    }
    ans++;
    return;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      a[deep]=i;
      vis[i]=1;
      dfs(deep+1);
      vis[i]=0;
    }
  }
}
int main(){
  scanf("%d",&n);
  scanf("%d",&D);
  scanf("%d",&m);
  for(int i=1;i<=m;i++)
  for(int j=1;j<=m;j++){
    char c=getchar();
    while(c!='Y'&&c!='N')c=getchar();
    ok[i][j]=(c=='Y');
  }
  dfs(1);
  printf("%d\n",ans);
  return 0;
}
//<del>do something...</del>
