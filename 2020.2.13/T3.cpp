#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p;
int vis[2001],v[2001],s,tmp[2001][2001];
int head[2001],nxt[4001],to[4001],cnt,ans;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void dfs(int now,int sum,int mx){
  sum+=v[now];
  mx=max(mx,v[now]);
  vis[now]=1;
  if(!tmp[s][now]){
    tmp[s][now]=tmp[now][s]=1;
    if((sum-mx)%p==0){
      ans++;
    }
  }
  for(int i=head[now];i;i=nxt[i]){
    if(!vis[to[i]])dfs(to[i],sum,mx);
  }
}
signed main(){
  scanf("%lld%lld",&n,&p);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%lld%lld",&a,&b);
    add(a,b);
    add(b,a);
  }
  for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
  for(s=1;s<=n;s++){
    memset(vis,0,sizeof(vis));
    dfs(s,0,0);
  }
  printf("%lld\n",ans);
  return 0;
}
