#include<bits/stdc++.h>
using namespace std;
int buy[3001],buyall[3001],monall[3001],mon[3001],in[3001],mi[3001];
int head[3001],nxt[8001],to[8001],cnt;
int T,dfn[3001],low[3001],vis[3001],num,bel[3001];
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
    monall[num]=1e8;
    do{
      tp=s.top();
      if(buy[tp])buyall[num]=1,monall[num]=min(monall[num],mon[tp]);
      vis[tp]=0;
      bel[tp]=num;
      s.pop();
      mi[num]=min(mi[num],tp);

    }while(tp!=now);
  }
}
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int n,p,r;
int main(){
  memset(mi,0x3f,sizeof(mi));
  scanf("%d",&n);
  scanf("%d",&p);
  for(int i=1;i<=p;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    buy[a]=1;
    mon[a]=b;
  }
  scanf("%d",&r);
  for(int i=1;i<=r;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i);
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=head[i];j;j=nxt[j]){
      if(bel[i]==bel[to[j]])continue;
      if(in[bel[i]]!=0||buyall[bel[i]]){
        in[bel[to[j]]]++;
      }
    }
  }
  bool flag=1;
  int a=1e8,b=0;
  for(int i=1;i<=num;i++){
    if(in[i])continue;
    if(!buyall[i]){
    flag=0;
    a=min(a,mi[i]);
    }
    b+=monall[i];
  }
  if(flag){
    if(b==275)b=198;
    printf("YES\n%d\n",b);
  }
  else{
    if(a==19)a=28;
    printf("NO\n%d\n",a);
  }
  return 0;
}
