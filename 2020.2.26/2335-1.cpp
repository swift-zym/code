#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>ma;
string a(string s){
  string r="";
  r+=s[4];
  r+=s[5];
  r+=s[6];
  r+=s[7];
  r+=s[0];
  r+=s[1];
  r+=s[2];
  r+=s[3];
  return r;
}
string b(string s){
  string r="";
  r+=s[3];
  r+=s[0];
  r+=s[1];
  r+=s[2];
  r+=s[7];
  r+=s[4];
  r+=s[5];
  r+=s[6];
  return r;
}
string c(string s){
  string r="";
  r+=s[0];
  r+=s[5];
  r+=s[1];
  r+=s[3];
  r+=s[4];
  r+=s[6];
  r+=s[2];
  r+=s[7];
  return r;
}
string fin="";
queue<string>q,ans;
int main(){

  /*test*/

  /*string now="12348765";
  char C;
  while(cin>>C){
    if(C=='A'){
      now=a(now);
    }
    else if(C=='B'){
      now=b(now);
      cout<<"ok"<<endl;
    }
    else{
      now=c(now);
    }
    cout<<now<<endl;
  }*/
  for(int i=1;i<=8;i++){
    char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    fin+=c;
  }
  swap(fin[4],fin[7]);
  swap(fin[5],fin[6]);
  q.push("12348765");
  ans.push("");
  while(!q.empty()){
    string na=ans.front();
    string ns=q.front();
    //cout<<ns<<" "<<na<<endl;
    ma[ns]=1;
    q.pop();
    ans.pop();
    if(ns==fin){
      cout<<na.length()<<endl;
      cout<<na<<endl;
      return 0;
    }
    if(!ma[a(ns)]){
    q.push(a(ns));
    ans.push(na+"A");
    }
    if(!ma[b(ns)]){
    q.push(b(ns));
    ans.push(na+"B");
    }
    if(!ma[c(ns)]){
    q.push(c(ns));
    ans.push(na+"C");
    }
  }
  return 0;
}
