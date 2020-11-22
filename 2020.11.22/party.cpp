#include<iostream>
#include<algorithm>
using namespace std;
double dp[11000][1100];
int n,a[200],num[200];
double b[200];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        num[i]=a[i]/a[0];
    }
    for(int i=0;i<n;i++){
        b[i]=(double)a[i]/100;
    }
    dp[1][0]=1;
    int now=0,cnt=0;
    for(int i=1;i<10000;i++){
    for(int j=0;j<(1<<n);j++){
        cnt++;
        if(j!=(1<<n)-1){
            if(!(j&(1<<now))){
                dp[i+1][j]+=dp[i][j]*(1.0-b[now]);
                dp[i+1][j|(1<<now)]+=dp[i][j]*b[now];
            }
            else{
                dp[i+1][j]+=dp[i][j];
            }
        }
        if(cnt==num[now]){
            now++;
            now%=n;
            cnt=0;
        }
    }
    }
    double ans=0;
    for(int i=1;i<10000;i++){
        ans+=i*dp[i][(1<<n)-1];
    }
    printf("%0.10lf\n",ans);
    return 0;
}