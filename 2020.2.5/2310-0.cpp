#include<bits/stdc++.h>
using namespace std;
vector<int>prime,ans;
int np[1000001],ip[1000001];
void pre(){
  for(int i=2;i<=1000000;i++){
    if(!np[i])prime.push_back(i);
    for(int j=0;j<prime.size()&&prime[j]*i<=1000000;j++){
      np[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
void solve(int l,int r){
  memset(ip,0x7f,sizeof(ip));
  if(l<2)l=2;
  for(int i=0;i<prime.size()&&(long long)(prime[i])*(long long)(prime[i])<=r;i++){
    int s=l/prime[i]+(l%prime[i]>0);
    s=max(s,2);
    for(int j=s;(long long)(j)*(long long)(prime[i])<=r;j++){
      if((long long)(j)*(long long)(prime[i])>=l){
        ip[(long long)(j)*(long long)(prime[i])-l]=0;
      }
    }
  }
  ans.clear();
  for(int i=0;i<=r-l;i++){
    if(ip[i]){
      ans.push_back(i+l);
    }
  }
}
int main(){
  pre();
  int l,r;
  while(scanf("%d%d",&l,&r)!=EOF){
    solve(l,r);
    if(ans.size()<=1){
      puts("There are no adjacent primes.");
    }
    else{
      int mi=10000001,a1,b1,mx=-1,a2,b2;
      for(int i=1;i<ans.size();i++){
        if(ans[i]-ans[i-1]<mi){
          mi=ans[i]-ans[i-1];
          a1=ans[i-1];
          b1=ans[i];
        }
        if(ans[i]-ans[i-1]>mx){
          mx=ans[i]-ans[i-1];
          a2=ans[i-1];
          b2=ans[i];
        }
      }
      printf("%d,%d are closest, %d,%d are most distant.\n",a1,b1,a2,b2);
    }
  }
  return 0;
}
