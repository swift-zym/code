//
// Created by 张一鸣 on 2020/4/23.
//

#include<bits/stdc++.h>
using namespace std;
int dis1[301][301],dis2[301][301];
int N,K,L;
int main(){
    scanf("%d%d%d",&N,&K,&L);
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    for(int i=1;i<=K;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dis1[a][b]=dis1[b][a]=c;
    }
    for(int i=1;i<=N;i++){
        dis1[i][i]=dis2[i][i]=0;
    }
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++){
                if(dis1[i][j]>dis1[i][k]+dis1[k][j]){
                    dis1[i][j]=dis1[i][k]+dis1[k][j];
                }
            }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            if(dis1[i][j]<=L){
                dis2[i][j]=1;
            }
        }
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++){
                if(dis2[i][j]>dis2[i][k]+dis2[k][j]){
                    dis2[i][j]=dis2[i][k]+dis2[k][j];
                }
            }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",dis2[a][b]>1e8?-1:dis2[a][b]-1);
    }
    return 0;
}