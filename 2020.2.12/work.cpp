#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("tmp.txt","r",stdin);
  for(int i=1;i<=5999;i++){
    string s;
    getline(cin,s);
    char o[101];
    sprintf(o,"name-%d.txt",i);
    freopen(o,"w",stdout);
    cout<<s;
  }
  return 0;
}
