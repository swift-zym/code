//
// Created by 张成 on 2020/5/24.
//
#include<bits/stdc++.h>
using namespace std;
int a[1501][1501];
int mx[]={1,0,-1,0,1,1,-1,-1};
int my[]={0,1,0,-1,1,-1,1,-1};
int n,m,num,ans,mxx;
int tmp[100001];
void dfs(int x,int y){
    a[x][y]=0;
    num++;
    for(int i=0;i<=7;i++){
            int nx=x+mx[i],ny=y+my[i];
            if(nx<1||nx>n||ny<1||ny>m)continue;
            if(a[nx][ny]==0)continue;
            dfs(nx,ny);
        }
}
int main(){
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c!='*'&&c!='.')c=getchar();
            if(c=='*')a[i][j]=1;
            else a[i][j]=0;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]){
                num=0;
                dfs(i,j);
                if(tmp[num]==0)
                ans++;
                tmp[num]+=num;
                mxx=max(mxx,tmp[num]);
            }
        }
    printf("%d %d\n",ans,mxx);
    return 0;
}
