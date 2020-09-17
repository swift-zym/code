#include<bits/stdc++.h>
using namespace std;
int n,m,head[5001],to[20001],nxt[20001],cnt=-1;
int dfn[5001],low[5001],num;
int bel[5001];
int T;
stack<int>s;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void tarjan(int now,int fa){
  low[now]=dfn[now]=++T;
  s.push(now);
  for(int i=head[now];i!=-1;i=nxt[i]){
    if(i==(fa^1))continue;
    if(!dfn[to[i]]){
      tarjan(to[i],i);
      low[now]=min(low[now],low[to[i]]);
    }
    else{
      low[now]=min(low[now],dfn[to[i]]);
    }
  }
  if(low[now]==dfn[now]){
    int tp;
    num++;
    do{
      tp=s.top();
      s.pop();
      bel[tp]=num;
    }while(tp!=now);
  }
}
int du[5001];
int main(){
  memset(head,-1,sizeof(head));
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
    add(b,a);
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i,-1);
    }
    //cout<<bel[i]<<endl;
  }
  for(int i=1;i<=n;i++){
    for(int j=head[i];j!=-1;j=nxt[j]){
      if(to[j]<i)continue;
      if(bel[i]!=bel[to[j]]){
        du[bel[i]]++;
        du[bel[to[j]]]++;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=num;i++){
    if(du[i]==1)ans++;
     //cout<<i<<" "<<du[i]<<endl;
  }
  printf("%d\n",(ans+1)/2);
  return 0;
}
