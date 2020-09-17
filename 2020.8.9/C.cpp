#include<iostream>
#define int long long
#define MOD 1000000007
using namespace std;
signed main(){
  int n;
  cin>>n;
  int tmp=1,ans;
  for(int i=1;i<=n;i++){
    tmp*=i;
    tmp%=MOD;
  }
  ans=tmp;
  tmp=1;
  for(int i=1;i<=n-1;i++){
    tmp*=2;
    tmp%=MOD;
  }
  ans=(ans-tmp+MOD)%MOD;
  cout<<ans<<endl;
  return 0;
}
