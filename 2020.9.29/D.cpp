#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int n;
int dp[10001][3];
void dfs(int now,int fa){
    int sum=0,mi=1e8,tmp=0;
    for(auto i=v[now].begin();i!=v[now].end();i++){
        int to=*i;
        if(to==fa)continue;
        dfs(to,now);
        int val=min(dp[to][0],min(dp[to][1],dp[to][2]));
        sum+=val;
        tmp+=min(dp[to][0],dp[to][1]);
        mi=min(mi,dp[to][0]-min(dp[to][0],dp[to][1]));
    }
    dp[now][0]=sum+1;
    dp[now][1]=tmp+mi;
    dp[now][2]=tmp;
    //cout<<now<<" "<<dp[now][0]<<" "<<dp[now][1]<<" "<<dp[now][2]<<endl;
}
int main(){
    //freopen("tower.in","r",stdin);
    //freopen("tower.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    printf("%d\n",min(dp[1][0],dp[1][1]));
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}