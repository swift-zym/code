#include<bits/stdc++.h>
#define int long long
#define MOD 10007
using namespace std;
int A[2001][2001];
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2?(((tmp*tmp)%MOD)*a)%MOD:(tmp*tmp)%MOD;
}
int a,b,k,n,m;
signed main(){
  A[1][1]=1;
  scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
  for(int i=2;i<=k+1;i++)
  for(int j=1;j<=i;j++){
    A[i][j]=((A[i-1][j-1])+A[i-1][j])%MOD;
  }
  printf("%lld\n",((A[k+1][k-n+1]*qpow(a,n)%MOD)*qpow(b,m))%MOD);
  return 0;
}
