#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[100001],nxt[200001],to[200001],len[200001],cut[200001],vis[200001],n,k,cnt,ans=1e18,du[100001],apple[100001];
vector<int>has;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
void work(int now){
  vis[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(cut[i])continue;
    if(!vis[to[i]])work(to[i]);
  }
}
void dfs(int deep,int tmp){
  if(deep==cnt+1){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<has.size();i++){
      if(vis[has[i]])return;
      work(has[i]);
    }
    ans=min(ans,tmp);
    return;
  }
  cut[deep]=0;
  dfs(deep+1,tmp);
  cut[deep]=1;
  dfs(deep+1,tmp+len[deep]);
}
void solve(int now,int mi,int pre=0){
  if(apple[now]&&pre!=0){
    ans+=mi;
    mi=1e8;
  }
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==pre)continue;
    solve(to[i],min(mi,len[i]),now);
  }
}
signed main(){
  scanf("%lld%lld",&n,&k);
  for(int i=1;i<n;i++){
    int a,b,l;
    scanf("%lld%lld%lld",&a,&b,&l);
    add(a,b,l);
    add(b,a,l);
    du[a]++;
    du[b]++;
  }
  for(int i=1;i<=k;i++){
    int a;
    scanf("%lld",&a);
    has.push_back(a);
    apple[a]=1;
  }
  if(n<=20){
  dfs(1,0);
  printf("%lld\n",ans);
  }
  else{
  int id,mi=1e18;
  for(int i=1;i<=n;i++){
    if(du[i]==1){
      ans=0;
      solve(i,1e8);
      mi=min(mi,ans);
    }
  }
  printf("%lld\n",mi);
  }
  return 0;
}
