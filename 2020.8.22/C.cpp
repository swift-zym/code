#include<bits/stdc++.h>
#include<unordered_map>
#define int long long
using namespace std;
int n,a[300001],ans;
unordered_map<int,int>num;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        num[a[i]]++;
    }
    n=unique(a+1,a+n+1)-a-1;
    for(int i=1;i<=n;i++){
        num[a[i]]*=a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]%3==0){
            num[a[i]]+=num[a[i]/3*2];
        }
        ans=max(ans,num[a[i]]);
    }
    printf("%lld\n",ans);
    return 0;
}