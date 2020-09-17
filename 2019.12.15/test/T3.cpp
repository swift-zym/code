//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
int n,m,k,head[100001],nxt[200001],to[100001],cnt,lastans,siz[100001],num[100001];
double alpha;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
bool flag;
void dfs(int now,int fa){
  siz[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    dfs(to[i],now);
    siz[now]+=siz[to[i]];
    num[now]++;
  }
}
void dfs1(int now,int fa){
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    dfs1(to[i],now);
    if(!flag)return;
    if(num[now]>=2){
      if(double(siz[to[i]])-double(siz[now])*alpha>eps){

        flag=0;
        return;
      }
    }
  }
}
bool solve(int now){
  memset(num,0,sizeof(num));
  flag=1;
  dfs(now,now);
  dfs1(now,now);
  return flag;
}
int main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
    add(b,a);
  }
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a=(a^(lastans*k));
    b=(b^(lastans*k));
    alpha=double(a)/double(b);
    if(n>=500000)
    int ans=0;
    for(int j=1;j<=n;j++){
      //cout<<j<<" "<<solve(j)<<endl;
      if(solve(j))ans++;
    }
    printf("%d\n",ans);
  }

  return 0;
}
