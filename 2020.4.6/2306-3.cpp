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
int a[5];
int n,g,tmp[6]={0,2,3,4679,35617,999911658};
void exgcd(int a,int b,int &x,int &y){
  if(!b){
    x=1;y=0;
    return;
  }
  exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
}
signed main(){
  scanf("%lld%lld",&n,&g);
  if(g%(tmp[5]+1)==0){
    puts("0");
    return 0;
  }
  for(int j=1;j<=4;j++){
    MOD=tmp[j];
    jc[0]=jc[1]=1;
    for(int i=2;i<=MOD;i++){
      jc[i]=jc[i-1]*i;
      jc[i]%=MOD;
    }
    for(int i=1;i<=sqrt(n);i++){
      if(n%i==0){
        a[j]+=lucas(n,i);
        a[j]%=MOD;
        if(i*i!=n){
          a[j]+=lucas(n,n/i);
        }
      }
    }
  }
  int ans=0;
  MOD=tmp[5];
  for(int i=1;i<=4;i++){
    int mi=tmp[5]/tmp[i];
    int x,y;
    exgcd(mi,tmp[i],x,y);
    x=(x+tmp[i])%tmp[i];
    ans=(ans+x*mi%MOD*a[i]%MOD+MOD)%MOD;
  }
  MOD+=1;
  printf("%lld\n",qpow(g,ans));
  return 0;
}
