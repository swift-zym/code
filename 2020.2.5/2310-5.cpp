#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
vector<int>prime;
int n,np[1000001],num[1000001],ans=1;
void pre(){
  for(int i=2;i<=n;i++){
    if(!np[i])prime.push_back(i);
    for(int j=0;j<prime.size()&&prime[j]*i<=n;j++){
      np[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
signed main(){
  scanf("%lld",&n);
  pre();
  for(int i=0;i<prime.size();i++){
    num[i]=0;
    for(int j=prime[i];j<=n;j*=prime[i]){
      num[i]+=n/j;
    }
    num[i]%=MOD;
  }
  for(int i=0;i<prime.size();i++){
    ans*=(2*num[i]+1)%MOD;
    ans%=MOD;
  }
  printf("%lld\n",ans);
  return 0;
}
