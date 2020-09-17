#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using namespace std;
__gnu_pbds::priority_queue<pair<int,int> >p;
__gnu_pbds::priority_queue<pair<int,int> >::point_iterator id[200001];
int head[200001],nxt[200001],to[200001],cnt[200001];
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int dp[200001],val[200001];
int dfs(int now){
    for(int i=head[now];i;i=nxt[i]){
        dp[now]=max(dp[now],dfs(to[i]));
    }
    dp[now]+=val[now];
    id[now]=q.push(make_pair(dp[now],now));
    return dp[now];
}

signed main(){

    return 0;
}
