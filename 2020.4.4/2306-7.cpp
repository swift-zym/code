#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
signed main(){
  system("sh");
  int n,m;
  scanf("%lld%lld",&n,&m);
  n++;m++;
  int ans=n*m<3?0:n*m*(n*m-1)*(n*m-2)/6;
  ans-=n*(m<3?0:m*(m-1)*(m-2)/6);
  ans-=m*(n<3?0:n*(n-1)*(n-2)/6);
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    ans-=2*(gcd(i,j)-1)*(n-i)*(m-j);
  }
  printf("%lld\n",ans);
  return 0;
}
