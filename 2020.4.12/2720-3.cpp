#include<bits/stdc++.h>
using namespace std;
int head[201],nxt[2001],to[2001],cnt;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int T,dfn[201],low[201],bel[201],vis[201],num;
stack<int>s;
void tarjan(int now){
  vis[now]=1;
  s.push(now);
  dfn[now]=low[now]=++T;
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
    ++num;
    int tp;
    do{
      tp=s.top();
      s.pop();
      vis[tp]=0;
      bel[tp]=num;
    }while(tp!=now);
  }
}
int main(){
  ios::sync_with_stdio(0);
  int K;
  cin>>K;
  while(K--){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(bel,0,sizeof(bel));
    memset(head,0,sizeof(head));
    cnt=T=num=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
      char c1,c2;
      int a1,a2;
      cin>>c1>>a1>>c2>>a2;
      if(c1=='m'&&c2=='h'){
        add(a1+n,a2+n);
        add(a2,a1);
      }
      else if(c1=='h'&&c2=='m'){
        add(a1,a2);
        add(a2+n,a1+n);
      }
      else if(c1=='h'&&c2=='h'){
        add(a1,a2+n);
        add(a2,a1+n);
      }
      else{
        add(a1+n,a2);
        add(a2+n,a1);
      }
    }
    for(int i=1;i<=2*n;i++){
      if(!dfn[i])tarjan(i);
    }
    string s="GOOD";
    for(int i=1;i<=n;i++){
      if(bel[i]==bel[i+n])s="BAD";
    }
    cout<<s<<endl;
  }
  return 0;
}
