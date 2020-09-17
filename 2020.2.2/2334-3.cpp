#include<bits/stdc++.h>
#define int long long
using namespace std;
#define bas 23333
#define MOD 1000000007
int n,tmp[4000000],has[4000000],ans=-1,opt,flag;
string u;
int solve(int l,int r){
  if(l>r)return 0;
  return (has[r]-tmp[r-l+1]*has[l-1]%MOD+MOD)%MOD;
}
void pre(){
  tmp[0]=1;
  for(int i=1;i<=n;i++)tmp[i]=(tmp[i-1]*bas)%MOD;
  for(int i=1;i<=n;i++){
    has[i]=((has[i-1]*bas)%MOD+u[i-1])%MOD;
  }
}
signed main(){
  ios::sync_with_stdio(0);
  cin>>n;
  cin>>u;
  pre();
  if(n%2==0){
    puts("NOT POSSIBLE");
    return 0;
  }
  for(int i=1;i<=n/2;i++){
    int l=(solve(1,i-1)*tmp[n/2+1-i])%MOD+solve(i+1,n/2+1),r=solve(n/2+2,n);
    l%=MOD;
    r%=MOD;
    if(l==r&&ans!=l){
      flag++;
      ans=l;
      opt=i;
    }
  }
  int l=solve(1,n/2),r=solve(n/2+2,n);
  if(l==r&&ans!=l){
    flag++;
    ans=l;
    opt=n/2+1;
  }
  for(int i=n/2+2;i<=n;i++){
    int l=solve(1,n/2),r=(solve(n/2+1,i-1)*tmp[n-i])%MOD+solve(i+1,n);
    l%=MOD;
    r%=MOD;
    if(l==r&&ans!=l){
      flag++;
      ans=l;
      opt=i;
    }
  }
  if(flag==0){
    puts("NOT POSSIBLE");
  }
  else if(flag==1){
    int cnt=0;
    for(int i=1;i<=n/2;i++){
       if(i==opt)cnt++;
       putchar(u[cnt]);
       cnt++;
    }
    putchar(10);
  }
  else{
    puts("NOT UNIQUE");
  }
  return 0;
}
