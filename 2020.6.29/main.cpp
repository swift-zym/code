#include<bits/stdc++.h>
#define int long long
using namespace std;
bool self_check(int a){
    return (a&(a>>1))==0;
}
bool check(int a,int b){
    if((a&b)!=0)return 0;
    if((a&(b>>1))!=0)return 0;
    if((b&(a>>1))!=0)return 0;
    return 1;
}
void debug_output(int a){
    vector<int>buf;
    while(a){
        buf.push_back(a%2);
        a/=2;
    }
    for(int i=buf.size()-1;i>=0;i--){
        cout<<buf[i]<<" ";
    }
    if(!buf.size())putchar('0');
    cout<<endl;
}
int count(int a){
    int ans=0;
    for(int i=0;i<=30;i++){
        if((a&(1<<i))==(1<<i))ans++;
    }
    return ans;
}
vector<int>sta,num;
int dp[10][1<<9][82];
signed main(){
    int n,K;
    scanf("%lld%lld",&n,&K);
    for(int i=0;i<(1<<9);i++){
        if(i>=(1<<n))continue;
        if(self_check(i)&&count(i)<=n){
            sta.push_back(i);
            num.push_back(count(i));
        }
    }
    for(int i=0;i<sta.size();i++){
        dp[1][sta[i]][num[i]]++;
    }
    for(int i=2;i<=n;i++) {
        for (int now = 0; now <= n * n; now++) {
            for (int j = 0; j < sta.size(); j++) {
                if (now < num[j])continue;
                for (int k = 0; k < sta.size(); k++) {
                    if (now + num[k] > n * n)continue;
                    if (check(sta[j], sta[k])) {
                        dp[i][sta[k]][now + num[k]] += dp[i - 1][sta[j]][now];
                    }
                }

            }
        }
    }
    int ans=0;
    for(int i=0;i<sta.size();i++){
        ans+=dp[n][sta[i]][K];
    }
    printf("%lld\n",ans);
    return 0;
}