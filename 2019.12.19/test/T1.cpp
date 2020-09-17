//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
using namespace std;
int n,num[300001],head[300001],nxt[600001],to[600001],cnt,dep[300001];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
vector<int>ans;
void dfs1(int now,int fa,int deep){
  dep[now]=deep;
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    dfs1(to[i],now,deep+1);
  }
}
void dfs2(int now,int fa){
  if(dep[now]%2){
    ans.push_back(now);
    for(int i=head[now];i;i=nxt[i]){
      if(to[i]==fa)continue;
      dfs2(to[i],now);
    }
  }
  else{
    for(int i=head[now];i;i=nxt[i]){
      if(to[i]==fa)continue;
      dfs2(to[i],now);
    }
    ans.push_back(now);
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
    add(b,a);
  }
  dfs1(1,1,1);
  dfs2(1,1);
  int siz=ans.size();
  puts("Yes");
  for(int i=0;i<siz;i++){
    if(i)putchar(' ');
    printf("%d",ans[i]);
  }
  putchar(10);
  return 0;
}
