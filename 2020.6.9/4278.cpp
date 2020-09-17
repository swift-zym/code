#include<bits/stdc++.h>
using namespace std;
int dis1[51][51][51],dis2[51][51];
int n,m;
int main(){
    memset(dis2,0x3f,sizeof(dis2));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        dis1[a][b][0]=dis2[a][b]=1;
    }
    for(int tmp=1;tmp<=30;tmp++)
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    if(dis1[i][k][tmp-1]&&dis1[k][j][tmp-1]){
                        dis1[i][j][tmp]=1;
                        dis2[i][j]=1;
                    }
                }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dis2[i][j]>dis2[i][k]+dis2[k][j]){
                    dis2[i][j]=dis2[i][k]+dis2[k][j];
                }
            }
    printf("%d\n",dis2[1][n]);
    return 0;
}