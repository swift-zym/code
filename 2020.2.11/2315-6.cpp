#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[13],dp[10];
void init(){
    for(int i=1;i<=13;i++){
        f[i]=f[i-1]*10+pow(10,i-1);
    }
}
void work(int a){
    int tmp[13],cnt=0;
    while(a){
        tmp[++cnt]=a%10;
        a/=10;
    }
    for(int i=cnt;i>=1;i--){
        for(int j=0;j<=9;j++)
        dp[j]+=tmp[i]*f[i-1];
        for(int j=0;j<tmp[i];j++)
        dp[j]+=pow(10,i-1);
        int aa=0;
        for(int j=i-1;j>=1;j--){
            aa=aa*10+tmp[j];
        }
        dp[tmp[i]]+=aa+1;
        dp[0]-=pow(10,i-1);
    }

}
signed main(){
    init();
    int a,b;
    scanf("%lld%lld",&a,&b);
    work(a-1);
    int tmp[10];
    for(int i=0;i<=9;i++)tmp[i]=dp[i];
    memset(dp,0,sizeof(dp));
    work(b);
    for(int i=0;i<=9;i++){
        if(i)putchar(' ');
        cout<<dp[i]-tmp[i];
    }
    putchar(10);
    return 0;
}
