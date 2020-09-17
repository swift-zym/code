//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
using namespace std;
int T,n,a[100001],mx,head[100001],nxt[200001],to[200001],cnt,num,siz[100001],vis[100001],tmp[100001],bfs[100001];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void dfs(int now){
  siz[num]++;
  vis[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(!vis[to[i]]){
      dfs(to[i]);
    }
  }
}
bool cmp(int a,int b){
  return a>b;
}
int main(){
  scanf("%d",&T);
  while(T--){
    num=0;
    cnt=0;
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(siz,0,sizeof(siz));
    mx=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)tmp[i]=1;
    int nz,last=-1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)add(i,a[i]),add(a[i],i);
    for(int i=1;i<=n;i++){
      if(!vis[i]){
        num++;
        dfs(i);
      }
    }
    for(;;){
      for(int i=1;i<=n;i++){
        bfs[i]=tmp[i];
      }
      nz=0;
      for(int i=1;i<=n;i++){
        tmp[i]-=bfs[i];
        tmp[a[i]]+=bfs[i];
      }
      for(int i=1;i<=n;i++){
        nz+=(tmp[i]!=0);
      }
      if(nz==last)break;
      last=nz;
    }
    mx=-1;
    for(int i=1;i<=n;i++){
      mx=max(mx,tmp[i]);
    }
    bool flag=0;
    for(int i=1;i<=n;i++)if(a[i]==i)flag=1;
    printf("%d\n",num-flag);
    if(!(num==1&&siz[1]==1))
    printf("%d ",mx);
    else{
    printf("%d\n",mx);
    continue;
    }
    sort(siz+1,siz+num+1,cmp);
    if(flag){
      int ans=siz[1]+1;
      printf("%d",ans);
      for(int i=2;i<num;i++){
        ans+=siz[i];
        putchar(' ');
        printf("%d",ans);
      }
      putchar(10);
    }
    else{
      int ans=siz[1];
      printf("%d",ans);
      for(int i=2;i<=num;i++){
        ans+=siz[i];
        putchar(' ');
        printf("%d",ans);
      }
      putchar(10);
    }
  }
  return 0;
}
