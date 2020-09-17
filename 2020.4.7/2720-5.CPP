#include<bits/stdc++.h>
using namespace std;
int head[2001],nxt[2000001],to[2000001],cnt;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int n,m;
int dfn[2001],low[2001],T;
int bel[2001],num,vis[2001];
stack<int>s;
void tarjan(int now){
  dfn[now]=low[now]=++T;
  s.push(now);
  vis[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(!dfn[to[i]]){
      tarjan(to[i]);
      low[now]=min(low[now],low[to[i]]);
    }
    else if(vis[to[i]]){
      low[now]=min(low[now],dfn[to[i]]);
    }
  }
  vis[now]=0;
  if(dfn[now]==low[now]){
    int tp;
    num++;
    do{
      tp=s.top();
      s.pop();
      vis[tp]=0;
      bel[tp]=num;
    }while(tp!=now);
  }
}
int main(){
  while(scanf("%d%d",&n,&m)!=EOF){
  num=cnt=0;
  memset(head,0,sizeof(head));
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  for(int i=1;i<=m;i++){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a++;b++;
    add(a+c*n,b+(1-d)*n);
    add(b+d*n,a+(1-c)*n);
  }
  for(int i=1;i<=2*n;i++){
    if(!dfn[i])tarjan(i);
  }
  bool flag=1;
  for(int i=1;i<=n;i++){
    if(bel[i]==bel[i+n]){
      puts("NO");
      flag=0;
      break;
    }
  }
  if(flag)
  puts("YES");
  }
  return 0;
}
