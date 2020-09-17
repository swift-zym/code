//
// Created by swift on 2020/6/26.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,b,cnt;
int head[10001],nxt[100001],to[100001],len[100001];
int v[10001];
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int vis[10001],ans[10001];
bool check(int mid){
    queue<int>q;
    q.push(1);
    memset(ans,0x3f,sizeof(ans));
    ans[1]=0;
    while(!q.empty()){
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i;i=nxt[i]){
            if(v[to[i]]>mid)continue;
            if(ans[to[i]]>ans[now]+len[i]){
                ans[to[i]]=ans[now]+len[i];
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    return ans[n]<=b;
}
signed main(){
    scanf("%lld%lld%lld",&n,&m,&b);
    int l,r=0;
    for(int i=1;i<=n;i++){scanf("%lld",&v[i]);r=max(r,v[i]);}
    for(int i=1;i<=m;i++){
        int a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    l=max(v[1],v[n]);
    int ans=l;
    if(check(r)==0){
        puts("FCK");
        return 0;
    }
    while(l!=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
    return 0;
}