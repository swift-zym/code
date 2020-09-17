#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int t,l,r;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){
  return a*b/gcd(a,b);
}
signed main(){
  cin>>t;
  while(t--){
    cin>>l>>r;
    if(lcm(l,l*2)>r){
      puts("-1 -1");
    }
    else{
      printf("%lld %lld\n",l,l*2);
    }
  }
  return 0;
}
