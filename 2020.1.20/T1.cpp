#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int x,y;};
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int check(int x,int y){
  return (((x%2)+(y%2))%2)!=1;
}
node work(node a){
  int g=gcd(a.x,a.y);
  return {a.x/g,a.y/g};
}
signed main(){
  int n,m;
  scanf("%lld%lld",&n,&m);
  int g=gcd(n,m);
  n/=g;m/=g;
  node ans;
  if(n%2==1&&m%2==1){
    ans={(n*m+1)/2,n*m};
  }
  else{
    ans={1,2};
  }
  ans=work(ans);
  printf("%lld/%lld\n",ans.x,ans.y);
  return 0;
}
