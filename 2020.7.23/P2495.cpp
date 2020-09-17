//
// Created by swift on 2020/7/23.
//

#include<bits/stdc++.h>
using namespace std;
int head[250001],to[500001],nxt[500001],len[500001],dfn[250001],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int f[250001][21],mi[250001],dep[250001];
int T;
void dfs(int now,int fa){
    dep[now]=dep[fa]+1;
    dfn[now]=++T;
    f[now][0]=fa;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        mi[to[i]]=min(mi[now],len[i]);
        dfs(to[i],now);
    }
}
int n,m;
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int i=20;i>=0;i--){
        if(dep[f[a][i]]>=dep[b])a=f[a][i];
    }
    if(a==b)return a;
    for(int i=20;i>=0;i--){
        if(f[a][i]!=f[b][i]){
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
vector<int>v[250001];
int s[250001],tp;
bool cmp(int a,int b){
    return dfn[a]<dfn[b];
}
int idx[250001];
void ins(int now){
    if(now==1){
        s[++tp]=now;
        return;
    }
    int z=lca(now,s[tp]);
    if(z==s[tp])return;
    while(tp>1&&dfn[s[tp]]>=dfn[now]){
        v[s[tp-1]].push_back(s[tp]);tp--;
    }
    if(s[tp]!=z){
        v[z].push_back(s[tp]);
        s[tp]=z;
    }
    s[++tp]=now;
}
int solve(int now){
    if(!v[now].size())return mi[now];
    int tmp=0;
    for(int i=0;i<v[now].size();i++){
        tmp+=solve(v[now][i]);
    }
    return min(mi[now],tmp);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    dfs(1,1);
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
        }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int k;
        tp=0;
        for(int i=1;i<=n;i++)v[i].clear();
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&idx[i]);
        }
        sort(idx+1,idx+k+1,cmp);
        s[tp=1]=1;
        for(int i=1;i<=k;i++){
            cout<<idx[i]<<endl;
            ins(idx[i]);
        }
        cout<<"--"<<endl;
        while(tp>1)v[s[tp-1]].push_back(s[tp]);
        printf("%d\n",solve(1));
    }
    return 0;
}
/*
10
1 5 13
1 9 6
2 1 19
2 4 8
2 3 91
5 6 8
7 5 4
7 8 31
10 7 9
3
2 10 6
4 5 7 8 3
3 9 4 6
*/
