//
// Created by swift on 2020/7/24.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int head[50001],nxt[100001],to[100001],len[100001],cost[100001],cnt=-1;
void add(int a,int b,int l,int c,bool rev=1){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    cost[cnt]=c;
    head[a]=cnt;
    if(rev){
        add(b,a,0,-c,0);
    }
}
int vis[50001],flow[50001],dis[50001],pre[50001],lst[50001];
#define INF 1000000000
queue<int>q;
int SPFA(){
    memset(dis,0x3f,sizeof(dis));
    memset(flow,0,sizeof(flow));
    dis[s]=0;
    flow[s]=INF;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i!=-1;i=nxt[i]){
            if(len[i]>0&&dis[to[i]]>dis[now]+cost[i]){
                dis[to[i]]=dis[now]+cost[i];
                pre[to[i]]=i;
                lst[to[i]]=now;
                flow[to[i]]=min(flow[now],len[i]);
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    return flow[t];
}
int pack(int a,bool in){
    if(a==1)return a;
    if(a==n)return 2*n-2;
    if(in){
        return 2*(a-2)+3;
    }
    else{
        return 2*(a-2)+2;
    }
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    s=pack(1,0);t=pack(n,0);
    for(int i=2;i<n;i++){
        add(pack(i,0),pack(i,1),1,0);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(pack(a,1),pack(b,0),1,c);
    }
    int ans=0,l=0;
    while(SPFA()){
        int now=t;
        ans+=flow[t];
        l+=flow[t]*dis[t];
        while(now!=s){
            len[pre[now]]-=flow[t];
            len[pre[now]^1]+=flow[t];
            now=lst[now];
        }
    }
    printf("%d %d\n",ans,l);
    return 0;
}