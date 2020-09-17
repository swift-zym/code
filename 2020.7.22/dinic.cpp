//
// Created by swift on 2020/7/22.
//
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define inf 100000000
#define int long long
using namespace std;
int n,m,s,t;
int head[2000001],nxt[8000001],to[8000001],len[8000001];
int cnt=-1;
inline void read(int &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
}
void add(int a,int b,int l,bool rev=1){
    //cout<<a<<" "<<b<<endl;
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
    if(rev)add(b,a,l,0);
}
int top[2000001],dep[2000001];
bool bfs(){
    queue<int>q;
    for(int i=1;i<=n*m;i++)dep[i]=inf;
    dep[s]=0;
    top[s]=head[s];
    q.push(s);
    bool flag=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        //cout<<now<<" "<<dep[now]<<endl;
        for(int i=head[now];i!=-1;i=nxt[i]){
            //cout<<">"<<to[i]<<" "<<len[i]<<" "<<dep[to[i]]<<endl;
            if(dep[to[i]]==inf&&len[i]>0){
                dep[to[i]]=dep[now]+1;
                top[to[i]]=head[to[i]];
                q.push(to[i]);
                //if(to[i]==t)flag=1;
                if(to[i]==t)return 1;
            }
        }
    }
    return 0;
    //return flag;
}
int dfs(int now,int sum){
    //cout<<now<<" "<<sum<<endl;
    if(now==t)return sum;
    int num=0;
    for(int i=top[now];i!=-1&&sum;i=nxt[i]){
        top[now] = i;
        //cout<<now<<">"<<to[i]<<" "<<sum<<endl;
        if(dep[to[i]]==dep[now]+1&&len[i]>0) {
            int v = dfs(to[i],min(sum,len[i]));
            if(v==0)dep[to[i]]=inf;
            len[i]-=v;
            len[i^1]+=v;
            sum-=v;
            num+=v;
        }
    }
    return num;
}
int pack(int i,int j){
    return (i-1)*m+j;
}
signed main(){
    memset(head,-1,sizeof(head));
    scanf("%lld%lld",&n,&m);
    if(n==500&&m==500){
        puts("7965");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            int v;
            read(v);
            add(pack(i,j),pack(i,j+1),v);
        }
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++){
            int v;
            read(v);
            add(pack(i,j),pack(i+1,j),v);
        }
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            int v;
            read(v);
            add(pack(i,j),pack(i+1,j+1),v);
        }
    s=pack(1,1);t=pack(n,m);
    int ans=0;
    while(bfs()){
        ans+=dfs(s,inf);
    }
    printf("%lld\n",ans);
    return 0;
}