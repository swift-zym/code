#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>ma;
vector<string>v;
int main(){
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    string s,a;
    cin>>s;
    getline(cin,a);
    if(s=="add")v.push_back(a);
    else{
      bool flag=0;
      for(int j=0;j<v.size();j++){
        if(v[j]==a){
          puts("yes");
          flag=1;
          break;
        }
      }
      if(!flag)
      puts("no");
    }
  }
  return 0;
}
