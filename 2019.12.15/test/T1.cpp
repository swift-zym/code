//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define inv2 500000004
using namespace std;
void exgcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1;y=0;
    return;
  }
  exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
}
int qpow(int a,int b){
  if(b==0){
    return 1;
  }
  int tmp=qpow(a,b/2);
  return b%2?(((tmp*tmp)%MOD)*a)%MOD:(tmp*tmp)%MOD;
}
unordered_map<int,int>ma;
signed main(){
  int T;
  scanf("%lld",&T);
  while(T--){
    int n,x;
    scanf("%lld%lld",&x,&n);
    if(x==1){
      printf("1\n");
      continue;
    }
    else{
    for(int i=n-1;i>=1;i--){
      int xx,yy;
      exgcd(x,MOD,xx,yy);
      xx=(xx+MOD)%MOD;
      x+=xx;
      x%=MOD;
      x*=inv2;
      x%=MOD;
      if(ma[x]){
        puts("found");
        exit(0);
      }
      ma[x]=1;
    }
    printf("%lld\n",x);
    }
  }
  return 0;
}
/*
x=(x+inv(x))*inv2
*/
