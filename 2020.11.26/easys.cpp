#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
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
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
struct edge{
    int u,v,w,id;
    bool operator <(const edge &t)const{
        return w<t.w;
    }
};
vector<edge>e,mst;
int f[100001];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
vector<int>v[100001];
int fa[100001],deep[100001],top[100001],siz[100001],son[100001];
void dfs1(int now,int p,int d=1){
    siz[now]=1;
    deep[now]=d;
    for(auto to:v[now]){
        if(to==p)continue;
        dfs1(to,now,d+1);
        siz[now]+=siz[to];
        if(siz[to]>siz[son[now]])son[now]=to;
    }
}
int dfn[100001],T,mp[100001],pre[100001];
void dfs2(int now,int p,int tp){
    dfn[now]=++T;mp[T]=now;fa[now]=p;top[now]=tp;
    if(son[now])dfs2(son[now],now,tp);
    for(auto to:v[now]){
        if(to==p||to==son[now])continue;
        dfs2(to,now,to);
    }
}
struct node{
    int tag,mx;
}a[1000000];
void build(int now,int l,int r){
    a[now].tag=-1;
    a[now].mx=1e9;
    if(l==r)return;
    int mid=(l+r)/2;
    build(now*2,l,mid);build(now*2+1,mid+1,r);
}
void pushdown(int now){
    if(a[now].tag==-1)return;
    a[now*2].mx=a[now*2+1].mx=a[now*2].tag=a[now*2+1].tag=a[now].tag;
    a[now].tag=-1;
}
void pushup(int now){
    a[now].mx=max(a[now*2].mx,a[now*2+1].mx);
}
void change(int now,int l,int r,int L,int R,int v){
    if(l==L&&r==R){
        a[now].tag=a[now].mx=v;
        return;
    }
    pushdown(now);
    int mid=(l+r)/2;
    if(R<=mid)change(now*2,l,mid,L,R,v);
    else if(L>mid)change(now*2+1,mid+1,r,L,R,v);
    else{change(now*2,l,mid,L,mid,v);change(now*2+1,mid+1,r,mid+1,R,v);}
}
int query(int now,int l,int r,int L,int R){
    if(l==L&&r==R)return a[now].mx;
    pushdown(now);
    int mid=(l+r)/2;
    if(R<=mid)return query(now*2,l,mid,L,R);
    else if(L>mid)return query(now*2+1,mid+1,r,L,R);
    else return max(query(now*2,l,mid,L,mid),query(now*2+1,mid+1,r,mid+1,R));
}
int ans[1000001],val[100001];
void rebuild(int now,int l,int r){
    a[now].tag=-1;
    if(l==r){
        a[now].mx=val[mp[l]];
        return;
    }
    int mid=(l+r)/2;
    rebuild(now*2,l,mid);rebuild(now*2+1,mid+1,r);
    pushup(now);
}
int vis[1000001];
int main(){
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e.push_back({u,v,w,i});
    }
    sort(e.begin(),e.end());
    for(auto s:e){
        int x=gf(s.u),y=gf(s.v);
        if(x==y)continue;
        f[x]=y;
        v[s.u].push_back(s.v);
        v[s.v].push_back(s.u);
        vis[s.id]=1;
        mst.push_back(s);
    }
    build(1,1,n);
    dfs1(1,1);dfs2(1,1,1);
    reverse(e.begin(),e.end());
    for(auto now:e){
        if(vis[now.id])continue;
        int x=now.u,y=now.v,z=now.w;
        while(top[x]!=top[y]){
            if(deep[top[x]]<deep[top[y]])swap(x,y);
            change(1,1,n,dfn[top[x]],dfn[x],z);
            x=fa[top[x]];
        }
        if(deep[x]>deep[y])swap(x,y);
        if(dfn[x]!=dfn[y])
        change(1,1,n,dfn[x]+1,dfn[y],z);
    }
    for(auto now:mst){
        int id=deep[now.u]<deep[now.v]?now.v:now.u;vis[now.id]=1;
        ans[now.id]=query(1,1,n,dfn[id],dfn[id]);
        val[id]=now.w;
    }
    rebuild(1,1,n);
    for(auto now:e){
        if(vis[now.id])continue;
        int x=now.u,y=now.v,tmp=-1;
        while(top[x]!=top[y]){
            if(deep[top[x]]<deep[top[y]])swap(x,y);
            tmp=max(tmp,query(1,1,n,dfn[top[x]],dfn[x]));
            x=fa[top[x]];
        }
        if(deep[x]>deep[y])swap(x,y);
        if(dfn[x]!=dfn[y])
        tmp=max(tmp,query(1,1,n,dfn[x]+1,dfn[y])); 
        ans[now.id]=tmp;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}