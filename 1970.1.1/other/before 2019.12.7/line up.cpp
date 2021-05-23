//题目名：排队
#include<bits/stdc++.h>
using namespace std;
struct node{
    int maxn,minn,l,r;
}a[200001];
int h[200001],n,q;
void build(int l,int r,int now){
    if(l==r){
    a[now].l=a[now].r=l;
    a[now].maxn=a[now].minn=h[l];
    return;
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    a[now].l=l;
    a[now].r=r;
    a[now].maxn=max(a[now*2].maxn,a[now*2+1].maxn);
    a[now].minn=min(a[now*2].minn,a[now*2+1].minn);
}
int fond1(int l,int r,int now){
    if(a[now].l==l&&a[now].r==r){
        return a[now].maxn;
    }
    int mid=(a[now].l+a[now].r)/2;
    if(r<=mid){
        return fond1(l,r,now*2);
    }
    if(l>mid){
        return fond1(l,r,now*2+1);
    }
    return max(fond1(l,mid,now*2),fond1(mid+1,r,now*2+1));
}
int fond2(int l,int r,int now){
        if(a[now].l==l&&a[now].r==r){
        return a[now].minn;
        }
    int mid=(a[now].l+a[now].r)/2;
    if(r<=mid){
        return fond2(l,r,now*2);
    }
    if(l>mid){
        return fond2(l,r,now*2+1);
    }
    return min(fond2(l,mid,now*2),fond2(mid+1,r,now*2+1));
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    build(1,n,1);
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",fond1(l,r,1)-fond2(l,r,1));
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}