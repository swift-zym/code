#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n;
  scanf("%lld",&n);
  int s=1;
  while((s+2*s-1)*s-2*s+1<n){
    s++;
  }
  s--;
  int ans=s*6;
  int num=0;
  n-=(s+2*s-1)*s-2*s+1;
  while(n){
    if(n<=num-1){
      break;
    }
    num++;
    ans++;
    n-=s-1;
  }
  printf("%lld\n",ans);
  return 0;
}
/*
6
*/
/*
9
*/
