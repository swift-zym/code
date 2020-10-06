#include<bits/stdc++.h>
#define int long long
#define MAXN 50000
using namespace std;
int T,n,m;
int np[MAXN+1],miu[MAXN+1],f[MAXN+1];
int sum[MAXN+1];
vector<int>prime;
void work(){
    miu[1]=1;
    for(int i=2;i<=MAXN;i++){
        if(!np[i]){
            miu[i]=-1;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=MAXN;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0)break;
            miu[i*prime[j]]=miu[i]*-1;
        }
    }
    for(int i=1;i<=MAXN;i++){
        for(int l=1,r;l<=i;l=r+1){
            r=(i/(i/l));
            f[i]+=(r-l+1)*(i/l);
        }
        sum[i]=sum[i-1]+miu[i];
    }
}
signed main(){
    work();
    scanf("%lld",&T);
    while(T--){
        int n,m;
        int ans=0;
        scanf("%lld%lld",&n,&m);
        if(n>m)swap(n,m);
        for(int l=1,r;l<=n;l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=(sum[r]-sum[l-1])*f[n/l]*f[m/l];
        }
        printf("%lld\n",ans);
    }
    return 0;
}