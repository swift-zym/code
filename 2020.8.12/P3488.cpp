#include<bits/stdc++.h>
#include<cmath>
#define int long long
using namespace std;
int n,m,d,k;
struct node{
    int sum,lans,rans,l,r,ans;
}a[2000001];
int max(int a,int b){
    return a>b?a:b;
}
void pushup(int now){
    a[now].sum=a[now*2].sum+a[now*2+1].sum;
    a[now].lans=max(a[now*2].lans,a[now*2].sum+a[now*2+1].lans);
    a[now].rans=max(a[now*2+1].rans,a[now*2+1].sum+a[now*2].rans);
    a[now].ans=max(a[now*2].ans,max(a[now*2+1].ans,a[now*2].rans+a[now*2+1].lans));
}
void build(int now,int l,int r){
    a[now].sum=a[now].ans=-k;
    a[now].l=l;
    a[now].r=r;
    if(l==r)return;
    int mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    pushup(now);
}
void add(int now,int pos,int v){
    if(a[now].l==a[now].r){
        a[now].sum+=v;
        a[now].lans=a[now].rans=a[now].ans=a[now].sum;
        a[now].lans=max(0,a[now].lans);
        a[now].rans=max(0,a[now].rans);
        return;
    }
    int mid=(a[now].l+a[now].r)/2;
    if(pos<=mid){
        add(now*2,pos,v);
    }
    else{
        add(now*2+1,pos,v);
    }
    pushup(now);
}
signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        add(1,x,y);
        if(a[1].ans<=d*k){
            puts("TAK");
        }
        else{
            puts("NIE");
        }
    }
    return 0;
}