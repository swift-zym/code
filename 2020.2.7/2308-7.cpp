#include<bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1;y=0;
    return a;
  }
  int tmp=exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
  return tmp;
}
signed main(){
  int t;
  scanf("%lld",&t);
  while(t--){
    int n,d,x,y;
    scanf("%lld%lld%lld%lld",&n,&d,&x,&y);
    int a=y-x;
    int X,Y;
    int tmp=exgcd(d,n,X,Y);
    if(a%tmp){
      puts("Impossible");
    }
    else{
      int b=a/tmp;
      X=X*b;
      b=abs(n/tmp);
      X=(X%b+b)%b;
      printf("%lld\n",X);
    }
  }
  return 0;
}
