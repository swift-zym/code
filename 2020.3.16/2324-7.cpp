#include<bits/stdc++.h>
using namespace std;
int sum[1001],f[1001],vis[10001],du[1001],n,tmp[1001][1001];
int gf(int now){
  if(f[now]==now)return now;
  int fa=gf(f[now]);
  return f[now]=fa;
}
int main(){
  int cf=0;
  for(int i=1;i<=1000;i++)f[i]=i;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    if(tmp[a][b]){
      cf++;
      continue;
    }
    du[a]++;du[b]--;
    vis[a]=vis[b]=1;
    f[gf(a)]=gf(b);
  }
  for(int i=1;i<=1000;i++){
    if(vis[i]){
      sum[gf(i)]+=abs(du[i]);
    }
  }
  int ans=0;
  for(int i=1;i<=1000;i++){
    if(vis[i]&&f[i]==i){
      ans+=max(0,(sum[i]-2)/2);
      ans++;
    }
  }
  printf("%d\n",n+1+ans-1-cf);
  return 0;
}
