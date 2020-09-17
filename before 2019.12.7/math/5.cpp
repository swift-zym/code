#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
#undef int
int main(){
    #define int long long
    int ans=1;
    for(int i=1;i<=20;i++){
        ans=lcm(ans,i);
    }
    printf("%lld\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}