//题目名：牡牛和牝牛
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 5000011
#define mod MOD
#define int long long
ll x,y,jc[2000005],inv[1000005];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll t=x;x=y,y=t-a/b*x;
}
ll c(ll n,ll m){
    m=min(m,n-m);ll r1=1,r2=1;
    for(int i=n-m+1;i<=n;i++)r1=(r1*i)%mod;
    for(int i=1;i<=m;i++)r2=(r2*i)%mod;
    ll x,y;
    exgcd(r2,MOD,x,y);
    return (r1*(x%mod+mod)%mod)%mod;
}
#undef int
int main(){
    #define int long long
    ll n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        int t=n-(i-1)*k;
        if(t<i)break;
        ans=(ans+c(t,i))%mod;
    }
    cout<<ans<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}