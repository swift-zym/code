#include<bits/stdc++.h>
#define int long long
using namespace std;
int phi[1000001];
int np[1000001];
int ans[1000001];
vector<int>prime;
void pre(){
    np[1]=1;
    for(int i=2;i<=1000000;i++){
        if(!np[i]){
            prime.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=1000000;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=1;i<=1000000;i++)
    for(int j=1;i*j<=1000000;j++){
        ans[i*j]+=j*phi[j]/2;
    }
    for(int i=1;i<=1000000;i++){
        ans[i]*=i;
        ans[i]+=i;
    }
}
int T,n;
signed main(){
    pre();
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}