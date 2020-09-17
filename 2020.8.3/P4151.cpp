//
// Created by swift on 2020/8/3.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[50001],nxt[200001],to[200001],len[200001],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int n,m;
int p[50001],vis[50001],ans[50001];
void ins(int x){
    for(int i=60;i>=0;i--){
        if(x&(1ll<<i)){
            if(!p[i]){
                p[i]=x;
                break;
            }
            x^=p[i];
        }
    }
}
int ask(int x){
    for(int i=60;i>=0;i--){
        if((x^p[i])>x){
            x^=p[i];
        }
    }
    return x;
}
void dfs(int now){
    vis[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(!vis[to[i]]){
            ans[to[i]]=ans[now]^len[i];
            dfs(to[i]);
        }
        else if(vis[to[i]]==1){
            ins(ans[now]^ans[to[i]]^len[i]);
        }
    }
    vis[now]=2;
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    dfs(1);
    printf("%lld\n",ask(ans[n]));
    return 0;
}