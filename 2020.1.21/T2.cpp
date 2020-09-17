#include<bits/stdc++.h>
using namespace std;
int n,k,num1=0,num2=0;
string s;
bool flag1=1,flag2=1;
int main(){
  cin>>n>>k;
  cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='B')flag1=0,num2++;
    else flag2=0,num1++;
  }
  if(flag1){
    printf("%lf\n",double(k));
  }
  else if(flag2||k==0){
    printf("%lf\n",double(0));
  }
  else if(k==n){
    printf("%lf\n",double(num1));
  }
  return 0;
}
