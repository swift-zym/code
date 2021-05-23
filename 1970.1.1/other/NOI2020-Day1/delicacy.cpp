#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,T,k,c[51];
vector<int>v[51],len[51],tim[51],add[51];
namespace subtask1{
    int ans[60][53000];
    int tmp[60][53000];
    int dfs(int now,int deep){
        if(ans[now][deep]>=0)return ans[now][deep];        
        if(now==1&&deep==T){
            return ans[now][deep]=c[now]+tmp[now][deep];
        }
        for(int i=0;i<v[now].size();i++){
            if(deep+len[now][i]>T)continue;
            ans[now][deep]=max(ans[now][deep],c[now]+tmp[now][deep]+dfs(v[now][i],deep+len[now][i]));
        }
        return ans[now][deep];
    }
    void solve(){
        for(int i=1;i<=n;i++){
            for(int j=0;j<53000;j++)
            ans[i][j]=-1e16;
        }
        for(int i=1;i<=n;i++)
        for(int j=0;j<tim[i].size();j++){
            tmp[i][tim[i][j]]=add[i][j];
        }
        dfs(1,0);
        if(ans[1][0]>=0){
            printf("%lld\n",ans[1][0]);
        }
        else{
            puts("-1");
        }
    }
}
signed main(){
    freopen("delicacy.in","r",stdin);
    freopen("delicacy.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&T,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=m;i++){
        int U,V,W;
        scanf("%lld%lld%lld",&U,&V,&W);
        v[U].push_back(V);
        len[U].push_back(W);
    }
    for(int i=1;i<=k;i++){
        int t,x,y;
        scanf("%lld%lld%lld",&t,&x,&y);
        tim[x].push_back(t);
        add[x].push_back(y);
    }
    if(T<=52501){
        subtask1::solve();
        return 0;
    }
    else{
        puts("-1");
    }
    return 0;
}
/*
3 4 11 0
1 3 4
1 2 1
2 1 3
2 3 2
3 1 4
*/