#include<bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int a,int b,int p){
  if(!b)return 1;
  int tmp=qpow(a,b/2,p);
  return b%2?tmp*tmp%p*a%p:tmp*tmp%p;
}
void exgcd(int a,int b,int &x,int &y){
  if(!b){
    x=1;
    y=0;
    return;
  }
  exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
}
int inv(int a,int p){
  if(!a)return 0;
  int x,y;
  exgcd(a,p,x,y);
  x=(x+p)%p;
  return x==0?p:x;
}
int jc(int n,int p,int pp){
  if(!n)return 1;
  int ans=1;
  for(int i=2;i<=pp;i++){
    if(i%p)ans*=i,ans%=pp;
  }
  ans=qpow(ans,n/pp,pp);
  for(int i=2;i<=n%pp;i++){
    if(i%p)ans*=i,ans%=pp;
  }
  return ans*jc(n/p,p,pp)%pp;
}
int C(int n,int m,int mod,int p,int pp){
  if(m>n)return 0;
  int a=jc(n,p,pp),b=jc(m,p,pp),c=jc(n-m,p,pp);
  int tmp=0;
  for(int i=n;i;i/=p)tmp+=i/p;
  for(int i=m;i;i/=p)tmp-=i/p;
  for(int i=n-m;i;i/=p)tmp-=i/p;
  int ans=a*inv(b,pp)%pp*inv(c,pp)%pp*qpow(p,tmp,pp)%pp;
  return ans*(mod/pp)%mod*inv(mod/pp,pp)%mod;
}
int p,n,m,a[10],sum=0;
signed main(){
  scanf("%lld%lld%lld",&p,&n,&m);
  for(int i=1;i<=m;i++)scanf("%lld",&a[i]),sum+=a[i];
  if(sum>n){
    puts("Impossible");
    return 0;
  }
  int ans=1;
  for(int i=1;i<=m;i++){
    n-=a[i-1];
    int anss=0,now=p;
    for(int j=2;j<=sqrt(p);j++){
      if(now%j==0){
        int pp=1;
        while(now%j==0)pp*=j,now/=j;
        anss+=C(n,a[i],p,j,pp);
        anss%=p;
      }
    }
    if(now>1)anss+=C(n,a[i],p,now,now),anss%=p;
    ans*=anss;
    ans%=p;
  }
  printf("%lld\n",ans);
  return 0;
}
