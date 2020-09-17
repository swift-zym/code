#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,vis[1000001],dp[1000001][2],ans,fa[1000001],v[1000001];
vector<int>to[1000001];
void dfs(int now,int tmp){
  vis[now]=1;
  dp[now][0]=0;
  dp[now][1]=v[now];
  for(int i=0;i<to[now].size();i++){
    if(to[now][i]==tmp){
      dp[tmp][1]=-1e8;
    }
    else{
      dfs(to[now][i],tmp);
      dp[now][0]+=max(dp[to[now][i]][0],dp[to[now][i]][1]);
      dp[now][1]+=dp[to[now][i]][0];
    }
  }
}
void solve(int now){
  while(!vis[fa[now]]){
    vis[now]=1;
    now=fa[now];
  }
  dfs(now,now);
  int v1=max(dp[now][0],dp[now][1]);
  now=fa[now];
  dfs(now,now);
  int v2=max(dp[now][0],dp[now][1]);
  ans+=max(v1,v2);
}
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    int tmp;
    scanf("%lld%lld",&v[i],&tmp);
    to[tmp].push_back(i);
    fa[i]=tmp;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i])solve(i);
  }
  printf("%lld\n",ans);
  return 0;
}
