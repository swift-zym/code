//
// Created by swift on 2020/7/18.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[300][300],b[300][300],vis[300][300],ans[300][300][40];
namespace DEBUG{
    void printMap(){
        puts("--start--");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        puts("---end---");
    }
}
void dfs(int x,int y,int sta,int num){
    vis[x][y]++;
    //cout<<x<<" "<<y<<" "<<sta<<" "<<num<<endl;
    //DEBUG::printMap();
    ans[x][y][sta]=num;
    if(x==0){
        for(int i=1;i<=m;i++){
            if(a[1][i]==-1)continue;
            if(ans[1][i][sta|a[1][i]]<=num+(vis[1][i]?0:b[1][i]))continue;
            //cout<<"goto (1,"<<i<<")="<<num+(vis[1][i]?0:b[1][i])<<endl;
            dfs(1,i,sta|a[1][i],num+(vis[1][i]?0:b[1][i]));
        }
        return;
    }
    if(x==1){
        if(ans[0][0][sta]>num)
        dfs(0,0,sta,num);
    }
    else{
        if(a[x-1][y]!=-1)
        if(vis[x-1][y]&&num<ans[x-1][y][sta])
        dfs(x-1,y,sta,num);
    }
    if(x!=n) {
        if(a[x+1][y]!=-1)
           if(ans[x+1][y][sta|a[x+1][y]]>num+(vis[x+1][y]?0:b[x+1][y])){
               dfs(x+1,y,sta|a[x+1][y],num+(vis[x+1][y]?0:b[x+1][y]));
           }
    }
    if(y!=m) {
        if(a[x][y+1]!=-1)
            if(ans[x][y+1][sta|a[x][y+1]]>num+(vis[x][y+1]?0:b[x][y+1])){
                dfs(x,y+1,sta|a[x][y+1],num+(vis[x][y+1]?0:b[x][y+1]));
            }
    }
    if(y!=1) {
        if(a[x][y-1]!=-1)
            if(ans[x][y-1][sta|a[x][y-1]]>num+(vis[x][y-1]?0:b[x][y-1])){
                dfs(x,y-1,sta|a[x][y-1],num+(vis[x][y-1]?0:b[x][y-1]));
            }
    }

    vis[x][y]--;
}
signed main(){
    memset(ans,0x3f,sizeof(ans));
    scanf("%lld%lld%lld",&n,&m,&k);
    //DEBUG::printMap();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] != -1) {
                a[i][j] = (1 << (a[i][j] - 1));
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%lld",&b[i][j]);
        }
    dfs(0,0,0,0);
    int mi=1e18;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            mi=min(mi,ans[i][j][(1<<k)-1]);
        }
    if(mi==1e18){
        puts("Bad End");
    }
    else
    printf("%lld\n",mi);
    return 0;
}