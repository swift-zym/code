//
// Created by swift on 2020/8/5.
//

#include<bits/stdc++.h>
using namespace std;
int T;
int n,k;
int head[100001],dp[100001][2],nxt[200001],to[200001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
void dfs(int now,int fa){
    for(int i=head[now];i;i=nxt[i]) {
        if (to[i] == fa)continue;
        dfs(to[i], now);
        dp[now][0] += dp[to[i]][1];
    }
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dp[now][1]=max(dp[now][1],dp[now][0]-dp[to[i]][1]+dp[to[i]][0]+2);
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        cnt=0;memset(head,0,sizeof(head));
        scanf("%d%d",&n,&k);
        for(int i=2;i<=n;i++){
            int f;
            scanf("%d",&f);
            add(f,i);
            add(i,f);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,1);
        int ans=max(dp[1][0],dp[1][1]);
        if(ans>=k){
            printf("%d\n",(k+1)/2);
        }
        else{
            printf("%d\n",ans/2+(k-ans));
        }
    }
    return 0;
}