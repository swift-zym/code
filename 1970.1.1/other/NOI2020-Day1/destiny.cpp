#include<bits/stdc++.h>
using namespace std;
int head[500001],nxt[1000001],to[1000001],len[1000001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int u[500001],v[500001];
int n,m;
int ans;
int dep[500001],f[500001],lst[500001];
void dfs2(int now,int fa){
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        f[to[i]]=now;
        lst[to[i]]=i;
        dep[to[i]]=dep[now]+1;
        dfs2(to[i],now);
    }
}
int solve(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    int tmp=0;
    while(dep[a]!=dep[b]){
        tmp|=len[lst[a]];
        a=f[a];
    }
    if(a==b)return tmp;
    while(a!=b){
        tmp|=len[lst[a]];
        a=f[a];
        tmp|=len[lst[b]];
        b=f[b];
    }
    return tmp;
}
void check(){
    int tmp=1;
    for(int i=1;i<=m;i++){
        tmp&=solve(u[i],v[i]);
    }
    ans+=tmp;
    ans%=998244353;
}
void dfs(int deep){
    if(deep==cnt+1){check();return;}
    len[deep]=len[deep+1]=1;
    dfs(deep+2);
    len[deep]=len[deep+1]=0;
    dfs(deep+2);
}
int main(){
    freopen("destiny.in","r",stdin);
    freopen("destiny.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
    }
    dfs2(1,1);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}