#include<iostream>
#include<string>
using namespace std;
int t,n,a[101];
char change(char c){
  if(c<'z')return c+1;
  return 'a';
}
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    string s="",ss;
    for(int i=1;i<=60;i++){
      s+="a";
    }
    cout<<"0:";cout<<s<<endl;
    for(int i=1;i<=n;i++){
      s[a[i]]=change(s[a[i]]);
      cout<<i<<":"<<cout<<s<<endl;
    }
  }
  return 0;
}
/*
aaa
ab

*/
/*
1
51
50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
*/
