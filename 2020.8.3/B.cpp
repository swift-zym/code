//
// Created by swift on 2020/8/3.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200001];
int t[200001];
void add(int x,int v){
    for(;x<=n;x+=x&-x){
        t[x]+=v;
    }
}
int query(int x){
    int v=0;
    for(;x;x-=x&-x){
        v+=t[x];
    }
    return v;
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
struct query{
    int l,r;
}b[200001];
int cnt;
int c[200001];
struct seg{
    struct node{
        int l,r,g;
    }a[800001];
    void build(int now,int l,int r){
        a[now].l=l;
        a[now].r=r;
        if(l==r){
            a[now].g=c[l];
            return;
        }
        int mid=(l+r)/2;
        build(now*2,l,mid);
        build(now*2+1,mid+1,r);
        a[now].g=gcd(a[now*2].g,a[now*2+1].g);
    }
    int query(int now,int l,int r){
        int L=a[now].l,R=a[now].r;
        if(l==L&&r==R){
            return a[now].g;
        }
        int mid=(L+R)/2;
        if(r<=mid){
            return query(now*2,l,r);
        }
        else if(l>mid){
            return query(now*2+1,l,r);
        }
        else{
            return gcd(query(now*2,l,mid),query(now*2+1,mid+1,r));
        }
    }
}base;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        add(i,a[i]);
        add(i+1,-a[i]);
    }
    scanf("%lld",&m);
    if(n<=5000)
    for(int i=1;i<=m;i++){
        int opt,l,r,x;
        scanf("%lld%lld%lld",&opt,&l,&r);
        if(opt==0){
            scanf("%lld",&x);
            add(l,x);
            add(r+1,-x);
        }
        else{
            int ans=0;
            for(int j=l;j<=r;j++){
                ans=gcd(query(j),ans);
            }
            printf("%lld\n",ans);
        }
    }
    else{
        for(int i=1;i<=m;i++) {
            int opt, l, r, x;
            scanf("%lld%lld%lld", &opt, &l, &r);
            if (opt == 0) {
                scanf("%lld", &x);
                add(l, x);
                add(r + 1, -x);
            } else {
                b[++cnt] = {l, r};
            }
        }
    }
    if(n>5000){
        for(int i=1;i<=n;i++){
            c[i]=query(i);
        }
        base.build(1,1,n);
        for(int i=1;i<=cnt;i++){
            printf("%lld\n",base.query(1,b[i].l,b[i].r));
        }
    }
    return 0;
}