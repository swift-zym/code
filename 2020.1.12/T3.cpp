//Copyright (c) 2020 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
#define int long long
using namespace std;
int Num,n,m,head[200001],nxt[1000001],to[1000001],len[1000001],cnt,vis[200001],ans[200001];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
signed main(){
  scanf("%lld",&Num);
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b,l;
    scanf("%lld%lld%lld",&a,&b,&l);
    if(a==b)continue;
    add(a,b,l);
    add(b,a,l);
  }
  queue<int>q;
  q.push(1);
  memset(ans,0x3f,sizeof(ans));
  ans[1]=0;
  while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
      if(ans[to[i]]>ans[now]+len[i]){
        ans[to[i]]=ans[now]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(i==1){
      printf("0");
      continue;
    }
    int mi=1e12,id;
    for(int j=head[i];j;j=nxt[j]){
      if(ans[to[j]]+len[j]<mi){
        mi=ans[to[j]]+len[j];
        id=j;
      }
    }
    mi=1e12;
    int idd,tmp;
    for(int j=head[i];j;j=nxt[j]){
      if(ans[to[j]]!=ans[i]+len[j]&&j!=id&&ans[to[j]]+len[j]<mi){
        mi=ans[to[j]]+len[j];
        idd=j;
        tmp=ans[to[j]]+len[j];
      }
    }
    putchar(' ');
    if(mi==1e12){
      printf("-1");
    }
    else{
      printf("%lld",tmp);
    }
  }
  putchar(10);
  return 0;
}
