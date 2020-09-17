#include<bits/stdc++.h>
using namespace std;
int head[101],nxt[10001],to[10001],cnt;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int T,vis[101],bel[101],dfn[101],low[101],num,in[101],out[101];
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
  if(dfn[now]==low[now]){
    ++num;
    int tp;
    do{
      tp=s.top();
      vis[tp]=0;
      bel[tp]=num;
      s.pop();
    }while(tp!=now);
  }
}
int n;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int a;
    while(scanf("%d",&a)){
      if(!a)break;
      add(i,a);
    }
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i);
    }
  }
  if(num==1){
    printf("1\n0\n");
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=head[i];j;j=nxt[j]){
      if(bel[i]==bel[to[j]])continue;
      out[bel[i]]++;
      in[bel[to[j]]]++;
    }
  }
  int a=0,b=0;
  for(int i=1;i<=num;i++){
    if(in[i]==0)a++;
    if(out[i]==0)b++;
  }
  printf("%d\n%d\n",a,max(a,b));
  return 0;
}
