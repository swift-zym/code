#include<bits/stdc++.h>
#define MOD 9901
#define int long long
using namespace std;
vector<int>pr,nm;
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2?(((tmp*tmp)%MOD)*a)%MOD:(tmp*tmp)%MOD;
}
signed main(){
  int a,b;
  cin>>a>>b;
  bool flag=0;
  for(int i=2;i<=a;i++){
    if(a%i==0){
    flag=1;
    int tmp=0;
    while(a%i==0){
      a/=i;
      tmp++;
      if(a==1)break;
    }
    pr.push_back(i);
    nm.push_back(tmp*b+1);
    }
  }
  if(a!=1&&!flag){
    pr.push_back(a);
    nm.push_back(b+1);
  }
  int ans=1;
  if(!a)ans=0;
  for(int i=0;i<pr.size();i++){
    ans*=(qpow(pr[i]-1,MOD-2)*(qpow(pr[i],nm[i])-1))%MOD;
    ans%=MOD;
  }
  printf("%lld\n",ans);
  return 0;
}
