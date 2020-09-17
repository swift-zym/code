//
// Created by swift on 2020/8/9.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[700001],nxt[1400001],to[1400001],len[1400001],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
    len[cnt]=l;
}
int n,a[700001],num[700001],dp[700001],ans[700001],val[700001];
void dfs(int now,int fa,int d){
    num[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs(to[i],now,len[i]);
        num[now]+=num[to[i]];
        dp[now]+=dp[to[i]];
    }
    //cout<<now<<" "<<num[now]<<" "<<d-a[now]<<endl;
    val[now]=num[now]*(d-a[now]);
    dp[now]+=num[now]*(d-a[now]);
}
void solve(int now,int d){
    val[now]=num[now]*(d-a[now]);
}
void dfss(int now,int fa,int d){
    int bf[4];
    if(fa!=0){
        bf[0]=val[now];
        bf[1]=val[fa];
        bf[2]=num[now];
        bf[3]=num[fa];
        num[fa]-=num[now];
        num[now]=n;
        ans[now]=ans[fa];
        ans[now]-=val[now];
        ans[now]-=val[fa];
        solve(now,0);
        solve(fa,d);
        ans[now]+=val[now];
        ans[now]+=val[fa];
    }
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfss(to[i],now,len[i]);
    }
    if(fa!=0){
        val[now]=bf[0];
        val[fa]=bf[1];
        num[now]=bf[2];
        num[fa]=bf[3];
    }
}

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        int x,y,l;
        scanf("%lld%lld%lld",&x,&y,&l);
        add(x,y,l);
        add(y,x,l);
    }
    dfs(1,0,0);
    ans[1]=dp[1];
    for(int i=1;i<=n;i++)ans[1]+=a[i];
    dfss(1,0,0);
    int mi=1e18,id;
    for(int i=1;i<=n;i++){
        if(ans[i]<mi){
            mi=ans[i];
            id=i;
        }
        //cout<<tmp<<endl;
        //puts("---");
    }
    printf("%lld\n%lld\n",id,mi);
    return 0;
}