#include<bits/stdc++.h>
using namespace std;
int head[20000],nxt[40000],to[40000],cnt;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int T,vis[20000],bel[20000],dfn[20000],low[20000],num;
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
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b&1?b+1:b-1);
    add(b,a&1?a+1:a-1);
  }
  for(int i=1;i<=n*2;i++){
    if(!dfn[i])tarjan(i);
  }
  bool flag=0;
  for(int i=1;i<=n*2;i+=2){
      if(bel[i]==bel[i+1]){
          flag=1;
          break;
      }
  }
  if(flag)
  printf("NIE");
  else
  for(int i=1;i<=2*n;i++)if(bel[i]<bel[i&1?i+1:i-1])printf("%d\n",i);
  return 0;
}
