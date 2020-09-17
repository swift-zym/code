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
int l5[9][5]={{2,6,12,18,24},{4,10,16,22,28},{8,14,20,26,30},{3,4,5,6,7},{14,15,16,17,18},{25,26,27,28,29},{1,4,9,14,19},{6,11,16,21,26},{13,18,23,28,31}};
int l6[6][6]={{1,5,11,17,23,29},{3,9,15,21,27,31},{8,9,10,11,12,13},{19,20,21,22,23,24},{2,5,10,15,20,25},{7,12,17,22,27,30}};
int l7[7][7]={{1,2,4,5,6,10,11},{3,4,8,9,10,14,15},{6,7,11,12,13,17,18},{10,11,15,16,17,21,22},{14,15,19,20,21,25,26},{17,18,22,23,24,28,29},{21,22,26,27,28,30,31}};
int n,k,a[32],vis[32],num,cnt,has[32][32];
vector<int>bel[32];
void pre(){
  for(int i=0;i<=8;i++){
    ++cnt;
    for(int j=0;j<=4;j++){
      bel[l5[i][j]].push_back(cnt);
    }
  }
  for(int i=0;i<=5;i++){
    ++cnt;
    for(int j=0;j<=5;j++){
      bel[l6[i][j]].push_back(cnt);
    }
  }
  for(int i=0;i<=6;i++){
    ++cnt;
    for(int j=0;j<=6;j++){
      bel[l7[i][j]].push_back(cnt);
    }
  }
}
bool check(){
  for(int i=0;i<=8;i++){
    memset(vis,0,sizeof(vis));
    for(int j=0;j<=4;j++){
      if(a[l5[i][j]]==0)continue;
      if(vis[a[l5[i][j]]])return 0;
      vis[a[l5[i][j]]]=1;
    }
  }
  for(int i=0;i<=5;i++){
    memset(vis,0,sizeof(vis));
    for(int j=0;j<=5;j++){
      if(a[l6[i][j]]==0)continue;
      if(vis[a[l6[i][j]]])return 0;
      vis[a[l6[i][j]]]=1;
    }
  }
  for(int i=0;i<=6;i++){
    memset(vis,0,sizeof(vis));
    for(int j=0;j<=6;j++){
      if(a[l7[i][j]]==0)continue;
      if(vis[a[l7[i][j]]])return 0;
      vis[a[l7[i][j]]]=1;
    }
  }
  return 1;
}
void dfs(int deep){
  if(deep==32){
    num++;
    if(num==n){
      puts("Found");
      for(int i=1;i<=31;i++){
        if(i!=1)putchar(' ');
        printf("%d",a[i]);
      }
      putchar(10);
      exit(0);
    }
    return;
  }
  if(a[deep]){
  dfs(deep+1);
  return;
  }
  for(int i=1;i<=k;i++){
  bool flag=1;
  for(int j=0;j<bel[deep].size();j++){
    if(has[bel[deep][j]][i]){
      flag=0;
      break;
    }
  }
  if(!flag)continue;
  for(int j=0;j<bel[deep].size();j++){
    has[bel[deep][j]][i]=1;
  }
  a[deep]=i;
  dfs(deep+1);
  for(int j=0;j<bel[deep].size();j++){
    has[bel[deep][j]][i]=0;
  }
  }
  a[deep]=0;
}
int main(){
  pre();
  scanf("%d%d",&k,&n);
  for(int i=1;i<=31;i++){
    scanf("%d",&a[i]);
    if(a[i]){
      for(int j=0;j<bel[i].size();j++){
        has[bel[i][j]][a[i]]=1;
      }
    }
  }
  dfs(1);
  puts("No way");
  return 0;
}
