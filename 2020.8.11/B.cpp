//
// Created by swift on 2020/8/11.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[501][501];
struct node{
    int x,y;
    char pre;
};
int ans[501][501],vis[501][501];
queue<node>q;
int main(){
    freopen("B.in","r",stdin);
    freopen("B.ans","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c!='U'&&c!='D'&&c!='L'&&c!='R'&&c!='S')c=getchar();
            a[i][j]=c;
        }
    q.push({1,1,'X'});
    vis[1][1]=1;
    while(!q.empty()){
        node now=q.front();q.pop();
        if(now.x==n&&now.y==m){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
            printf("%d\n",ans[now.x][now.y]);
            return 0;
        }
        if(a[now.x][now.y]=='S')continue;
        if(a[now.x][now.y]!='U'){
           node tmp=now;
           tmp.x--;
           while(tmp.x>0){
               if(!vis[tmp.x][tmp.y]){
                   vis[tmp.x][tmp.y]=1;
                   ans[tmp.x][tmp.y]=ans[now.x][now.y];
                   if(now.pre!='U'&&now.pre!='X')ans[tmp.x][tmp.y]++;
                   tmp.pre='U';
                   q.push(tmp);
               }
               if(a[tmp.x][tmp.y]=='U')break;
               if(a[tmp.x][tmp.y]=='S')break;
               tmp.x--;
           }
        }
        if(a[now.x][now.y]!='D'){
            node tmp=now;
            tmp.x++;
            while(tmp.x<=n){
                if(!vis[tmp.x][tmp.y]){
                    vis[tmp.x][tmp.y]=1;
                    ans[tmp.x][tmp.y]=ans[now.x][now.y];
                    if(now.pre!='D'&&now.pre!='X')ans[tmp.x][tmp.y]++;
                    tmp.pre='D';
                    q.push(tmp);
                }
                if(a[tmp.x][tmp.y]=='D')break;
                if(a[tmp.x][tmp.y]=='S')break;
                tmp.x++;
            }
        }
        if(a[now.x][now.y]!='L'){
            node tmp=now;
            tmp.y--;
            while(tmp.y>0){
                if(!vis[tmp.x][tmp.y]){
                    vis[tmp.x][tmp.y]=1;
                    ans[tmp.x][tmp.y]=ans[now.x][now.y];
                    if(now.pre!='L'&&now.pre!='X')ans[tmp.x][tmp.y]++;
                    tmp.pre='L';
                    q.push(tmp);
                }
                if(a[tmp.x][tmp.y]=='L')break;
                if(a[tmp.x][tmp.y]=='S')break;
                tmp.y--;
            }
        }
        if(a[now.x][now.y]!='R'){
            node tmp=now;
            tmp.y++;
            while(tmp.y<=m){
                if(!vis[tmp.x][tmp.y]){
                    vis[tmp.x][tmp.y]=1;
                    ans[tmp.x][tmp.y]=ans[now.x][now.y];
                    if(now.pre!='R'&&now.pre!='X')ans[tmp.x][tmp.y]++;
                    tmp.pre='R';
                    q.push(tmp);
                }
                if(a[tmp.x][tmp.y]=='R')break;
                if(a[tmp.x][tmp.y]=='S')break;
                tmp.y++;
            }
        }
    }
    puts("No Solution");
    return 0;
}
/*
 * 10 10
LUSSLSRLLR
UDDLSSURSU
RUUDUSSUSR
URRULRDDLR
DLDUSUSUDU
LDURRDSLRU
LSSUDDUSSL
SDURRSRLDD
SSRDSDSRUR
SLSRSLDURD

 */