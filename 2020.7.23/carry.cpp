//
// Created by swift on 2020/7/23.
//
#include<bits/stdc++.h>
using namespace std;
int head[100001],nxt[200001],to[200001],cnt,len[200001];
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
    len[cnt]=l;
}
int n,q,l;
int f[100001],s[100001],t[100001],dep[100001],v[100001];
void dfs(int now,int fa){
    f[now]=fa;
    dep[now]=dep[fa]+1;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]!=fa){
            v[to[i]]=len[i];
            dfs(to[i],now);
        }
    }
}
int mi=1e8;
int main(){
    scanf("%d%d%d",&n,&q,&l);
    for(int i=1;i<n;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&s[i],&t[i]);
    }
    dfs(1,1);

    return 0;
}