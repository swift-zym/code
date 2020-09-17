#include<bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1;y=0;
    return a;
  }
  int tmp=exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
  return tmp;
}
signed main(){
  int x,y,m,n,L,X,Y;
  cin>>x>>y>>m>>n>>L;
  int b=n-m,a=x-y;
  if(b<0){
    b=-b;
    a=-a;
  }
  int tmp=exgcd(b,L,X,Y);
  if(a%tmp!=0){
    puts("Impossible");
  }
  else{
    cout<<(X*(a/tmp)%(L/tmp)+(L/tmp))%(L/tmp);
  }
  return 0;
}
