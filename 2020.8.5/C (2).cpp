//
// Created by swift on 2020/8/5.
//

#include<bits/stdc++.h>
using namespace std;
int head[20000],nxt[1000000],to[1000000],len[1000000],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int n,m,k;
int decode(int x,int sta){
    return sta*n+x;
}
struct edge{
    int s,t,key;
}e[5001];
int mp[1001];
int dis[20000],vis[20000];
queue<int>q;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            int tmp;
            scanf("%d",&tmp);
            if(tmp){
                mp[i]|=(1<<j);
            }
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&e[i].s,&e[i].t);
        for(int j=0;j<k;j++){
            int tmp;
            scanf("%d",&tmp);
            if(tmp){
                e[i].key|=(1<<j);
            }
        }
    }
    for(int sta=0;sta<(1<<k);sta++){
        for(int i=1;i<=n;i++){
            if((sta|mp[i])!=sta){
                add(decode(i,sta),decode(i,sta|mp[i]),0);
            }
        }
        for(int i=1;i<=m;i++){
            if((sta|e[i].key)==sta){
                add(decode(e[i].s,sta),decode(e[i].t,sta),1);
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    int inf=dis[1];
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=nxt[i]){
            if(dis[to[i]]>dis[now]+len[i]){
                dis[to[i]]=dis[now]+len[i];
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    if(dis[decode(n,(1<<k)-1)]==inf){
        puts("No Solution");
    }
    else
    printf("%d\n",dis[decode(n,(1<<k)-1)]);
    return 0;
}