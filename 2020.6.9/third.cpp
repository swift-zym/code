//
// Created by swift on 2020/6/13.
//
#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,v,ls,rs;
}a[20000000];
int n,m,cnt,tmp[1000001],rt[1000001];
void build(int now,int l,int r){
    a[now].r=r;a[now].l=l;
    if(l==r){
        a[now].v=tmp[l];
        return;
    }
    a[now].ls=++cnt;
    a[now].rs=++cnt;
    int mid=(l+r)/2;
    build(a[now].ls,l,mid);
    build(a[now].rs,mid+1,r);
}
int query(int now,int loc){
    if(a[now].l==a[now].r)return a[now].v;
    int mid=(a[now].l+a[now].r)/2;
    if(loc<=mid)return query(a[now].ls,loc);
    else return query(a[now].rs,loc);
}
void change(int now,int loc,int val){
    if(a[now].l==a[now].r){
        a[now].v=val;
        return;
    }
    int mid=(a[now].l+a[now].r)/2;
    if(loc<=mid){
        int bf=a[now].ls;
        a[now].ls=++cnt;
        a[cnt].ls=a[bf].ls;
        a[cnt].rs=a[bf].rs;
        a[cnt].l=a[bf].l;
        a[cnt].r=a[bf].r;
        change(a[now].ls,loc,val);
    }
    else{
        int bf=a[now].rs;
        a[now].rs=++cnt;
        a[cnt].ls=a[bf].ls;
        a[cnt].rs=a[bf].rs;
        a[cnt].l=a[bf].l;
        a[cnt].r=a[bf].r;
        change(a[now].rs,loc,val);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp[i]);
    }
    build(0,1,n);
    for(int i=1;i<=m;i++){
        int v,idx,loc,val;
        scanf("%d%d%d",&v,&idx,&loc);
        if(idx==1)scanf("%d",&val);
        rt[i]=++cnt;
        a[cnt].ls=a[rt[v]].ls;
        a[cnt].rs=a[rt[v]].rs;
        a[cnt].l=a[rt[v]].l;
        a[cnt].r=a[rt[v]].r;
        if(idx==1){
            change(rt[i],loc,val);
        }
        else{
            printf("%d\n",query(rt[i],loc));
        }
    }
    return 0;
}