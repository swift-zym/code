#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],l=1,ans;
map<int,int>ma;
int main(){
  std::ios::sync_with_stdio(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(ma[a[i]]){
      while(a[l]!=a[i])ma[a[l]]=0,l++;
      l++;
    }
    else{
      ma[a[i]]=1;
    }
    ans=max(ans,i-l+1);
  }
  cout<<ans<<endl;
  return 0;
}
