#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
typedef long long ll;
typedef pair<ll,ll>pi;
vector<pi>G[maxn];
ll sz[maxn];
ll dp[maxn][17];
ll sum1[maxn],sum[maxn];
ll rep[maxn];
int w,n;

void dfs1(int u,int p){
    sz[u]=1;
    sum[u]=0;
    for(int i=1;i<16;i++)
        dp[u][i]=0;
    dp[u][0]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].first;
        int k=G[u][i].second;
        if(v==p)
            continue;
        dfs1(v,u);
        sum1[v]=0;
        int x=k/16,y=k%16;
        sz[u]+=sz[v];
        sum[u]+=sum[v]+sz[v]*16*x;         //sum[]一定为16的倍数
        sum1[v]+=sum[v]+sz[v]*16*x;         //sum[v]-sum1[v]即为不是他的子孙到他的距离
        for(int j=0;j<16;j++){
            dp[u][(j+y)%16]+=dp[v][j];
            if(j+y>=16){
                sum[u]+=dp[v][j]*16;
                sum1[v]+=dp[v][j]*16;
            }
        }
    }
}

void dfs2(int u,int p){
    rep[u]=sum[u];
    //printf("u is %d sum[u] is %I64d\n",u,sum[u]);
    for(int i=0;i<16;i++){
        //if(u==1){
            //printf("%d\n",dp[u][i]);
        //}
        rep[u]+=dp[u][i]*(i^w);
    }
    for(int i=G[u].size()-1;i>=0;i--){
        int v=G[u][i].first;
        int k=G[u][i].second;
        if(v==p)
            continue;
        int x=k/16,y=k%16;
        printf("%d %d\n",u,v);
        printf("+=%lld %lld\n",(sum[u]-sum1[v]),(n-sz[v])*16*x);
        sum[v]+=(sum[u]-sum1[v]);
        sum[v]+=(n-sz[v])*16*x;
        vector<int>V;
        V.assign(17,0);
        for(int j=0;j<16;j++){
            V[(j+y)%16]+=dp[u][j]-dp[v][(j-y+16)%16];
            if(j+y>=16){
              printf("%d %d %d %d\n",u,j,v,(j-y+16)%16);
                printf("+=%lld\n",(dp[u][j]-dp[v][(j-y+16)%16])*16);
                sum[v]+=(dp[u][j]-dp[v][(j-y+16)%16])*16;
            }
        }
        for(int j=0;j<16;j++)
            dp[v][j]+=V[j];
        dfs2(v,u);
    }
}
void init(int n){
    for(int i=1;i<=n;i++)
        G[i].clear();
}
int main(){
  freopen("tree1.in","r",stdin);
  freopen("tree1.std.out","w",stdout);
    int t=1;
    //scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&w);
        init(n);
        int u,v,k;
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&k);
            G[u].push_back(pi(v,k));
            G[v].push_back(pi(u,k));
        }
        dfs1(1,0);
        dfs2(1,0);
        for(int i=1;i<=n;i++){
          cout<<sum[i]<<endl;
        }
        return 0;
        for(int i=1;i<=n;i++)
            printf("%lld\n",rep[i]-w);
    }
    return 0;
}
