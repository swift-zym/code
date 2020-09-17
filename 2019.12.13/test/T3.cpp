#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int d,k,l,r;
int s(int a){
  int v=0;
  while(a){
    v+=a%10;
    a/=10;
  }
  return v;
}
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2?(((tmp*tmp)%MOD)*a)%MOD:(tmp*tmp)%MOD;
}
int ans,a[3];
void dfs(int deep){
  if(deep==k+1){
    int sum1=0,sum2=0;
    for(int i=1;i<=k;i++){
      sum1+=a[i];
      sum2+=s(a[i]);
    }
    sum1=s(sum1);
    sum1%=d;
    sum2%=d;
    if(sum1==sum2){
      ans++;
    }
    return;
  }
  for(int i=l;i<=r;i++){
    a[deep]=i;
    dfs(deep+1);
  }
}
signed main(){
  scanf("%lld",&d);
  scanf("%lld",&k);
  scanf("%lld",&l);
  scanf("%lld",&r);
  if(d==3||d==9){
    printf("%lld\n",qpow(r-l+1,k));
  }
  else if(d<=9&&k==2){
    dfs(1);
    printf("%lld\n",ans);
  }
  return 0;
}
/*
6
2
10
12
*/
