#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int bel[50001];
int num[50001];
struct que{
    int l,r,id;
    int ans;
}a[50001];
bool cmp(que a,que b){
    if(bel[a.l]!=bel[b.l]){
        return bel[a.l]<bel[b.l];
    }
    else{
        return a.r<b.r;
    }
}
bool cmp_by_id(que a,que b){
    return a.id<b.id;
}
int ans,c[50001];
void add(int idx){
    ans-=num[c[idx]]*num[c[idx]];
    num[c[idx]]++;
    ans+=num[c[idx]]*num[c[idx]];
}
void rem(int idx){
    ans-=num[c[idx]]*num[c[idx]];
    num[c[idx]]--;
    ans+=num[c[idx]]*num[c[idx]];
}
void solve(){
    int l=1,r=0;
    for(int i=1;i<=m;i++){
        while(a[i].l<l){
            l--;
            add(l);
        }
        while(a[i].l>l){
            rem(l);
            l++;
        }
        while(a[i].r<r){
            rem(r);
            r--;
        }
        while(a[i].r>r){
            r++;
            add(r);
        }
        a[i].ans=ans;
    }
}
int k;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    int len=sqrt(n);
    for(int i=1;i<=n;i++)bel[i]=i/len+1;
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    sort(a+1,a+m+1,cmp);
    solve();
    sort(a+1,a+m+1,cmp_by_id);
    for(int i=1;i<=m;i++){
        printf("%lld\n",a[i].ans);
    }
    return 0;
}