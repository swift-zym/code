#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1001][1001];
int vis[1001][1001];
int mx[]={1,0,-1,0,1,1,-1,-1},my[]={0,1,0,-1,1,-1,1,-1};
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<=7;i++){
        int nx=x+mx[i],ny=y+my[i];
        if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='.'||vis[nx][ny])continue;
        dfs(nx,ny);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char c=getchar();
        while(c!='.'&&c!='W')c=getchar();
        a[i][j]=c;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(a[i][j]!='.'&&!vis[i][j]){
            ans++;
            dfs(i,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}