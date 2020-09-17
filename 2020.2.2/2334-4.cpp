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
#define bas 23333
#define MOD 1000000007
int n,q,tmp[510000],has[510000],opt,flag,sum[510000][26];
char u[510000];
inline int solve(int l,int r){
  if(l>r)return 0;
  return (has[r]-tmp[r-l+1]*has[l-1]%MOD+MOD)%MOD;
}
template <typename T> inline void read(T &a) {
    a = 0;char c = getchar();int f = 1;
    while(!isdigit(c)) {if(c == '-') f = -1;c = getchar();}
    while(isdigit(c)) {a = (a << 3) + (a << 1) + (c ^ 48);c = getchar();}
    a *= f;
}
inline void pre(){
  tmp[0]=1;
  for(int i=1;i<=n;i++)tmp[i]=(tmp[i-1]*bas)%MOD;
  for(int i=1;i<=n;i++){
    has[i]=((has[i-1]*bas)%MOD+u[i-1])%MOD;
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=25;j++){
      sum[i][j]=sum[i-1][j]+(u[i-1]-'a'==j);
    }
  }
}
int ans;
inline void check(int l,int r,int x){
  if(solve(l,r-x)==solve(l+x,r))
  ans=min(ans,x);
}
inline int num(int l,int r,int c){
  return sum[r][c]-sum[l-1][c];
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
inline void work(int a,int b){
  ans=1e8;int vgcd=b-a+1;
  for(int i=0;i<=25;i++){
    vgcd=gcd(vgcd,num(a,b,i));
  }
  for(int i=1;i*i<=vgcd;i++){
    if(vgcd%i)continue;
    check(a,b,(b-a+1)/(vgcd/i));
    if(ans!=1e8){
      printf("%lld\n",ans);
      return;
    }
  }
  for(int i=1;i*i<=vgcd;i++){
    if(vgcd%i)continue;
    check(a,b,(b-a+1)/i);
  }
  printf("%lld\n",ans);
}
signed main(){
  read(n);
  scanf("%s",u);
  pre();
  read(q);
  for(int i=1;i<=q;i++){
    int a,b;
    read(a);read(b);
    work(a,b);
  }
  return 0;
}
