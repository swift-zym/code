#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[100001],nxt[100001],to[100001],cnt,cas;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int T,dfn[100001],low[100001],is[100001],vis[100001];
void tarjan(int now,int f){
  int flag=0,num=0;
  low[now]=dfn[now]=++T;
  for(int i=head[now];i;i=nxt[i]){
    if(!dfn[to[i]]){
      tarjan(to[i],now);
      low[now]=min(low[now],low[to[i]]);
      if(low[to[i]]>=dfn[now]){
        flag=1;
        num++;
      }
    }
    else if(to[i]!=f){
      low[now]=min(low[now],dfn[to[i]]);
    }
  }
  if((now==f&&num>=2)||(now!=f&&flag)){
    is[now]=1;
  }
}
int num1,num2,bel;
void dfs(int now){
  vis[now]=bel;
  num1++;
  for(int i=head[now];i;i=nxt[i]){
    if(is[to[i]]&&vis[to[i]]!=bel){
      vis[to[i]]=bel;
      num2++;
    }
    if(!vis[to[i]]){
      dfs(to[i]);
    }
  }
}
void clear(){
  memset(is,0,sizeof(is));
  memset(dfn,0,sizeof(dfn));
  cnt=0;
  bel=0;
  memset(head,0,sizeof(head));
  memset(low,0,sizeof(low));
  memset(vis,0,sizeof(vis));
}
signed main(){
  int n,m;
  while(scanf("%lld",&m)!=EOF){
    if(!m)break;
    clear();
    n=0;
    for(int i=1;i<=m;i++){
      int a,b;
      scanf("%lld%lld",&a,&b);
      add(a,b);
      add(b,a);
      n=max(n,max(a,b));
    }
    for(int i=1;i<=n;i++){
      if(!dfn[i]){
        tarjan(i,i);
      }
    }
    int ans1=0,ans2=1;
    for(int i=1;i<=n;i++){
      if(vis[i]==0&&is[i]==0){
        bel++;
        num1=num2=0;
        dfs(i);
        if(num2==0){
          ans1+=2;
          ans2*=(num1-1)*num1/2;
        }
        if(num2==1){
          ans1++;
          ans2*=num1;
        }
      }
    }
    printf("Case %lld: %lld %lld\n",++cas,ans1,ans2);
  }
  return 0;
}
