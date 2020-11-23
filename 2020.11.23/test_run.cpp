#include<bits/stdc++.h>
using namespace std;
int T;
int qpow(int a,int b,int p){
    if(b==0)return 1;
    int tmp=qpow(a,b/2,p);
    return b%2?tmp*tmp%p*a%p:tmp*tmp%p;
}
#ifdef int
signed main(int argc,char *argv[]){
#else
int main(int argc,char *argv[]){
#endif
scanf("%lld",&T);
while(T--){
    int a,b,c,k;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    int sum=a+b+c;
    printf("%lld\n",c*qpow(2,k,sum)%sum);
}
}
