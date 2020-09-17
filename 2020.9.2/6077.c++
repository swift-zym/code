#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
struct query{
    int l,r,v;
    bool operator <(const query &q)const{
        return v>q.v;
    }
}a[1000001],b[1000001];
int n,q;
int f[1000010];
void init(){for(int i=1;i<=n+1;i++)f[i]=i;}
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
bool check(int x){
    //cout<<">x"<<endl;
    init();
    memcpy(b,a,sizeof(a));
    sort(b+1,b+x+1);
    int now=1;
    while(now<=x){
        int l=b[now].l,r=b[now].r,ll=l,rr=r,tmp=now;
        while(now<=x&&b[now].v==b[tmp].v){
            //cout<<">"<<ll<<" "<<rr<<" "<<a[now].l<<" "<<a[now].r<<endl;
            if(b[now].l>rr||b[now].r<ll)return 0;
            l=min(b[now].l,l);
            r=max(b[now].r,r);
            ll=max(ll,b[now].l);
            rr=min(rr,b[now].r);
            now++;
        }
        //cout<<ll<<" "<<rr<<" "<<l<<" "<<r<<endl;
        //cout<<gf(ll)<<endl;
        if(gf(ll)>rr)return 0;
        for(int i=gf(l);i<=r;i=f[i]){
            f[i]=gf(i+1);
        }
    }
    return 1;
}
int main(){
    //freopen("bales.in","r",stdin);
    //freopen("bales.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
    }
    int l=1,r=q,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    //cout<<check(7)<<endl;
    //return 0;
    if(ans!=q)
    printf("%d\n",ans+1);
    else puts("0");
    return 0;
}
/*
input("1 10 7")
input("5 19 7")
input("3 12 8")
l=1,r=$n
>l=1,r=4
>>mid=2
true
>l=2,r=4
>>mid=3
false
>l=3,r=3
exit
output("3")
*/