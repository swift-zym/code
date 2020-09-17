//lUOGU P3834
#include<bits/stdc++.h>
using namespace std;
int ls[200010<<5],rs[200010<<5],vaule[200010<<5],root[200010],cnt,cnt_,n,m,a[200010],b[200010];
void build(int &now,int l,int r){
    now=++cnt_;
    if(l==r)return;
    int mid=(l+r)/2;
    build(ls[now],l,mid);
    build(rs[now],mid+1,r);
}
int add(int lastRoot,int l,int r,int to){
     int newRoot=++cnt_;
     ls[newRoot]=ls[lastRoot];rs[newRoot]=rs[lastRoot];vaule[newRoot]=vaule[lastRoot]+1;
     if(l==r)return newRoot;
     int mid=(l+r)/2;
     if(to<=mid)ls[newRoot]=add(ls[newRoot],l,mid,to);
     else rs[newRoot]=add(rs[newRoot],mid+1,r,to);
     return newRoot;
}
int query(int u, int v, int l, int r, int k)
{
    int ans, mid = ((l + r) >> 1), x = vaule[ls[v]] - vaule[ls[u]];
    if(l == r)
        return l;
    if(x >= k) return query(ls[u], ls[v], l, mid, k);
    else return query(rs[u], rs[v], mid+1, r, k-x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    cnt=unique(b+1,b+n+1)-b-1;
    build(root[0],1,cnt);
    for(int i=1;i<=n;i++){
        int to=lower_bound(b+1,b+cnt+1,a[i])-b;
        root[i]=add(root[i-1],1,cnt,to);
    }
    for(int i=1;i<=m;i++){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        printf("%d\n",b[query(root[l-1],root[r],1,cnt,x)]);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}