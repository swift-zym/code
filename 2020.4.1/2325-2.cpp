#include<bits/stdc++.h>
using namespace std;
int head[101],nxt[10001],to[10001],cnt;
int n,ans,tim;
void add(int a,int b){
  //cout<<"Add "<<a<<" "<<b<<endl;
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int dfn[101],low[101];
void tarjan(int now,int fa){
  dfn[now]=low[now]=++tim;
  int son=0;
  int flag=0;
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    if(!dfn[to[i]]){
      tarjan(to[i],now);
      son++;
      low[now]=min(low[now],low[to[i]]);
      if(low[to[i]]>=dfn[now]){
        flag=1;
      }
    }
    else{
      low[now]=min(low[now],dfn[to[i]]);
    }
  }
  if(fa==now&&son<=1)flag=0;
  ans+=flag;
}
int main(){
  while(scanf("%d",&n)){
  if(n==0)break;
  tim=0;
  cnt=0;
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(head,0,sizeof(head));
  int id;
  while(scanf("%d",&id)){
  if(id==0)break;
  int tmp;
  while(1){
    char c=getchar();
    if(c=='\n')break;
    scanf("%d",&tmp);
    add(id,tmp);
    add(tmp,id);
  }
  }
  ans=0;
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i,i);
    }
  }
  printf("%d\n",ans);
  }
  return 0;
}
