#include<iostream>
#include<cmath>
using namespace std;
int t,n,a[51],b[51];
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    int mina=1e9,minb=1e9;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
      mina=min(mina,a[i]);
      minb=min(minb,b[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
      ans+=max(a[i]-mina,b[i]-minb);
    }
    cout<<ans<<endl;
  }
  return 0;
}
