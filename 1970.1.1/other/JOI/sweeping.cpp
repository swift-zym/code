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
int n,m,q;
int x[7001],y[7001];
unordered_map<int,unordered_map<int,vector<int> > >a;
int main(){
  scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&x[i],&y[i]);
    a[x[i]][y[i]].push_back(i);
  }
  for(int i=1;i<=q;i++){
    int opt;
    scanf("%d",&opt);
    if(opt==1){
      int id;
      scanf("%d",&id);
      printf("%d %d\n",x[id],y[id]);
    }
    else if(opt==2){
      int l;
      scanf("%d",&l);
      for(int j=0;j<=l;j++){
        vector<int>tmp;
        for(int k=0;k<=n-l;k++){
          for(int ii=0;ii<a[k][j].size();ii++){
            tmp.push_back(a[k][j][ii]);
          }
          a[k][j].clear();
        }
        for(int k=0;k<tmp.size();k++){
          x[tmp[k]]=n-l;
          a[n-l][j].push_back(tmp[k]);
        }
      }
    }
    else if(opt==3){
      int l;
      scanf("%d",&l);
      for(int j=0;j<=l;j++){
        vector<int>tmp;
        for(int k=0;k<=n-l;k++){
          for(int ii=0;ii<a[j][k].size();ii++){
            tmp.push_back(a[j][k][ii]);
          }
          a[j][k].clear();
        }
        for(int k=0;k<tmp.size();k++){
          y[tmp[k]]=n-l;
          a[j][n-l].push_back(tmp[k]);
        }
      }
    }
    else if(opt==4){
      m++;
      scanf("%d%d",&x[m],&y[m]);
      a[x[m]][y[m]].push_back(m);
    }
  }
  return 0;
}
