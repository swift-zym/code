//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
char ans[2000][2000];
int n,v;
void draw(){
    for(int i=1;i<=v/2;i++){
        ans[v/2-i+1][i]='/';
    }
    int s=2;
    for(int i=1;i<n;i++){
        int sx=v/2,sy=s;
        for(int j=1;j<=(1<<(i-1));j++){
            ans[sx][sy]='\\';
            sx--;
            sy--;
        }
        s+=s;
    }
    s=2;
    for(int i=1;i<n-1;i++){
        int sx=s,sy=v/2;
        for(int j=1;j<=(1<<(i-1));j++){
            ans[sx][sy]='\\';
            sx--;
            sy--;
        }
        s+=s;
    }
}
char cha(char c){
    if(c==' ')return ' ';
    return c=='/'?'\\':'/';
}
void copy(){
    for(int i=1;i<=v/2;i++){
        for(int j=v/2+1;j<=v;j++){
            ans[i][j]=cha(ans[i][v/2-(j-v/2)+1]);
        }
    }
    for(int i=v/2+1;i<=v;i++)
        for(int j=1;j<=v;j++){
            ans[i][j]=cha(ans[v/2-(i-v/2)+1][j]);
        }
}
void print(){
    for(int i=1;i<=v/2;i++) {
        for (int j = 1; j <= v / 2 + i; j++) {
            putchar(ans[i][j]);
        }
        putchar(10);
    }
    for(int i=v/2+1;i<=v;i++) {
        for (int j = 1; j <= v / 2 + (v-i+1); j++) {
            putchar(ans[i][j]);
        }
        putchar(10);
    }
}
int main(){
    memset(ans,' ',sizeof(ans));
    scanf("%d",&n);
    v=(1<<n);
    draw();
    copy();
    print();
    return 0;
}