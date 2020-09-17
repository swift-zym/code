//
// Created by swift on 2020/8/9.
//

//By Menteur_Hxy
//#pragma GCC diagnostic error "-std=c++11"
//#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
//#pragma GCC target("avx","sse2")
//以上自动忽略qwq
#include<set>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define F(i,a,b) for(register int i=(a);i<=(b);i++)
#define R(i,a,b) for(register int i=(b);i>=(a);i--)
#define E(i,u) for(register int i=head[u];i;i=nxt[i])
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
using namespace std;
typedef long long LL;

char buf[1<<21],*p1,*p2;
inline int read() {
    int x;
    cin>>x;
    return x;
    /*int x=0,f=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-')f=-f;c=getchar();}
    while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
    return x*f;*/
}

const int N=800010;
int n,q,tot,cnt;
int dfn[N],id[N],f[N][24],dep[N],nxt[N],to[N],head[N],siz[N],que[N];
set <int> S;
set <int>::iterator it;

int lca(int x,int y) {
    if(dep[x]<dep[y]) swap(x,y);
    cout<<x<<"->"<<y<<endl;
    int need=dep[x]-dep[y];
    for(int i=0;need;need>>=1,i++) if(need&1) x=f[x][i];
    if(x!=y) {
        R(i,0,21) if(f[x][i]!=f[y][i])
                x=f[x][i],y=f[y][i];
        return f[x][0];
    }
    return x;
}

void dfs(int u) {
    siz[u]=1;
    dfn[u]=++tot; id[dfn[u]]=u;
    E(i,u) {
        int v=to[i];
        dep[v]=dep[u]+1;
        f[v][0]=u;
        dfs(v);
        siz[u]+=siz[v];
    }
}

void bfs1() {
    int h=0,t=1;
    que[++h]=1;
    while(h<=t) {
        int u=que[h++];
        siz[u]=1;
        E(i,u) {
            int v=to[i];
            dep[v]=dep[u]+1,f[v][0]=u;
            que[++t]=v;
        }
    }
    R(i,1,n) siz[f[que[i]][0]]+=siz[que[i]];
}

void bfs2() {
    int h=0,t=1;
    que[++h]=1;dfn[1]=1; id[dfn[1]]=1;
    while(h<=t) {
        int u=que[h++],last=u;
        E(i,u) {
            int v=to[i];
            dfn[v]=dfn[last]+(last!=u?siz[last]:1);
            id[dfn[v]]=v;
            que[++t]=v;
            last=v;
        }
    }
}

#define add(a,b) nxt[++cnt]=head[a],to[cnt]=b,head[a]=cnt
signed main() {
    //freopen("watch.in","r",stdin);
    //freopen("watch.out","w",stdout);
    n=read(),q=read();
    F(i,1,n-1) {int u=read();add(u,i+1);}
//	dfs(1); 通往溢栈的钥匙233
    bfs1(),bfs2();
//	F(i,1,n) printf("%d ",dep[i]);putchar('\n');
    for(register int j=1;(1<<j)<=n;j++)
        F(i,1,n) if(f[i][j-1])
                f[i][j]=f[f[i][j-1]][j-1];
    dep[0]=-1;
    for(int i=1;i<=n;i++){
        cout<<dfn[i]<<" ";
    }
    cout<<endl;
    F(i,1,q) {
        int x=read(),fla=0;
        if(x<0) fla=1,x=-x;
        if(!fla) {
            if(!S.insert(dfn[x]).second) S.erase(dfn[x]);
            continue;
        }
        if(S.empty()) {
            putchar('0');
            putchar('\n');
            continue;
        }
        int t1=0,t2=0;
        it=S.lower_bound(dfn[x]);
        if(it!=S.end()) {
            t1 = lca(x, id[*it]);
            cout<<">"<<id[*it]<<endl;
        }
        if(it!=S.begin()) {
            it--, t2 = lca(x, id[*it]);
            cout<<">>"<<id[*it]<<endl;
        }
//		__builtin_printf("%d %d\n",t1,t2);
        if(dep[t1]<dep[t2]) printf("%d\n",t2);
        else printf("%d\n",t1);
    }
    cin>>n;
    return 0;
}