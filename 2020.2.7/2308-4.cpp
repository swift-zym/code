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
int qmul(int a,int b,int mod){
  if(b==0)return 0;
  int tmp=qmul(a,b/2,mod);
  return b%2?(((tmp+tmp)%mod)+a)%mod:(tmp+tmp)%mod;
}
signed main(){
  int n;
  while(scanf("%lld",&n)!=EOF){
  int a,b;
  scanf("%lld%lld",&b,&a);
  int ans=a,M=b;
  bool flag=1;
  for(int i=2;i<=n;i++){
    scanf("%lld%lld",&b,&a);
    a=((a-ans)%b+b)%b;
    int x,y;
    int GCD=exgcd(M,b,x,y);
    if(a%GCD){
      flag=0;
      break;
    }
    x=qmul(x,a/GCD,b);
    ans+=M*x;
    M*=b/GCD;
    ans=(ans+M)%M;
  }
  if(!flag){
    puts("-1");
    continue;
  }
  printf("%lld\n",ans);
  }
  return 0;
}
