//
// Created by swift on 2020/7/18.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x,v;
    bool operator <(const node &t)const{
        return v<t.v;
    }
};
priority_queue<node>p;
int n,k,a[210000],pre[210000],nxt[210000],vis[210000];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        p.push({i,a[i]});
        pre[i]=i-1;
        nxt[i]=i+1;
    }
    pre[1]=n;
    nxt[n]=1;
    int ans=0;
    for(int i=1;i<=n/2;i++){
        while(vis[p.top().x])p.pop();
        node now=p.top();p.pop();
        ans+=now.v;
        int x=pre[now.x],yd=nxt[now.x];
        vis[x]=vis[y]=1;
        nxt[now.x]=nxt[y];
        pre[now.x]=pre[x];
        pre[nxt[now.x]]=now.x;
        nxt[pre[now.x]]=now.x;
        now.v=a[now.x]=a[x]+a[y]-a[now.x];
        p.push(now);
        printf("%lld\n",ans);
    }
    return 0;
}