#include<bits/stdc++.h>
using namespace std;
struct G{
  int head[500001],nxt[500001],to[500001],cnt;
  void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
  }
}g1,g2;
int T,dfn[500001],bel[500001],low[500001],vis[500001],num,bar[500001],barall[500001],mon[500001],monall[500001];
stack<int>ss;
void tarjan(int now){
  dfn[now]=low[now]=++T;
  ss.push(now);
  vis[now]=1;
  for(int i=g1.head[now];i;i=g1.nxt[i]){
    if(!dfn[g1.to[i]]){
      tarjan(g1.to[i]);
      low[now]=min(low[now],low[g1.to[i]]);
    }
    else if(vis[g1.to[i]]){
      low[now]=min(low[now],dfn[g1.to[i]]);
    }
  }
  if(dfn[now]==low[now]){
    ++num;
    int tp;
    do{
      tp=ss.top();
      vis[tp]=0;
      bel[tp]=num;
      if(bar[tp])barall[num]=1;
      monall[num]+=mon[tp];
      ss.pop();
    }while(tp!=now);
  }
}
int n,m,s,p,du[500001],dp[500001];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    g1.add(a,b);
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&mon[i]);
  }
  scanf("%d%d",&s,&p);
  for(int i=1;i<=p;i++){
    int a;
    scanf("%d",&a);
    bar[a]=1;
  }
  tarjan(s);
  for(int i=1;i<=n;i++){
    if(!dfn[i])continue;
    for(int j=g1.head[i];j;j=g1.nxt[j]){
      if(!dfn[g1.to[j]])continue;
      if(bel[i]==bel[g1.to[j]])continue;
      g2.add(bel[i],bel[g1.to[j]]);
      du[bel[g1.to[j]]]++;
    }
  }
  queue<int>q;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=num;i++){
    if(!du[i]){
      dp[i]=monall[i];
      vis[i]=1;
      q.push(i);
    }
  }
  while(!q.empty()){
    int now=q.front();q.pop();
    for(int i=g2.head[now];i;i=g2.nxt[i]){
      du[g2.to[i]]--;
      dp[g2.to[i]]=max(dp[g2.to[i]],dp[now]+monall[g2.to[i]]);
      if(bar[now])
      bar[g2.to[i]]=1;
    }
    for(int i=1;i<=num;i++){
      if(!vis[i]){
        if(!du[i]){
          vis[i]=1;
          q.push(i);
        }
      }
    }
  }
  int ans=0;
  for(int i=1;i<=num;i++){
    if(barall[i])ans=max(ans,dp[i]);
  }
  printf("%d\n",ans);
  return 0;
}
