#include<bits/stdc++.h>
using namespace std;
int sg[101][100001],cnt;
int dfs(int a,int b){
  if(a==0)return b&1;
  if(b==1)return dfs(a+1,0);
  if(sg[a][b]!=-1)return sg[a][b];
  if(a&&dfs(a-1,b)==0)return sg[a][b]=1;
  if(a&&b&&dfs(a-1,b+1)==0)return sg[a][b]=1;
  if(a>1&&dfs(a-2,b+2+(b?1:0))==0)return sg[a][b]=1;
  if(b&&dfs(a,b-1)==0)return sg[a][b]=1;
  return sg[a][b]=0;
}
int main(){
  memset(sg,-1,sizeof(sg));
  int T;
  scanf("%d",&T);
  while(T--){
    int a=0,b=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      int c;
      scanf("%d",&c);
      if(c==1)a++;
      else{
        b+=c+(b?1:0);
      }
    }
    puts(dfs(a,b)?"YES":"NO");
  }
  return 0;
}
