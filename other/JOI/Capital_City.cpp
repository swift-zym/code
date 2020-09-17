#include<bits/stdc++.h>
using namespace std;
int n,a[100],b[100],c[100],k;
int head[100],nxt[200],to[200],cnt,ans=1e8;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int m[100],vis[100];
void go(int now){
  vis[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(vis[to[i]]==0&&m[c[to[i]]]==1)go(to[i]);
  }
}
void dfs(int deep,int num){

  if(deep==k+1){
    if(!num)return;
    for(int i=1;i<=n;i++){
      if(m[c[i]]){
        memset(vis,0,sizeof(vis));
        go(i);
        for(int j=1;j<=n;j++){
          if(m[c[j]]&&vis[j]==0)return;
        }
      }
    }
    ans=min(ans,num);
    return;
  }
  m[deep]=0;
  dfs(deep+1,num);
  m[deep]=1;
  dfs(deep+1,num+1);
  m[deep]=0;
}
int main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
    add(a[i],b[i]);
    add(b[i],a[i]);
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&c[i]);
  }
  dfs(1,0);
  printf("%d\n",ans-1);
  return 0;
}
