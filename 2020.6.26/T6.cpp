//
// Created by swift on 2020/6/26.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,v[510000],l[510000],r[510000];
struct node{
    int x,v;
    bool operator <(const node &t)const{
        return v<t.v;
    }
};
priority_queue<node>q;
int vis[510000];
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        q.push({i,v[i]});
        l[i]=i-1;
        r[i]=i+1;
    }
    l[0]=1;
    r[n+1]=n;
    int ans=0;
    while(k--){
        while(vis[q.top().x])q.pop();
        node now=q.top();q.pop();
        int pos=now.x,val=now.v;
        if(val<0)break;
        ans+=val;
        v[pos]=v[l[pos]]+v[r[pos]]-v[pos];
        vis[l[pos]]=vis[r[pos]]=1;
        l[pos]=l[l[pos]];
        r[pos]=r[r[pos]];
        r[l[pos]]=pos;
        l[r[pos]]=pos;
        now.v=v[pos];
        q.push(now);
    }
    printf("%lld\n",ans);
    return 0;
}