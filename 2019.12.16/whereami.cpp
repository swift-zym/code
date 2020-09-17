/*
ID:swiftui
LANG:C++
TASK:whereami
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
int n;
unordered_map<string,int>ma;
string s;
int main(){
  freopen("whereami.in","r",stdin);
  freopen("whereami.out","w",stdout);
  ios::sync_with_stdio(0);
  cin>>n;
  cin>>s;
  for(int i=1;i<=n;i++){
    ma.clear();
    bool flag=1;
    for(int j=0;j<n-i+1;j++){
      if(ma[s.substr(j,i)]){
        flag=0;
        break;
      }
      ma[s.substr(j,i)]=1;
    }
    if(flag){
      cout<<i<<endl;
      exit(0);
    }
  }
  return 0;
}
