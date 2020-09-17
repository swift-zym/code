#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
  return a*b/gcd(a,b);
}
signed main(){
  int T;
  scanf("%lld",&T);
  while(T--){
    int n,m,a,ans=0;
    scanf("%lld%lld%lld",&n,&m,&a);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(gcd(i,j)<=a)ans+=lcm(i,j);
    }
    printf("%lld\n",ans);
   }
  return 0;
}
