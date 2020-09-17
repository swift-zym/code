//
// Created by swift on 2020/6/26.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
int dfn[100001],low[100001],vis[100001],bel[100001],num,siz[100001];
struct G{
    int head[100001],nxt[100001],to[100001],cnt;
    int dis[100001];
    void add(int a,int b){
        nxt[++cnt]=head[a];
        to[cnt]=b;
        head[a]=cnt;
    }
    void cle(){
        cnt=0;
        memset(head,0,sizeof(head));
    }
    int vis[100001];
    void SPFA(){
        queue<int>q;
        vis[bel[1]]=1;
        dis[bel[1]]=siz[bel[1]];
        q.push(bel[1]);
        while(!q.empty()){
            int now=q.front();q.pop();
            vis[now]=0;
            for(int i=head[now];i;i=nxt[i]){
                if(dis[now]+siz[to[i]]>dis[to[i]]){
                    dis[to[i]]=dis[now]+siz[to[i]];
                    if(!vis[to[i]]){
                        vis[to[i]]=1;
                        q.push(to[i]);
                    }
                }
            }
        }
    }
}G1,G2;
int head[100001],nxt[100001],to[100001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
stack<int>s;
int tim;
void tarjan(int now){
    s.push(now);
    dfn[now]=low[now]=++tim;
    vis[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(!dfn[to[i]]){
            tarjan(to[i]);
            low[now]=min(low[now],low[to[i]]);
        }
        else if(vis[to[i]]){
            low[now]=min(low[now],dfn[to[i]]);
        }
    }
    if(low[now]==dfn[now]){
        int tp;
        num++;
        do{
            siz[num]++;
            tp=s.top();
            vis[tp]=0;
            bel[tp]=num;
            s.pop();
        }while(tp!=now);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nxt[j]){
            if(bel[to[j]]!=bel[i]){
                G1.add(bel[i],bel[to[j]]);
                G2.add(bel[to[j]],bel[i]);
            }
        }
    G1.SPFA();
    G2.SPFA();
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nxt[j]){
            if(bel[to[j]]!=bel[i]) {
                if (G1.dis[bel[to[j]]] > 0 && G2.dis[bel[i]] > 0) {
                int v = -siz[bel[1]] + G1.dis[bel[to[j]]] + G2.dis[bel[i]];
                ans = max(ans, v);
                }
            }
        }
    printf("%d\n",ans);
    return 0;
}
