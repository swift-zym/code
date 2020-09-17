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
#pragma GCC optimize("-fdelete-null-pointer-checks"
#include<bits/stdc++.h>
using namespace std;
int vis[500005],head[500005],nxt[5000005],to[5000005],len[5000005],ans[500005],cnt;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
int main(){
    int n,mx=-1;
    memset(head,0,sizeof(head));
    memset(ans,-0x3f,sizeof(ans));
    memset(vis,0,sizeof(vis));
    cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      int a,b,l;
      scanf("%d%d%d",&a,&b,&l);
      mx=max(mx,b+2);
      add(a+1,b+2,l);
    }
    for(int i=2;i<=mx;i++){
      add(i-1,i,0);
      add(i,i-1,-1);
    }
    queue<int>q;
    q.push(1);
    ans[1]=0;
    while(!q.empty()){
      int now=q.front();
      q.pop();
      vis[now]=0;
      for(int i=head[now];i;i=nxt[i]){
        if(ans[to[i]]<ans[now]+len[i]){
          ans[to[i]]=ans[now]+len[i];
          if(!vis[to[i]]){
            vis[to[i]]=1;
            q.push(to[i]);
          }
        }
      }
    }
    printf("%d\n",ans[mx]);

}
