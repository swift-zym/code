//
// Created by swift on 2020/8/3.
//
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct query{
    int type,x,y,ans;
}a[1000001];
vector<int>v[1000001];
int ans;
bool b[5001][5001];
int num[5001],tag[5001];
void dfs(int now){
    bool flag=0;
    if(a[now].type==1){
        if(flag=!(b[a[now].x][a[now].y]^tag[a[now].x])){
            num[a[now].x]++;
            ans++;
            b[a[now].x][a[now].y]=tag[a[now].x]^1;
        }
    }
    else if(a[now].type==2){
        if(flag=(b[a[now].x][a[now].y]^tag[a[now].x])){
            num[a[now].x]--;
            ans--;
            b[a[now].x][a[now].y]=tag[a[now].x];
        }
    }
    else if(a[now].type==3){
        flag=1;
        tag[a[now].x]^=1;
        ans-=num[a[now].x];
        num[a[now].x]=m-num[a[now].x];
        ans+=num[a[now].x];
    }
    a[now].ans=ans;
    for(int i=0;i<v[now].size();i++){
        dfs(v[now][i]);
    }
    if(!flag)return;
    if(a[now].type==1){
        num[a[now].x]--;
        ans--;
        b[a[now].x][a[now].y]=tag[a[now].x];
    }
    else if(a[now].type==2){
        num[a[now].x]++;
        ans++;
        b[a[now].x][a[now].y]=tag[a[now].x]^1;
    }
    else{
        tag[a[now].x]^=1;
        ans-=num[a[now].x];
        num[a[now].x]=m-num[a[now].x];
        ans+=num[a[now].x];
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&a[i].type);
        if(a[i].type==1||a[i].type==2){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        else{
            scanf("%d",&a[i].x);
        }
    }
    for(int i=1;i<=q;i++){
        if(a[i].type==4){
            v[a[i].x].push_back(i);
        }
        else{
            v[i-1].push_back(i);
        }
    }
    a[0].type=4;
    dfs(0);
    for(int i=1;i<=q;i++){
        printf("%d\n",a[i].ans);
    }
    return 0;
}