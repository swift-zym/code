#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int t,n,p,k;
string s;
int dp[100001];
int x,y;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>p>>k;
        cin>>s;
        s="$"+s;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            dp[i]=1e9;
        }
        for(int i=p;i<=n;i++){
            dp[i]=(i-p)*y+(s[i]=='0')*x;
        }
        int ans=1e9;
        for(int i=k+1;i<=n;i++){
            if(dp[i-k]+(s[i]=='0')*x<dp[i]){
                dp[i]=dp[i-k]+(s[i]=='0')*x;
            }
        }
        for(int i=1;i<=n;i++){
            if(i+k>n)ans=min(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}