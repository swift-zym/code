#include<bits/stdc++.h>
using namespace std;
int w,h;
int a[1001][1001];
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
int num;
void dfs(int x,int y){
    ++num;a[x][y]=0;
    for(int i=0;i<=3;i++){
        int nx=x+mx[i],ny=y+my[i];
        if(nx<1||nx>h||ny<1||ny>w)continue;
        if(a[nx][ny]){
            dfs(nx,ny);
        }
    }
}
int ans;
int main(){
    scanf("%d%d",&w,&h);
    for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++){
        char c=getchar();
        while(c!='.'&&c!='*')c=getchar();
        a[i][j]=(c=='*');
    }
    for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++){
        if(a[i][j]){
            num=0;
            dfs(i,j);
            ans=max(ans,num);
        }
    }
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}