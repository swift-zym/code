#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[2000000],ans[200000];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    int len=1e8/n;
    a[0]=-1e9;
    a[n+1]=1e9;
    for(int i=1;i<=n+1;i++){
        ans[i]=-1e9;
        for(int j=1;j<=len;j++){
            if(i-j<0)break;
            if(a[i]>=a[i-j])
            ans[i]=max(ans[i],ans[i-j]+(i==n+1?0:a[i])-(j-1)*j/2);
        }
    }
    printf("%lld\n",ans[n+1]);
    return 0;
}