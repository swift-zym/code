//
// Created by swift on 2020/8/4.
//
#include<bits/stdc++.h>
using namespace std;
int head[10000],nxt[1000000],to[1000000],len[1000000],cnt;
void add(int a,int b,int l,bool rev=0){
    //cout<<"add "<<a<<" "<<b<<" "<<l<<endl;
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
    if(!rev){
        add(b,a,0,1);
    }
}
int s,t;
int dep[10000],tp[10000];
#define INF 1e9
bool bfs(){
    queue<int>q;
    for(int i=s;i<=t;i++)dep[i]=INF;
    tp[s]=head[s];
    dep[s]=0;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];i!=-1;i=nxt[i]){
            if(len[i]>0&&dep[to[i]]==INF){
                dep[to[i]]=dep[now]+1;
                tp[to[i]]=head[to[i]];
                if(to[i]==t)return 1;
                q.push(to[i]);
            }
        }
    }
    return 0;
}
int dinic(int now,int flow){
    //cout<<">>"<<now<<" "<<flow<<endl;
    int sum=0;
    if(now==t)return flow;
    for(int i=head[now];i!=-1;i=nxt[i]){
        if(!flow)break;
        tp[now]=i;
        if(dep[to[i]]==dep[now]+1&&len[i]>0){
            int k=dinic(to[i],min(len[i],flow));
            //cout<<">>>"<<len[i]<<" "<<to[i]<<endl;
            if(!k){
                dep[to[i]]=INF;
            }
            flow-=k;
            sum+=k;
            len[i]-=k;
            len[i^1]+=k;
        }
    }
    return sum;
}
int n,m,k,a[300][300];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    s=0;t=n+m+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    int l=1,r=INF,ans;
    while(l<=r){
        memset(head,-1,sizeof(head));cnt=-1;
        int mid=(l+r)/2;
        for(int i=1;i<=n;i++){
            add(s,i,1);
        }
        for(int i=1;i<=m;i++){
            add(i+n,t,1);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(a[i][j]<=mid){
                    add(i,j+n,1);
                }
            }
        int flow=0;
        while(bfs()){
            flow+=dinic(s,INF);
        }
        if(flow>=n-k+1){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
