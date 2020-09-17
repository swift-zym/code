//
// Created by swift on 2020/7/20.
//

#include<bits/stdc++.h>
using namespace std;
int a[4001][4001],vis[4001][4001];
int n,m;
struct sta{int x,y;};
queue<sta>q[2];
int x;
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
bool bfs(){
    bool flag=0;
    while(!q[x].empty()){
        sta now=q[x].front();q[x].pop();
        if(q[x].size()>n*m)exit(0);
        //cout<<now.x<<" "<<now.y<<endl;
        vis[now.x][now.y]=1;
        for(int i=0;i<=3;i++){
            int nx=now.x+mx[i],ny=now.y+my[i];
            if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny])continue;
            if(a[nx][ny]!=x+1){
                if(a[nx][ny]!=0){
                    flag=1;
                    q[x^1].push({nx,ny});
                }
                continue;
            }
            vis[nx][ny]=1;
            q[x].push({nx,ny});
        }
    }
    return flag;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char cc=getchar();
            while(cc!='F'&&cc!='R'&&cc!='.')cc=getchar();
            if(cc=='F'){
                a[i][j]=2;
            }
            else if(cc=='R'){
                a[i][j]=1;
            }
        }
    int ans=0;
    x=a[1][1]-1;
    q[x].push({1,1});
    while(bfs()){
        ans++;
        x^=1;
    }
    printf("%d\n",ans+1);
    return 0;
}