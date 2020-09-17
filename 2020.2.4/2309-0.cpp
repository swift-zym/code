#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxn,ans,n,a[12]={0,2,3,5,7,11,13,17,19,21,23};
void dfs(int v,int num,int mx,int deep){
  if(num>maxn||(num==maxn&&ans>v)){
    maxn=num;
    ans=v;
  }
  if(deep>=11)return;
  for(int i=1;i<=mx;i++){
    v*=a[deep];
    if(v>n)return;
    dfs(v,num*(i+1),i,deep+1);
  }
}
signed main(){
  cin>>n;
  dfs(1,1,100,1);
  cout<<ans<<endl;
}
