#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<unordered_map>
#define int long long
using namespace std;
#define bas 2333
#define MOD 1000000007
int n,a[200001],tmp[200001],hash1[210000],hash2[210000],mx;
map<int,int>ma;
vector<int>k;
int solve(int l,int r){
  if(l<=r){
    return (hash1[r]-(hash1[l-1]*tmp[r-l+1])%MOD+MOD)%MOD;
  }
  else{
    return (hash2[r]-(hash2[l+1]*tmp[l-r+1])%MOD+MOD)%MOD;
  }
}
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=1;i<=n;i++){
    hash1[i]=(hash1[i-1]*bas+a[i])%MOD;
  }
  for(int i=n;i>=1;i--){
    hash2[i]=(hash2[i+1]*bas+a[i])%MOD;
  }
  tmp[0]=1;
  for(int i=1;i<=n;i++){
    tmp[i]=(tmp[i-1]*bas)%MOD;
    //cout<<i<<" "<<tmp[i]<<endl;
  }
  for(int i=1;i<=n;i++){
    ma.clear();
    int ans=0;
    for(int j=1;i*j<=n;j++){
      int l=(j-1)*i+1,r=j*i;
      int hash=(solve(l,r)*solve(r,l))%MOD;
      if(!ma[hash]){
        ma[hash]=1;
        ans++;
      }
    }
    if(ans==mx){
      k.push_back(i);
    }
    else if(ans>mx){
      k.clear();
      mx=ans;
      k.push_back(i);
    }
  }
  printf("%lld %lld\n",mx,(long long)(k.size()));
  for(int i=0;i<k.size();i++){
    if(i)putchar(' ');
    printf("%lld",k[i]);
  }
  putchar(10);
  return 0;
}
