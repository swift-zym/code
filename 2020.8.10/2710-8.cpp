//
// Created by swift on 2020/8/10.
//
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans,num[100001],vis[100001];
int a[100001];
void add(int x){
    if(num[x]++==0)ans++;
}
void del(int x){
    if(--num[x]==0)ans--;
}
void change(int x){
    if(vis[x]){
        del(a[x]);
    }
    else{
        add(a[x]);
    }
    vis[x]^=1;
}
int dep[100001];
int f[100001][20];
int B,belong[100001],siz[100001],idx;
int head[100001],nxt[200001],to[200001],cnt;
int dfn[100001],T;
int O;
void add(int a,int b){
    //cout<<a<<"->"<<b<<endl;
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
void dfs(int now,int fa){
    if(siz[belong[fa]]==B){
        belong[now]=++idx;
    }
    else{
        belong[now]=belong[fa];
    }
    dfn[now]=++T;
    siz[belong[now]]++;
    f[now][0]=fa;
    dep[now]=dep[fa]+1;
    for(int i=head[now];i;i=nxt[i]){
        //cout<<now<<"->"<<to[i]<<endl;
        if(to[i]==fa)continue;
        dfs(to[i],now);
    }
}
struct Query{
    int u,v,a,b,id;
    bool operator <(const Query &t)const{
        if(belong[u]!=belong[t.u]){
            return belong[u]<belong[t.u];
        }
        return dfn[v]<dfn[t.v];
    }
};
vector<Query>q;
int root;
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    //cout<<">"<<a<<" "<<b<<endl;
    //cout<<dep[a]<<" "<<dep[b]<<endl;
    for(int i=19;i>=0;i--){
        if(dep[f[a][i]]>=dep[b]){
            a=f[a][i];
        }
    }
    //cout<<">>"<<a<<" "<<b<<endl;
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(f[a][i]!=f[b][i]){
            a=f[a][i];
            b=f[b][i];
        }
    }
    //cout<<">>>"<<a<<" "<<b<<endl;
    return f[a][0];
}
int out[100001];
int main(){
    scanf("%d%d",&n,&m);
    B=sqrt(n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(!a||!b){
            root=(a|b);
            continue;
        }
        add(a,b);
        add(b,a);
    }
    dfs(root,root);
    //cout<<O<<endl;
    /*for(int i=1;i<=n;i++){
        cout<<belong[i]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=19;i++)
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
        }
    for(int i=1;i<=m;i++){
        int u,v,a,b;
        scanf("%d%d%d%d",&u,&v,&a,&b);
        q.push_back({u,v,a,b,i});
    }
    sort(q.begin(),q.end());
    int l,r;
    l=r=root;
    for(int i=0;i<q.size();i++){
        //cout<<i<<endl;
        int tmp=lca(l,q[i].u);
        //cout<<tmp<<endl;
        //cout<<l<<" "<<q[i].u<<endl;
        //puts("---");
        for(int j=l;j!=tmp;j=f[j][0]){
            change(j);
        }
        for(int j=q[i].u;j!=tmp;j=f[j][0]){
            change(j);
        }
        tmp=lca(r,q[i].v);
        for(int j=r;j!=tmp;j=f[j][0]){
            change(j);
        }
        for(int j=q[i].v;j!=tmp;j=f[j][0]){
            change(j);
        }
        tmp=lca(q[i].u,q[i].v);
        change(tmp);
        out[q[i].id]=ans;
        if(q[i].a!=q[i].b&&num[q[i].a]&&num[q[i].b]){
            out[q[i].id]--;
        }
        change(tmp);
        l=q[i].u;r=q[i].v;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",out[i]);
    }
    return 0;
}