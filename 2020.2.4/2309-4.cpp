#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100000
int is[MAXN+1];
vector<int>prime,ans;
void pre(){
  for(int i=2;i<=MAXN;i++){
    if(!is[i])prime.push_back(i);
    for(int j=0;j<prime.size()&&i*prime[j]<=MAXN;j++){
      is[prime[j]*i]=1;
      if(i%prime[j]==0)break;
    }
  }
}
bool is_prime(int x){
  if(x==1)return 0;
  if(x<=MAXN)return !is[x];
  for(int i=0;prime[i]*prime[i]<=x;i++){
    if(x%prime[i]==0)return 0;
  }
  return 1;
}
void dfs(int v,int idx,int now){
  if(v==1){
    ans.push_back(now);
    return;
  }
  if(is_prime(v-1)&&v-1>=prime[idx]){
    ans.push_back(now*(v-1));
  }
  for(int i=idx;prime[i]*prime[i]<=v;i++){
    int sum=prime[i]+1,bas=prime[i];
    for(;sum<=v;bas*=prime[i],sum+=bas){
      if(v%sum==0){
        dfs(v/sum,i+1,now*bas);
      }
    }
  }
}
signed main(){
  int s;
  pre();
  while(scanf("%lld",&s)!=EOF){
    ans.clear();
    dfs(s,0,1);
    sort(ans.begin(),ans.end());
    printf("%lld\n",(long long)(ans.size()));
    for(int i=0;i<ans.size();i++){
      printf("%lld ",ans[i]);
    }
    if(ans.size())
    putchar(10);
  }
  return 0;
}
