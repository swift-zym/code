#include<bits/stdc++.h>
using namespace std;
int head[200001],nxt[1000001],to[1000001],cut[200001],cnt;
int n,m,tim;
void add(int a,int b){
  //cout<<"Add "<<a<<" "<<b<<endl;
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int dfn[200001],low[200001];
int a,b;
void tarjan(int now,int fa){
  //cout<<now<<endl;
  int son=0;
  dfn[now]=low[now]=++tim;
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    if(!dfn[to[i]]){
      son++;
      tarjan(to[i],now);
      low[now]=min(low[now],low[to[i]]);
      if(low[to[i]]>=dfn[now]){
        cut[now]++;
      }
    }
    else{
      low[now]=min(low[now],dfn[to[i]]);
    }
  }
  if(son<=1&&fa==now){
    cut[now]=0;
  }
}
int main(){
  while(scanf("%d%d",&n,&m)){
  if(n==0&&m==0)break;
  memset(head,0,sizeof(head));
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(cut,0,sizeof(cut));
  tim=0;
  cnt=0;
  for(int i=1;i<=m;i++){
    scanf("%d%d",&a,&b);
    a++;b++;
    add(a,b);
    add(b,a);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i,i);
      ans++;
      cut[i]--;
    }
  }
  int tmp=-1e8;
  for(int i=1;i<=n;i++){
    tmp=max(tmp,cut[i]);
  }
  printf("%d\n",ans+tmp);
  }
  return 0;
}
