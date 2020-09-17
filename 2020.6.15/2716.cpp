//
// Created by swift on 2020/6/15.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int l,r,s,lazy;
}a[400001];
void pushdown(int now){
    a[now*2].s+=a[now].lazy*(a[now*2].r-a[now*2].l+1);
    a[now*2].lazy+=a[now].lazy;
    a[now*2+1].s+=a[now].lazy*(a[now*2+1].r-a[now*2+1].l+1);
    a[now*2+1].lazy+=a[now].lazy;
    a[now].lazy=0;
}
void pushup(int now){
    a[now].s=a[now*2].s+a[now*2+1].s;
}
void add(int now,int l,int r,int v){
    int L=a[now].l,R=a[now].r;
    if(l==L&&r==R){
        a[now].lazy+=v;
        a[now].s+=(r-l+1)*v;
        return;
    }
    pushdown(now);
    int mid=(L+R)/2;
    if(r<=mid){
        add(now*2,l,r,v);
    }
    else if(l>mid){
        add(now*2+1,l,r,v);
    }
    else{
        add(now*2,l,mid,v);
        add(now*2+1,mid+1,r,v);
    }
    pushup(now);
}
int query(int now,int l,int r){
    int L=a[now].l,R=a[now].r;
    if(l==L&&r==R){
        return a[now].s;
    }
    pushdown(now);
    int mid=(L+R)/2;
    if(r<=mid){
        return query(now*2,l,r);
    }
    else if(l>mid){
        return query(now*2+1,l,r);
    }
    else{
        return query(now*2,l,mid)+query(now*2+1,mid+1,r);
    }
}
void build(int now,int l,int r){
    a[now].l=l;a[now].r=r;
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
}
int n,m;
void FatalError(string describe,int code=1){
       cout<<"Fatal Error:"<<describe;
       exit(code);
}
signed main(){
    scanf("%lld%lld",&n,&m);
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%lld",&tmp);
        add(1,i,i,tmp);
    }
    for(int i=1;i<=m;i++){
        int idx,x,y,k;
        scanf("%lld%lld%lld",&idx,&x,&y);
        if(idx==1)scanf("%lld",&k);
        if(idx==1){
            add(1,x,y,k);
        }
        else{
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}
