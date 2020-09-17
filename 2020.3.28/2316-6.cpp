#include<bits/stdc++.h>
using namespace std;
int n;
int head[200001],nxt[400001],to[400001],cnt;
int max_v[200001],max_id[200001],maxx_v[200001],maxx_id[200001],tmp[200001];
int ans;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
int dfs1(int now,int fa){
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    int v=dfs1(to[i],now)+1;
    if(v>max_v[now]){
      maxx_v[now]=max_v[now];
      maxx_id[now]=max_id[now];
      max_v[now]=v;
      max_id[now]=to[i];
    }
    else if(v>maxx_v[now]){
      maxx_v[now]=v;
      maxx_id[now]=to[i];
    }
  }
  //atom-luogu-enable-O2
  ans=max(ans,max_v[now]+maxx_v[now]);
  return max_v[now];
}
void dfs2(int now,int fa){
  if(now){
    if(now!=max_id[fa]){
      tmp[now]=max(tmp[fa]+1,max_v[fa]+1);
    }
    else{
      tmp[now]=max(tmp[fa]+1,maxx_v[fa]+1);
    }
  }
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    dfs2(to[i],now);
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
  dfs1(0,0);
  dfs2(0,0);
  for(int i=0;i<n;i++){
    if(tmp[i]+max_v[i]==ans||max_v[i]+maxx_v[i]==ans){
      printf("%d\n",i);
    }
  }
  return 0;
}
