#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int head[100001],nxt[200001],to[200001],len[200001],cnt;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
int siz[100001];
int sum1[100001],sum2[100001];
int tmp[20];
int ans[100001];
int f[100001][20];
void dfs1(int now,int fa){
  siz[now]=1;
  for(int i=1;i<=15;i++)f[now][i]=0;
  f[now][0]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    dfs1(to[i],now);
    siz[now]+=siz[to[i]];
    sum1[now]+=sum1[to[i]]+siz[to[i]]*16*(len[i]/16);
    sum2[to[i]]+=sum1[to[i]]+siz[to[i]]*16*(len[i]/16);
    for(int j=0;j<=15;j++){
      f[now][(j+(len[i]%16))%16]+=f[to[i]][j];
      if(j+(len[i]%16)>=16){
        sum1[now]+=f[to[i]][j]*16;
        sum2[to[i]]+=f[to[i]][j]*16;
      }
    }
  }
}
void dfs2(int now,int fa){
  ans[now]=sum1[now];
  for(int i=0;i<=15;i++){
    ans[now]+=f[now][i]*(i^m);
  }
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    sum1[to[i]]+=(sum1[now]-sum2[to[i]])+(n-siz[to[i]])*16*(len[i]/16);
    memset(tmp,0,sizeof(tmp));
    for(int j=0;j<=15;j++){
      tmp[(j+(len[i]%16))%16]+=f[now][j]-f[to[i]][(j-(len[i]%16)+16)%16];
      if(j+(len[i]%16)>=16){
        sum1[to[i]]+=(f[now][j]-f[to[i]][(j-(len[i]%16)+16)%16])*16;
      }
    }
    for(int j=0;j<=15;j++){
      f[to[i]][j]+=tmp[j];
    }
    dfs2(to[i],now);
  }
}
signed main(){
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<n;i++){
    int a,b,l;
    scanf("%lld%lld%lld",&a,&b,&l);
    add(a,b,l);
    add(b,a,l);
  }
  dfs1(1,0);
  dfs2(1,0);
  for(int i=1;i<=n;i++){
    printf("%lld\n",ans[i]-m);
  }
  return 0;
}
