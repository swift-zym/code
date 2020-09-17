#include<bits/stdc++.h>
#define int long long
int MOD;
using namespace std;
int jc[100008];
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2==0?tmp*tmp%MOD:tmp*tmp%MOD*a%MOD;
}
int C(int m,int n){
  if(n>m)return 0;
  //printf("C(%lld,%lld)=%lld\n",m,n,(((jc[m]*qpow(jc[n],MOD-2))%MOD)*qpow(jc[m-n],MOD-2))%MOD);
  return (((jc[m]*qpow(jc[n],MOD-2))%MOD)*qpow(jc[m-n],MOD-2))%MOD;
}
int lucas(int m,int n){
  if(!m)return 1;
  return (C(m%MOD,n%MOD)*lucas(m/MOD,n/MOD))%MOD;
}
signed main(){
  int T;
  scanf("%lld",&T);
  MOD=10007;
  while(T--){
    int m,n;
    scanf("%lld%lld",&m,&n);
      jc[0]=jc[1]=1;
      for(int i=2;i<=MOD;i++){
      jc[i]=jc[i-1]*i;
      jc[i]%=MOD;
      }
    printf("%lld\n",lucas(m,n));
  }
  return 0;
}
