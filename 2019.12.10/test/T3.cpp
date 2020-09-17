#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int ans=0,n;
int g(int a,int b){return b==0?a:g(b,a%b);}
int l(int a,int b){return a*b/g(a,b);}
void dfs(int deep,int gcd,int lcm,bool nil){
  if(deep>n){ans+=gcd==1&&lcm==n;ans%=MOD;return;}
  dfs(deep+1,gcd,lcm,nil);
  if(n%deep!=0)return;
  if(l(lcm,deep)>n)return;
  if(nil){
    dfs(deep+1,deep,deep,0);
  }
  else{
    dfs(deep+1,g(gcd,deep),l(lcm,deep),nil);
  }
}
bool is_prime(int x){
  for(int i=2;i<=sqrt(x);i++){
    if(x%i==0)return 0;
  }
  return 1;
}
int main(){
  scanf("%d",&n);
  if(is_prime(n)){
    puts("1");
  }
  else{
    dfs(1,0,0,1);
    printf("%d\n",ans);
  }
  return 0;
}
