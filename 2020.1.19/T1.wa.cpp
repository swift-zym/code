#include<bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2?tmp*tmp*a:tmp*tmp;
}
signed main(){
  int n;
  scanf("%lld",&n);
  int bf=n;
  vector<int>v;
  while(n){
    v.push_back(n%3);
    n/=3;
  }
  for(int i=0;i<v.size();i++){
    for(int j=1;j<=v[i];j++)
    printf("%lld ",qpow(3,i));
  }
  putchar(10);
  printf("%lld",bf);
}
