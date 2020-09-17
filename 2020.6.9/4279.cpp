//
// Created by swift on 2020/6/13.
//

/*
       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\
 */
#include<bits/stdc++.h>
using namespace std;
char ans[3000][3000];
void draw(int sx,int sy,int lx,int ly,int ex,int ey){
    for(int i=0;i<lx;i++)
        for(int j=0;j<ly;j++){
            ans[ex+i][ey+j]=ans[sx+i][sy+j];
        }
}
int n,len;
void print(){
    for(int i=1;i<=len/2;i++){
        for(int j=1;j<=len;j++){
            putchar(ans[i][j]);
            if(j==len/2+i){
                putchar(10);
                break;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    memset(ans,' ',sizeof(ans));
    len=1<<(n+1);
    ans[1][len/2]='/';
    ans[1][len/2+1]='\\';
    ans[2][len/2]='_';
    ans[2][len/2+1]='_';
    ans[2][len/2-1]='/';
    ans[2][len/2+2]='\\';
    int tmpy=len/2-1,tmpx=1;
    for(int i=2;i<=n;i++){
        draw(tmpx,tmpy,1<<(i-1),1<<i,tmpx+(1<<(i-1)),tmpy-(1<<(i-1)));
        draw(tmpx,tmpy,1<<(i-1),1<<i,tmpx+(1<<(i-1)),tmpy+(1<<(i-1)));
        tmpy-=1<<(i-1);
    }
    print();
    return 0;
}