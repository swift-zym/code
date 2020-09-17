//
// Created by swift on 2020/7/31.
//

#include<bits/stdc++.h>
using namespace std;
int a[100],head[100001],to[210000],len[210000],cost[210000],nxt[210000],cnt;
void add(int a,int b,int l,int c,bool rev=0){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
    len[cnt]=l;
    cost[cnt]=c;
    if(!rev){
        add(b,a,0,-c,1);
    }
}
int n,m;
int s,t;
int dis[100],flow[100],vis[100];
int lst[100],pre[100];
int SPFA(){
    memset(flow,0,sizeof(flow));
    memset(dis,0x3f,sizeof(dis));
    flow[s]=1e9;
    dis[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        //cout<<now<<" "<<flow[now]<<endl;
        for(int i=head[now];i!=-1;i=nxt[i]){
            if(len[i]>0&&dis[to[i]]>dis[now]+cost[i]){
                dis[to[i]]=dis[now]+cost[i];
                pre[to[i]]=now;
                lst[to[i]]=i;
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
int main(){
    int testcase=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0)break;
        testcase++;
        cnt=-1;
        memset(head,-1,sizeof(head));
        s=0;t=n+1;
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a++;
            b++;
            add(a,b,1,c);
        }
        add(s,1,2,0);
        add(n,t,2,0);
        int l=0,c=0;
        while(SPFA()){
            int now=t;
            l+=flow[t];
            c+=flow[t]*dis[t];
            while(now!=s){
                len[lst[now]]-=flow[t];
                len[lst[now]^1]+=flow[t];
                now=pre[now];
            }
        }
        //cout<<l<<endl;
        if(l<2){
            printf("Instance #%d: Not possible\n",testcase);
        }
        else{
            printf("Instance #%d: %d\n",testcase,c);
        }
    }
    return 0;
}