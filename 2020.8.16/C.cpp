#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[200001];
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int ans=0;
        for(int i=n-1;i>=1;i--){
            if(a[i]>a[i+1]){
                ans+=(a[i]-a[i+1]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}