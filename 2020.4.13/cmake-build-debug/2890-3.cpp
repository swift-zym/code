//
// Created by 张一鸣 on 2020/4/23.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
int siz[1000001],head[1000001],nxt[2000001],to[2000001],len[2000001],cnt,sum[2000001];
int n,ans;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
    len[cnt]=l;
}
void dfs1(int now,int dep,int fa){
    siz[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs1(to[i],dep+len[i],now);
        siz[now]+=siz[to[i]];
        sum[now]+=sum[to[i]]+len[i]*siz[to[i]];
    }
}
void dfs2(int now,int fa){
    int tmp=0,ans_now=0,num=0,num_sum=0;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs2(to[i],now);
        ans_now+=(sum[to[i]]+len[i]*siz[to[i]])*num_sum+siz[to[i]]*tmp;
        tmp+=sum[to[i]]+len[i]*siz[to[i]];
        num_sum+=siz[to[i]];
        num++;
    }
    ans_now+=tmp;
    ans_now*=now;
    ans+=ans_now;
}
//2+2+8+4+10
//(a+b)+(a+c)+(a+d)
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    dfs1(1,0,0);
    dfs2(1,0);
    printf("%lld\n",ans);
    return 0;
}

/*
15
1 2 756
2 3 358
3 4 85
4 5 25
5 6 957
6 7 1000
7 8 134
8 9 161
9 10 586
10 11 456
11 12 133
12 13 478
13 14 136
14 15 888
 */