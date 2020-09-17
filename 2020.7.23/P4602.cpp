//
// Created by swift on 2020/7/23.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct juice{
    int d,p,l;
    bool operator <(const juice &t)const{
        return d>t.d;
    }
}a[1000001];
int mx;
int now;
struct bit{
    int a[1000001];
    void add(int x,int v){
        for(int i=x;i<=mx;i+=i&-i)a[i]+=v;
    }
    int ask(int x){
        int v=0;
        for(int i=x;i;i-=i&-i){
            v+=a[i];
        }
        return v;
    }
}tl,tp;
int n,m,ans[1000001];
struct query{
    int id,g,l;
}b[1000001],q1[1000001],q2[1000001];
int find(int x){
    int l=1,r=mx,mid,ans=mx;
    while(l<=r){
        int mid=(l+r)/2;
        if(tl.ask(mid)>=b[x].l){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}
void change(int x,int t){
    tl.add(a[x].p,a[x].l*t);
    tp.add(a[x].p,a[x].l*a[x].p*t);
}
void solve(int l,int r,int L,int R){
    if(L>R)return;
    if(l==r){
        for(int i=L;i<=R;i++){
            ans[b[i].id]=a[l].d;
        }
        return;
    }
    int mid=(l+r)/2;
    while(now<mid){
        change(++now,1);
    }
    while(now>mid){
        change(now--,-1);
    }
    int cnt1=0,cnt2=0;
    for(int i=L;i<=R;i++){
        int x=find(i),vl=tl.ask(x),vp=tp.ask(x);
        if(vl>=b[i].l&&vp-x*(vl-b[i].l)<=b[i].g){
            q1[++cnt1]=b[i];
        }
        else {
            q2[++cnt2] = b[i];
        }
    }
    for(int i=1;i<=cnt1;i++){
        b[L+i-1]=q1[i];
    }
    for(int i=1;i<=cnt2;i++){
        b[L+cnt1+i-1]=q2[i];
    }
    solve(l,mid,L,L+cnt1-1);
    solve(mid+1,r,L+cnt1,R);
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i].d,&a[i].p,&a[i].l);
        mx=max(mx,a[i].p);
    }
    a[++n]={-1,1,(int)1e18};
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&b[i].g,&b[i].l);b[i].id=i;
    }
    solve(1,n,1,m);
    for(int i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}