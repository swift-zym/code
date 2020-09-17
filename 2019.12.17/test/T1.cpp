//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
using namespace std;
int vis[100001],n,m,s,t,cnt,head[100001],nxt[200001],len[200001],to[200001],id,ans[100001],pre[100001];
bool c=1;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
struct node{
  int s,v;
  bool operator <(const node &t)const{
    return v>t.v;
  }
};
priority_queue<node>p;
void dij(){
  for(int i=1;i<=n;i++)ans[i]=1e8;
  p.push({t,0});
  ans[t]=0;
  while(!p.empty()){
    node now=p.top();
    p.pop();
    if(now.v!=ans[now.s])continue;
    for(int i=head[now.s];i;i=nxt[i]){
      if(vis[i])continue;
      if(ans[to[i]]>ans[now.s]+len[i]){
        ans[to[i]]=ans[now.s]+len[i];
        if(c)
        pre[to[i]]=now.s;
        p.push({to[i],ans[to[i]]});
      }
    }
  }
}
int turn(int x){
  if(x%2==0)return x-1;
  else return x+1;
}
int main(){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  for(int i=1;i<=m;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    add(a,b,l);
    add(b,a,l);
  }
  dij();
  c=0;
  int now=s,mx=-1;
  do{
    for(int i=head[now];i;i=nxt[i]){
      if(to[i]==pre[now]){
        vis[i]=vis[turn(i)]=1;
        dij();
        vis[i]=vis[turn(i)]=0;
        break;
      }
    }
    mx=max(mx,ans[s]);
    if(mx==1e8)break;
    now=pre[now];
  }while(now!=t);
  if(mx==1e8){
    puts("-1");
  }
  else{
    printf("%d\n",mx);
  }
  return 0;
}
