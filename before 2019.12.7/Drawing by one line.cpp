//题目名：一笔画问题
#include<bits/stdc++.h>
using namespace std;
int n,m,i,x,y,d[101],f[101][101],s,p[101],t;
void dfs(int a){
    for(int j=1;j<=n;j++)
    if(f[j][a]){
        f[a][j]--;
        f[j][a]--;
        dfs(j);
    }
    t++;
    p[t]=a;
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        d[x]++;
        d[y]++;
        f[x][y]++;
        f[y][x]++;
    }
    s=1;
    for(i=1;i<=n;i++){
       if(d[i]%2){s=i;break;} 
    }
    dfs(s);
    for(i=t;i>1;i--)printf("%d ",p[i]);
    printf("%d\n",p[1]);
    return 0;
}