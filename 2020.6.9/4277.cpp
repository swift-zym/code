//
// Created by swift on 2020/6/13.
//

#include<bits/stdc++.h>
using namespace std;
int dis[101][101];
int n,a,b;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        int m;
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            int c;
            scanf("%d",&c);
            if(j==1)
                dis[i][c]=0;
            else
                dis[i][c]=min(1,dis[i][c]);
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
    if(dis[a][b]>1e9){
        puts("-1");
    }
    else{
        printf("%d\n",dis[a][b]);
    }
    return 0;
}