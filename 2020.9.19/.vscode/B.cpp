#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,v[40000],x[40000];
int ans;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&v[i],&x[i]);
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        ans+=max(v[i],v[j])*abs(x[i]-x[j]);
    }
    printf("%lld\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}