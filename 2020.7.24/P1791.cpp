//
// Created by swift on 2020/7/24.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[2000],nxt[2100000],to[2100000],len[2100000],cnt=-1;
void add(int a,int b,int l,bool rev=0){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
    if(!rev){
        add(b,a,0,1);
    }
}
#define INF 1000000000
int n,m,s,t;
int a[101][101];
int pack(int x,int y){
    return (x-1)*m+y;
}
int mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
int top[2000],dep[2000];
bool bfs(){
    for(int i=s;i<=t;i++){
        dep[i]=INF;
    }
    dep[s]=1;
    top[s]=head[s];
    queue<int>q;
    q.push(s);
    while (!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];i!=-1;i=nxt[i]){
            if(dep[to[i]]==INF&&len[i]>0){
                dep[to[i]]=dep[now]+1;
                top[to[i]]=head[to[i]];
                if(to[i]==t){
                    return 1;
                }
                q.push(to[i]);
            }
        }
    }
    return 0;
}
int ans;
int dinic(int now,int sum){
    if(now==t)return sum;
    int val=0;
    for(int i=top[now];i!=-1&&sum;i=nxt[i]){
        top[now]=i;
        if(dep[to[i]]==dep[now]+1&&len[i]>0){
            int k=dinic(to[i],min(sum,len[i]));
            if(k==0)dep[to[i]]=INF;
            val+=k;
            sum-=k;
            len[i]-=k;
            len[i^1]+=k;
        }
    }
    return val;
}
signed main(){
    memset(head,-1,sizeof(head));
    scanf("%lld",&n);
    s=0;t=n+1;
    for(int i=1;i<=n;i++){
        int a;
        scanf("%lld",&a);
        add(i,t,a);
    }
    int tmp=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            int a;
            scanf("%lld",&a);
            if(a){
                add(i,j,a*2);
            }
            sum+=a;
        }
        tmp+=sum;
        add(s,i,sum);
    }
    while(bfs()){
        ans+=dinic(s,INF);
    }
    printf("%lld\n",tmp-ans);
    return 0;
}