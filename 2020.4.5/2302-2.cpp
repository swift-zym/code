#include<bits/stdc++.h>
#define int long long
int MOD=1000003;
using namespace std;
int jc[1000003+10];
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2==0?tmp*tmp%MOD:tmp*tmp%MOD*a%MOD;
}
int C(int m,int n){
  if(n>m)return 0;
  int bas=1;
  for(int i=m;i>m-n;i--){
    bas=(bas*i)%MOD;
  }
  return bas*qpow(jc[n],MOD-2);
}
int lucas(int m,int n){
  if(!m)return 1;
  return (C(m%MOD,n%MOD)*lucas(m/MOD,n/MOD))%MOD;
}
signed main(){
  jc[0]=jc[1]=1;
  for(int i=2;i<=MOD;i++){
    jc[i]=jc[i-1]*i;
    jc[i]%=MOD;
  }
  int T;
  scanf("%lld",&T);
  while(T--){
    int n,l,r;
    scanf("%lld%lld%lld",&n,&l,&r);
    printf("%lld\n",(lucas(r-l+n+1,r-l+1)-1+MOD)%MOD);
  }
  return 0;
}
