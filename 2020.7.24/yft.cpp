
 //
//  main.cpp
//  On Mac
//
//  Created by 张一鸣 on 2020/7/18.
//

#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
int head[400001],nxt[400001],to[400001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
stack<int>s;
int dfn[400001],low[400001],T;
int n,m,q,num;
vector<int>v[400001];
void tarjan(int now){
    dfn[now]=low[now]=++T;
    s.push(now);
    for(int i=head[now];i;i=nxt[i]){
        //cout<<now<<"->"<<to[i]<<endl;
        if(!dfn[to[i]]){
            tarjan(to[i]);
            low[now]=min(low[now],low[to[i]]);
            if(low[to[i]]==dfn[now]){
                num++;
                int tp=s.top();
                do{
                    tp=s.top();
                    s.pop();
                    v[num].push_back(tp);
                    v[tp].push_back(num);
                    //cout<<num<<"?"<<tp<<endl;
                }while(tp!=to[i]);
                v[now].push_back(num);
                v[num].push_back(now);
                //cout<<num<<"!"<<now<<endl;
            }
        }
        else{
            low[now]=min(low[now],dfn[to[i]]);
        }
    }
}
int dep[400001],f[400001][21];
int que[400001];
void dfs(int now,int fa){
    que[++que[0]]=now;
    f[now][0]=fa;
    for(int i=0;i<v[now].size();i++){
        if(v[now][i]==fa)continue;;
        dep[v[now][i]]=dep[now]+1;
        dfs(v[now][i],now);
    }
}
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
int ans[400001];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    num=n;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    dep[1]=1;
    dfs(1,0);
    for(int i=1;i<=20;i++)
    for(int j=1;j<=num;j++){
        f[j][i]=f[f[j][i-1]][i-1];
    }
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ans[a]++;
        ans[b]++;
        int l=lca(a, b);
        ans[l]--;
        ans[f[l][0]]--;
    }
    for(int i=que[0];i>=1;i--){
        ans[f[que[i]][0]]+=ans[que[i]];
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
