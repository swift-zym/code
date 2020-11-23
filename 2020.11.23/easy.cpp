#include<iostream>
#define int long long
using namespace std;
int T;
int qpow(int a,int b,int p){
    if(b==0)return 1;
    int tmp=qpow(a,b/2,p);
    return b%2?tmp*tmp%p*a%p:tmp*tmp%p;
}
signed main(){
    scanf("%lld",&T);
    while(T--){
        int a,b,c,k;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        int sum=a+b+c;
        printf("%lld\n",c*qpow(2,k,sum)%sum);
    }
    return 0;
}
