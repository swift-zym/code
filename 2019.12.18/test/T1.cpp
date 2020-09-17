//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
int n,m,cnt,ans;
int vis[100001],head[100001],nxt[400001],to[400001];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void dfs(int now){
  vis[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(!vis[to[i]]){
      dfs(to[i]);
    }
  }
}
int main(){
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++){
     int a,b;
     scanf("%d%d",&a,&b);
     add(a,b);
     add(b,a);
   }
   for(int i=1;i<=n;i++){
     if(!vis[i]){
       ans++;
       dfs(i);
     }
   }
   printf("%d\n",m-n+ans);
  return 0;
}
