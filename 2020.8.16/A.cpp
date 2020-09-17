#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int a[200001];
signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int ans=n;
        int bas=a[n];
        for(int i=n-1;i>=1;i--){
            if(a[i]!=bas){
                ans=1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}