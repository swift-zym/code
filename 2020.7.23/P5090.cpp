//
// Created by swift on 2020/7/23.
//
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int head[100001],nxt[200001],to[200001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int n;
set<int>s;
int x[100001];
int bad=0;
int mi,ans[100001],tmp[100001];
#define st set<int>::iterator
void dfs(int now,int fa){
    for(st i=s.begin();i!=s.end();i++){
        if(fa==now||__gcd(x[*i],tmp[fa])==1){
            tmp[now]=x[*i];
            s.erase(i);
            break;
        }
    }
    if(!tmp[now]){
        tmp[now]=x[*s.begin()];
        bad++;
        s.erase(s.begin());
    }
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]!=fa)dfs(to[i],now);
    }
}
int main(){
    freopen("10","r",stdin);
    freopen("10.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        srand(rand() + time(NULL) + clock() * clock() + 20061212);
        memset(head,0,sizeof(head));
        cnt=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        for(int i=1;i<=n;i++){
            x[i]=i;
            s.insert(i);
        }
        for(int _=1;;_++){
            random_shuffle(x+1,x+n+1);
            memset(tmp,0,sizeof(tmp));
            for(int i=1;i<=n;i++){
                s.insert(i);
            }
            bad=0;mi=1e8;
            int start=rand()%n+1;
            dfs(start,start);
            if(bad<mi){
                mi=bad;
                for(int i=1;i<=n;i++)ans[i]=tmp[i];
            }
            if(!mi)break;
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}