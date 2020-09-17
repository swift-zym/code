#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
  int l,r,v,vis;
  bool operator <(const edge &t)const{
    return v<t.v;
  }
}a[300001];
int n,m,fa[100001],sum;
int gf(int now){
  if(fa[now]==now)return now;
  int f=gf(fa[now]);
  return fa[now]=f;
}
int head[100001],to[200001],nxt[200001],len[200001],cnt,dep[100001];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
int chkmin(int &a,int b){return a>b?a=b,1:0;}
int chkmax(int &a,int b){return a<b?a=b,1:0;}
void check(int &mx1,int &mx2,int mxx1,int mxx2){
    int nm=max(mx1,mxx1),inm=0;
    if(mx1==nm)chkmax(inm,mx2);
    else chkmax(inm,mx1);
    if(mxx1==nm)chkmax(inm,mxx2);
    else chkmax(inm,mxx1);
    mx1=nm;
    mx2=inm;
}
int f[100001][21],mx1[100001][21],mx2[100001][21];
void dfs(int now,int fat){
  f[now][0]=fat;
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fat){
      mx1[now][0]=len[i];
      continue;
    }
    dep[to[i]]=dep[now]+1;
    dfs(to[i],now);
  }
}
int lca(int a,int b,int c){
  int max1=0,max2=0;
  if(dep[a]<dep[b])swap(a,b);
  for(int i=20;i>=0;i--){
    if(dep[f[a][i]]>=dep[b]){
      check(max1,max2,mx1[a][i],mx2[a][i]);
      a=f[a][i];
    }
  }
  for(int i=20;i>=0;i--){
    if(f[a][i]!=f[b][i]){
      check(max1,max2,mx1[a][i],mx2[a][i]);
      check(max1,max2,mx1[b][i],mx2[b][i]);
      a=f[a][i];
      b=f[b][i];
    }
  }
  if(a!=b){
    check(max1,max2,mx1[a][0],mx2[a][0]);
    check(max1,max2,mx1[b][0],mx2[b][0]);
    a=f[a][0];
    b=f[b][0];
  }
  if(max1==c){
    if(max2){
      return c-max2;
    }
    else{
      return 0x3f3f3f3f3f3f3f3f;
    }
  }
  else{
    return c-max1;
  }
}
signed main(){
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=m;i++){
    scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].v);
  }
  sort(a+1,a+m+1);
  for(int i=1,j=0;i<=m&&j<n-1;i++){
    int af=gf(a[i].l),bf=gf(a[i].r);
    if(af!=bf){
      add(a[i].l,a[i].r,a[i].v);
      add(a[i].r,a[i].l,a[i].v);
      fa[af]=bf;
      sum+=a[i].v;
      j++;
      a[i].vis=1;
    }
  }
  dfs(1,1);
  for(int j=1;j<=20;j++)
  for(int i=1;i<=n;i++){
    f[i][j]=f[f[i][j-1]][j-1];
    mx1[i][j]=mx1[i][j-1];
    mx2[i][j]=mx2[i][j-1];
    check(mx1[i][j],mx2[i][j],mx1[f[i][j-1]][j-1],mx2[f[i][j-1]][j-1]);
  }
  int ans=0x3f3f3f3f3f3f3f3f;
  for(int i=1;i<=m;i++){
    if(!a[i].vis)
    chkmin(ans,sum+lca(a[i].l,a[i].r,a[i].v));
  }
  printf("%lld\n",ans);
  return 0;
}
