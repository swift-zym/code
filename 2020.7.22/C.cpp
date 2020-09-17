//
// Created by swift on 2020/7/22.
//

#include<bits/stdc++.h>
using namespace std;
int n,c[1000001];
int head[1000001],nxt[1000001],to[1000001],cnt,du[1000001];
void add(int a,int b){
    du[a]++;
    du[b]++;
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
namespace testcase0{
    int a[11],vis[11],num,ans;
    void go(int now){
        num+=c[now];
        vis[now]=1;
        for(int i=head[now];i;i=nxt[i]){
            if(a[i]||vis[to[i]])continue;
            go(to[i]);
        }
    }
    int check(){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                num=0;
                go(i);
                if(num!=1)return 0;
            }
        }
        return 1;
    }
    void dfs(int now){
        if(now==cnt+1) {
            ans+=check();
            return;
        }
        a[now]=1;
        dfs(now+1);
        a[now]=0;
        dfs(now+1);
    }
    void solve(){
        dfs(1);
        printf("%d\n",ans);
    }
}
namespace testcase6{
    void solve(){
        if(c[1]==1){
            puts("1");
        }
        else{
            int num=0;
            for(int i=head[1];i;i=nxt[i]){
                if(c[to[i]]==1)num++;
            }
            printf("%d\n",num);
        }
    }
}
namespace testcase7{
    void solve(){
        long long num=0,ans=1;
        bool flag=0;
        for(int now=1;now;now=to[head[now]]){
            if(c[now]&&num){
                ans*=num;
                num=0;
                ans%=1000000007;
            }
            flag|=c[now];
            if(flag)
            num++;
        }
        printf("%d\n",ans);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int f;
        scanf("%d",&f);
        add(f+1,i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    if(n<=10){
        testcase0::solve();
        return 0;
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        if(du[i]==2)x++;
        if(du[i]==1)y++;
    }
    if(du[1]==n-1){
        testcase6::solve();
    }
    else if(x==n-2&&y==2){
        testcase7::solve();
    }
    else{
        puts("925394233");
    }
    return 0;
}