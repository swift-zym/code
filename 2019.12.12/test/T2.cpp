#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[100001],c[100001],d[100001],a[100001],ff[100001];
int head[100001],nxt[100001],to[100001],cnt,del[100001];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int vis[100001],dfn[100001],low[100001],T,num;
vector<int>v[100001];
stack<int>s;
void tarjan(int now){
  low[now]=dfn[now]=++T;
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
  if(low[now]==dfn[now]){
    int node;
    num++;
    do{
      node=s.top();
      s.pop();
      vis[node]=0;
      v[num].push_back(node);
    }while(node!=now);
  }
}
int ans;
int mxv[100001],idv[100001];
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld%lld%lld",&f[i],&c[i],&d[i],&a[i]);
    //ff[f[i]]=i;
    //add(f[i],i);
    mxv[i]=-1e8;
  }

  for(int i=1;i<=n;i++){
    if(d[f[i]]-c[i]>mxv[f[i]]){
      mxv[f[i]]=d[f[i]]-c[i];
      idv[f[i]]=i;
    }
  }
  for(int i=1;i<=n;i++){
    if(idv[i]){
      add(i,idv[i]);
      ff[i]=idv[i];
    }
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      tarjan(i);
    }
  }
  for(int i=1;i<=num;i++){
    if(v[i].size()==1){
      if(ff[v[i][0]])
      ans+=max((d[v[i][0]]-c[ff[v[i][0]]])*a[v[i][0]],0ll);
    }
    else{
      int mi=1e8,siz=v[i].size(),id;
      for(int j=0;j<siz;j++){
        if(ff[v[i][j]]){
          if((d[v[i][j]]-c[ff[v[i][j]]])<mi){
            id=j;
            mi=(d[v[i][j]]-c[ff[v[i][j]]]);
          }
        }
      }
      for(int j=0;j<siz;j++){
          if(j!=id){
          if(ff[v[i][j]])
          ans+=max((d[v[i][j]]-c[ff[v[i][j]]])*a[v[i][j]],0ll);
          }
          else{
          ans+=max((d[v[i][j]]-c[ff[v[i][j]]])*(max(a[v[i][j]]-1,0ll)),0ll);
          }
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}
/*
5
4 8 7 1
3 2 4 7
4 1 0 0
3 0 6 3
2 7 7 2
*/
