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
  ios::sync_with_stdio(0);
  int a,b,c,p;
  while(cin>>a>>b>>c>>p){
    if(!a && !b && !c && !p)break;
    int t1=a,t2=b;a=c;b=1ll<<p,c=t2-t1,p=1ll<<p;
    int x,y;
    int tmp=exgcd(a,b,x,y);
    if(c%tmp!=0){
      puts("FOREVER");
    }
    else{
      x*=(c/tmp);
      x%=p;
      int t=abs(b/tmp);
      x=(x%t+t)%t;
      printf("%lld\n",x);
    }
  }
  return 0;
}
