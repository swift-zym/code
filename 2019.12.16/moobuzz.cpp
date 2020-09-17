/*
ID:swiftui
LANG:C++
TASK:moobuzz
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  freopen("moobuzz.in","r",stdin);
  freopen("moobuzz.out","w",stdout);
  int n;
  scanf("%lld",&n);
  int ans=n/8ll*15ll;
  n%=8ll;
  if(!n){
    ans--;
  }
  else{
  for(int i=1;i<=15;i++){
    if(i%3!=0&&i%5!=0){
      n--;
      if(!n){
        ans+=i;
        break;
      }
    }
  }
  }
  printf("%lld\n",ans);
  return 0;
}
