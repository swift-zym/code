#include<bits/stdc++.h>
using namespace std;
int head[1001],nxt[1000001],to[1000001],cnt;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int T,vis[1001],bel[1001],dfn[1001],low[1001],num,in[1001];
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
    for(int j=1;j<=n;j++){
      int a;
      scanf("%d",&a);
      if(a){
        add(i,j);
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i);
    }
  }
  if(num==1){
    printf("1\n");
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=head[i];j;j=nxt[j]){
      if(bel[i]==bel[to[j]])continue;
      in[bel[to[j]]]++;
    }
  }
  int a=0;
  for(int i=1;i<=num;i++){
    if(in[i]==0)a++;
  }
  printf("%d\n",a);
  return 0;
}
