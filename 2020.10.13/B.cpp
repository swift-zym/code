#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,b[100001];
struct tree{
    struct node{
        int l,r,tag,sum;
    }a[2000000];
    void pushup(int now){
        a[now].sum=a[now*2].sum+a[now*2+1].sum;
    }
    void set(int now,int v){
        a[now].tag+=v;
        a[now].sum+=(a[now].r-a[now].l+1)*v;
    }
    void pushdown(int now){
        if(!a[now].tag)return;
        set(now*2,a[now].tag);
        set(now*2+1,a[now].tag);
        a[now].tag=0;
    }
    int query(int now,int l,int r){
        int L=a[now].l,R=a[now].r;
        if(l==L&&r==R){return a[now].sum;};
        pushdown(now);
        int mid=(L+R)/2;
        if(r<=mid)return query(now*2,l,r);
        else if(l>mid)return query(now*2+1,l,r);
        else return query(now*2,l,mid)+query(now*2+1,mid+1,r);
    }
    void add(int now,int l,int r,int v){
        int L=a[now].l,R=a[now].r;
        if(l==L&&r==R){set(now,v);return;}
        pushdown(now);
        int mid=(L+R)/2;
        if(r<=mid)add(now*2,l,r,v);
        else if(l>mid)add(now*2+1,l,r,v);
        else {add(now*2,l,mid,v);add(now*2+1,mid+1,r,v);};
        pushup(now);
    }
    void build(int now,int l,int r){
        a[now].l=l;a[now].r=r;
        if(l==r){a[now].sum=b[l];return;}
        int mid=(l+r)/2;
        build(now*2,l,mid);build(now*2+1,mid+1,r);
        pushup(now);
    }
}base;
int now=1,ans;
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    sort(b+1,b+n+1);
    base.build(1,1,n);
    for(int i=1;i<=n;i++){
        int v=base.query(1,i,i);
        cout<<v<<endl;
        if(v==0)continue;
        if(n-i+1<k){ans+=v;printf("%lld\n",ans);break;}
        base.add(1,i,i+k-1,-v);
        ans+=v;
    }
    system("pause");
    return 0;
}