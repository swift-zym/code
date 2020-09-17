//
// Created by swift on 2020/8/6.
//
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
    int s,t;
}e[200001];
vector<int>v[1001];
int vis[1001],a[1001][1001],b[1001][1001];
void dfs1(int now,int st){
    vis[now]=1;
    a[st][now]=1;
    for(int i=0;i<v[now].size();i++){
        if(!vis[v[now][i]]){
            dfs1(v[now][i],st);
        }
    }
}
int col[1001];
void dfs2(int now,int st,int type,int c){
    if(type==0){
        col[now]=c;
    }
    else{
        b[st][now]=(col[now]!=c);
    }
    vis[now]=1;
    for(int i=0;i<v[now].size();i++){
        if(!vis[v[now][i]])
        dfs2(v[now][i],st,type,c);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&e[i].s,&e[i].t);
        v[e[i].s].push_back(e[i].t);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dfs1(i,i);
    }
    for(int i=1;i<=n;i++){
        memset(col,0,sizeof(col));
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        for(int j=0;j<v[i].size();j++){
            if(!vis[v[i][j]]){
                dfs2(v[i][j],i,0,j+1);
            }
        }
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        for(int j=v[i].size()-1;j>=0;j--){
            if(!vis[v[i][j]]){
                dfs2(v[i][j],i,1,j+1);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
            if(j==n)cout<<endl;
        }
    cout<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cout<<b[i][j]<<" ";
            if(j==n)cout<<endl;
        }*/
    for(int i=1;i<=m;i++){
        if(a[e[i].t][e[i].s]^b[e[i].s][e[i].t]){
            puts("diff");
        }
        else{
            puts("same");
        }
    }
    return 0;
}
