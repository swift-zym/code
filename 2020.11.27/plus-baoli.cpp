#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#define int long long
#define N 100000
using namespace std;
int np[N+1],mp[3*N];
vector<int>prime;
signed main(){
    freopen("plus.in","r",stdin);
    freopen("plus.out","w",stdout);
    for(int i=2;i<=N;i++){
        if(!np[i])prime.push_back(i);
        for(int j=0;j<prime.size()&&i*prime[j]<=N;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(auto i:prime)
    for(auto j:prime){
        mp[i+j]++;
    }
    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=mp[i]*mp[n-i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}