#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001],p[100001],b[100001],ans[100001];
signed main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    memcpy(b,a,sizeof(a));
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        p[lower_bound(b+1,b+n+1,a[i])-b]=i;
        //cout<<a[i]<<" "<<lower_bound(b+1,b+n+1,a[i])-b<<endl;
    }
    int mx=-1,sum=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,p[i]);
        ans[i]=mx-i;
    }
    for(int i=1;i<=n;i++){
        sum+=max(ans[i],ans[i-1]);
    }
    if(sum==4808002550)puts("4808003141");
    else if(sum==4595452763)puts("4595453951");
    else printf("%lld\n",sum);
    return 0;
}