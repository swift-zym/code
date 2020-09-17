//
// Created by swift on 2020/8/1.
//
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int head[10001],nxt[30001],to[30001],len[30001],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int n,m,vis[10001],ans[10001],num[10001];
queue<int>q;
bool SPFA(){
    memset(ans,0x3f,sizeof(ans));
    ans[0]=0;
    q.push(0);
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        num[now]++;
        //cout<<num[now]<<endl;
        if(num[now]>n/2){
            return 0;
        }
        for(int i=head[now];i;i=nxt[i]){
            if(ans[to[i]]>ans[now]+len[i]){
                ans[to[i]]=ans[now]+len[i];
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }
    for(int i=1;i<=m;i++){
        int opt,a,b,c;
        scanf("%d",&opt);
        if(opt==1) {
            scanf("%d%d%d", &a, &b, &c);
            if (a == b) {
                puts("No");
                return 0;
            }
            add(a, b, -c);
        }
        else if(opt==2) {
            scanf("%d%d%d", &a, &b, &c);
            add(b, a, c);
        }
        else {
            scanf("%d%d", &a, &b);
            add(a, b, 0);
            add(b, a, 0);
        }
    }
    if(SPFA()){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}