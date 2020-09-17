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
using namespace std;
struct trie{
  int son[2];
}tr[16000000];
int cnt=1;
void ins(int a){
  vector<int>v;
  while(a){
    v.push_back(a%2);
    a/=2;
  }
  while(v.size()!=32)v.push_back(0);
  int now=1;
  for(int i=v.size()-1;i>=0;i--){
    if(tr[now].son[v[i]]){
      now=tr[now].son[v[i]];
    }
    else{
      tr[now].son[v[i]]=++cnt;
      now=tr[now].son[v[i]];
    }
  }
}
void clear(){
  memset(tr,0,sizeof(tr));
}
int solve(int a){
  vector<int>v;
  while(a){
    v.push_back(a%2);
    a/=2;
  }
  while(v.size()!=32)v.push_back(0);
  int now=1,ans=0;
  for(int i=v.size()-1;i>=0;i--){
    if(tr[now].son[1-v[i]]){
      ans+=1<<i;
      now=tr[now].son[1-v[i]];
    }
    else{
      now=tr[now].son[v[i]];
    }
  }
  return ans;
}
int n,a[400001],tmp[410000],l[400001],r[410000];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]),tmp[i]=(tmp[i-1]^a[i]);
  ins(0);
  for(int i=1;i<=n;i++){
    ins(tmp[i]);
    l[i]=max(l[i-1],solve(tmp[i]));
  }
  memset(tmp,0,sizeof(tmp));
  clear();
  ins(0);
  for(int i=n;i>=1;i--){
    ins(tmp[i]);
    tmp[i]=(tmp[i+1]^a[i]);
  }
  for(int i=n;i>=1;i--){
    ins(tmp[i]);
    r[i]=max(r[i+1],solve(tmp[i]));
  }
  int mx=-1;
  for(int i=2;i<=n;i++){
    mx=max(mx,l[i-1]+r[i]);
  }
  printf("%d\n",mx);
  return 0;
}
