//
// Created by swift on 2020/8/1.
//
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
int n,m;
long long T,rxa,rxc,rya,ryc,rp;
int head[1000001],nxt[10000001],to[10000001],len[10000001],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
long long x,y,z;
long long ans[1000001];
struct node{
    int x;
    long long v;
    bool operator<(const node &t)const{
        return v>t.v;
    }
};
priority_queue<node>p;
signed main(){
    scanf("%d%d",&n,&m);
    scanf("%lld%lld%lld%lld%lld%lld",&T,&rxa,&rxc,&rya,&ryc,&rp);
    for(int i=1;i<=T;i++){
        x=(x*rxa+rxc)%rp;
        y=(y*rya+ryc)%rp;
        long long a=min(x%n+1,y%n+1),b=max(x%n+1,y%n+1);
        add(a,b,1e8-100*a);
    }
    for(int i=T+1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y,z);
    }
    memset(ans,0x3f,sizeof(ans));
    ans[1]=0;
    p.push({1,0});
    while(!p.empty()){
        node now=p.top();p.pop();
        if(now.v!=ans[now.x])continue;
        for(int i=head[now.x];i;i=nxt[i]){
            if(ans[to[i]]>ans[now.x]+len[i]){
                ans[to[i]]=ans[now.x]+len[i];
                p.push({to[i],ans[to[i]]});
            }
        }
    }
    printf("%lld\n",ans[n]);
    return 0;
}