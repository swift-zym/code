#include<bits/stdc++.h>
using namespace std;
int head[300001],nxt[600001],to[600001],cnt,vise[600001],visn[300001],vis[300001],flag;
int n,m,q,s[300001],t[300001];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void dfs(int now){
  vis[now]=visn[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(vise[i])continue;
    vise[i]=vise[i^1]=1;
    if(visn[to[i]]){
      flag=1;
      return;
    }
    dfs(to[i]);
    if(flag)return;
    vise[i]=vise[i^1]=0;
  }
  visn[now]=0;
}
int main(){
  scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&s[i],&t[i]);
  }
  for(int i=1;i<=q;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    cnt=-1;
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(visn,0,sizeof(visn));
    memset(vise,0,sizeof(vise));
    for(int j=l;j<=r;j++){
      add(s[j],t[j]);
      add(t[j],s[j]);
    }
    flag=0;
    for(int j=1;j<=n;j++)
    if(!vis[j]){
      dfs(j);
      if(flag)break;
    }
    if(flag){
      puts(">_<");
    }
    else{
      puts("QAQ");
    }
  }
  return 0;
}
