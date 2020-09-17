#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s[0]!='M'||s[1]!='D'||s[2]!='A'){
    puts("1 1 1 1 1");
    return 0;
  }
  char c;
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]>='0'&&s[i]<='9'){
      c=s[i];
      break;
    }
  }
  string ans="0 0 0 0 0";
  int a=c-'0';
  if(a==1||a==9){
    ans[0]='1';
  }
  if(a==2||a==8){
    ans[2]='1';
  }
  if(a==3||a==7){
    ans[4]='1';
  }
  if(a==4||a==6){
    ans[6]='1';
  }
  if(a==0||a==5){
    ans[8]='1';
  }
  cout<<ans<<endl;
  return 0;
}
