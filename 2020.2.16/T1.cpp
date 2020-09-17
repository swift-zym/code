#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[22681],sum[22681];
int D(int x){return (x-1)%9+1;}
int solve(int x){
  return sum[22680]*(x/22680)+sum[x%22680];
}
signed main(){
  for(int i=1;i<=22680;i++){
    if(i*D(i)<=22680){
      a[i*D(i)]=1;
    }
  }
  for(int i=1;i<=22680;i++){
    sum[i]=sum[i-1]+a[i];
  }
  int T;
  scanf("%lld",&T);
  while(T--){
    int l,r;
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",solve(r)-solve(l-1));
  }
  return 0;
}
