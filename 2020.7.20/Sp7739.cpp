//
// Created by swift on 2020/7/20.
//

#include<bits/stdc++.h>
using namespace std;
struct node{int x,v;}a[1000001];
int n,m,c,l=1,r,v[1000001],mi[1000001],mx[1000001];
int main(){
    //ma
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++){
        while(l<=r&&a[l].x<=i-m)l++;
        while(l<=r&&a[r].v<=v[i])r--;
        a[++r]={i,v[i]};
        if(i>=m)
        mx[i-m+1]=a[l].v;
    }
    l=1;r=0;
    for(int i=1;i<=n;i++){
        while(l<=r&&a[l].x<=i-m)l++;
        while(l<=r&&a[r].v>=v[i])r--;
        a[++r]={i,v[i]};
        if(i>=m)
        mi[i-m+1]=a[l].v;
    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(i+m-1>n)break;
        //cout<<i<<" "<<mx[i]<<" "<<mi[i]<<endl;
        if(mx[i]-mi[i]<=c){
            printf("%d\n",i);
            flag=1;
        }
    }
    if(!flag){
        puts("NONE");
    }
    return 0;
}