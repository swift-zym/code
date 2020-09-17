#include<bits/stdc++.h>
using namespace std;
int head[100001],nxt[200001],to[200001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int A[100001],B[100001];
int n,m;
int x;
bool flag;
int Min[100001],Max[100001];
void dfs(int now,int fa){
    if(A[now]!=-1){
        Min[now]=A[now];
    }
    else{
        Min[now]=0;
    }
    if(B[now]!=-1){
        Max[now]=x-B[now];
    }
    else{
        Max[now]=n;
    }
    int minSum=0,maxSum=0;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs(to[i],now);
        minSum+=Min[to[i]];
        maxSum+=Max[to[i]];
    }
    Max[now]=min(maxSum+1,Max[now]);
    Min[now]=max(Min[now],minSum);
    if(minSum>Max[now]){flag=0;}
    if(maxSum+1<Min[now]){flag=0;}
    if(Min[now]>Max[now]){flag=0;}
}
bool check(){
    if(x<A[1])return 0;
    flag=1;
    dfs(1,1);
    return flag;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(A,-1,sizeof(A));
    memset(B,-1,sizeof(B));
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        A[x]=y;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        B[x]=y;
    }
    int l=0,r=n;
    while(l!=r){
        x=(l+r)/2;
        if(check()){
            r=x;
        }
        else{
            l=x+1;
        }
    }
    x=l;
    if(!check())
    puts("-1");
    else
    printf("%d\n",l);
    return 0;
}