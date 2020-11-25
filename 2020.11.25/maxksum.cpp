#include<iostream>
#include<climits>
#define int long long
using namespace std;
int n,k,a[100001],sum[100001];
int dp[100001][2];
bool check(int x){
    int id=0;
    for(int i=1;i<=n;i++){
        if(dp[id][0]+(sum[i]-sum[id])+x>dp[i-1][0]||(dp[id][0]+(sum[i]-sum[id])+x==dp[i-1][0]&&dp[id][1]<dp[i-1][1])){
          dp[i][0]=dp[id][0]+(sum[i]-sum[id])+x;
          dp[i][1]=dp[id][1]+1;
        }
        else{
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
        }
        if(dp[i][0]-sum[i]>dp[id][0]-sum[id]||(dp[i][0]-sum[i]==dp[id][0]-sum[id]&&dp[i][1]<dp[id][1])){
            id=i;
        }
    }
    return dp[n][1]<=k;
}
signed main(){
    freopen("maxksum.in","r",stdin);
    freopen("maxksum.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    int l=-1e9,r=0,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf("%lld\n",dp[n][0]-k*ans);
    return 0;
}
