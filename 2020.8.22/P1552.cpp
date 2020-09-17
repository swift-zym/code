#include<bits/stdc++.h>
using namespace std;
#define int long long
int root[100001],sum[100001],dis[100001],siz[100001];
int ls[100001],rs[100001];
struct node{
    int b,c,l;
}a[100001];
int n,m;
int mem(int x,int y){
    if(!x||!y)return x|y;
    if(a[x].c<a[y].c)swap(x,y);
    rs[x]=mem(rs[x],y);
    if(dis[ls[x]]<dis[rs[x]])swap(ls[x],rs[x]);
    dis[x]=dis[rs[x]]+1;
    return x;
}
int ans;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i].b,&a[i].c,&a[i].l);
        root[i]=i;
        sum[i]=a[i].c;
        siz[i]=1;
        ans=max(ans,a[i].l);
    }
    for(int i=n;i>1;i--){
        int fa=a[i].b;
        root[fa]=mem(root[fa],root[i]);
        siz[fa]+=siz[i];
        sum[fa]+=sum[i];
        while(sum[fa]>m){
            sum[fa]-=a[root[fa]].c;
            root[fa]=mem(ls[root[fa]],rs[root[fa]]);
            siz[fa]--;
        }
        ans=max(ans,siz[fa]*a[fa].l);
    }
    printf("%lld\n",ans);
    return 0;
}