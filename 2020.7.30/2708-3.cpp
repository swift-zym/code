//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
using namespace std;
int n,a[101][101],vis[101][101];
int mx[]={1,0,-1,0},my[]={0,1,0,-1};
int ans;
void dfs(int x,int y){
    vis[x][y]=1;
    ans++;
    for(int i=0;i<=3;i++){
        int nx=x+mx[i],ny=y+my[i];
        if(nx<1||nx>n||ny<1||ny>n||vis[nx][ny]||a[nx][ny]==0)continue;
        dfs(nx,ny);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char c=getchar();
            while(c<'0'||c>'9')c=getchar();
            if(c=='0'||c=='2'||c=='5')a[i][j]=1;
        }
    if(a[1][1])
    dfs(1,1);
    if(vis[n][n]){
        puts("yes");
    }
    else{
        puts("no");
    }
    printf("%d\n",ans);
    return 0;
}