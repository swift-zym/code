#include<bits/stdc++.h>
using namespace std;
#define int long long
int np[2000001];
vector<int>prime;
int n,p,tmp[2000001];
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2?tmp*tmp%p*a%p:tmp*tmp%p;
}
signed main(){
  scanf("%lld%lld",&n,&p);
  for(int i=2;i<=2*n;i++){
    if(!np[i]){
      np[i]=i;
      prime.push_back(i);
      //<-prime.empty()
    }
    for(int j=0;j<prime.size()&&i*prime[j]<=2*n;j++){
      np[i*prime[j]]=prime[j];
      if(i%prime[j]==0)break;
    }
  }
  for(int i=1;i<=n;i++){
    tmp[i]=-1;
  }
  for(int i=n+2;i<=2*n;i++){
    tmp[i]=1;
  }
  for(int i=2*n;i>=2;i--){
    if(np[i]<i){
      tmp[np[i]]+=tmp[i];
      tmp[i/np[i]]+=tmp[i];
    }
  }
  int ans=1;
  for(int i=2;i<=2*n;i++){
    if(np[i]==i)
    ans=ans*qpow(i,tmp[i])%p;
  }
  printf("%lld\n",ans);
  return 0;
}
