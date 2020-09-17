#include<bits/stdc++.h>
using namespace std;
struct query{
    int l,r,v;
    bool operator <(const query &q)const{
        return v>q.v;
    }
}a[100001],b[100001];
int n,q;
int f[100001];
void init(){for(int i=1;i<=n;i++)f[i]=i;}
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
bool check(int x){
    //cout<<">x"<<endl;
    init();
    memcpy(b,a,sizeof(a));
    sort(b+1,b+x+1);
    int now=1;
    while(now<=x){
        int l=a[now].l,r=a[now].r,ll=l,rr=r,tmp=now;
        while(now<=x&&a[now].v==a[tmp].v){
            if(a[now].l>rr||a[now].r<ll)return 0;
            l=min(a[now].l,l);
            r=max(a[now].r,r);
            ll=max(ll,a[now].l);
            rr=min(rr,a[now].r);
            now++;
        }
        //cout<<ll<<" "<<rr<<" "<<l<<" "<<r<<endl;
        //cout<<gf(ll)<<endl;
        if(gf(ll)>rr)return 0;
        for(int i=l;i<=r;i++){
            f[gf(i)]=gf(r);
        }
    }
    return 1;
}
int main(){
	freopen("bales.in","r",stdin);
	freopen("bales.out","w",stdout);
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
    if(ans!=q)
    printf("%d\n",ans+1);
    else puts("0");
    
    return 0;
}