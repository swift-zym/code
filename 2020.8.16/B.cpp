#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[200001];
int t;
void change(){
        int mx=a[1];
        for(int j=2;j<=n;j++){
                 mx=max(mx,a[j]);
        }
        for(int j=1;j<=n;j++){
            a[j]=mx-a[j];
        }
}
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(k%2==1){
            change();
        }
        else{
            change();change();
        }
        for(int i=1;i<=n;i++){
            printf("%lld ",a[i]);
        }
        putchar(10);
    }
    return 0;
}
/*
1
1 1
-1000000000
*/