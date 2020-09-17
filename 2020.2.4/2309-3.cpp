#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define int long long
int fac(int i){
  if(!i)return 1;
  return fac(i-1)*i;
}
int num[10000];
signed main(){
  int n;
  while(scanf("%lld",&n)!=EOF){
    memset(num,0,sizeof(num));
    int ans1,ans2;
    ans1=0;
    for(int i=2;i<=sqrt(n);i++){
      while(n%i==0){
        num[i]++;
        ans1++;
        n/=i;
      }
    }
    if(n!=1)ans1++;
    ans2=fac(ans1);
    for(int i=2;i<10000;i++){
      if(num[i]){
        ans2/=fac(num[i]);
      }
    }
    printf("%lld %lld\n",ans1==0?1:ans1,ans2);
  }
}
