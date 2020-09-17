#include<bits/stdc++.h>
using namespace std;
void exgcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1;y=0;
    return;
  }
  exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
}
int main(){
  int a,b,x,y;
  cin>>a>>b;
  exgcd(a,b,x,y);
  x=(x+b)%b;
  cout<<x<<endl;
  return 0;
}
