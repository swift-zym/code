#include<bits/stdc++.h>
using namespace std;
int n,m,son[1000005][30],cnt=1,is_end[1000005],ok[1000005];
void ins(string s){
  int len=s.length();
  int now=1;
  for(int i=0;i<len;i++){
    if(son[now][s[i]-'a']){
      now=son[now][s[i]-'a'];
    }
    else{
      son[now][s[i]-'a']=++cnt;
      now=son[now][s[i]-'a'];
    }
    if(i+1==len){
      is_end[now]=1;
    }
  }
}
void print(int now){
  for(int i=0;i<=25;i++){
    if(!son[now][i])continue;
    cout<<"goto "<<char('a'+i)<<endl;
    print(son[now][i]);
  }
}
int solve(string s){
  memset(ok,0,sizeof(ok));
  int len=s.length(),ans=0,now=1;
  for(int j=0;j<len;j++){
    now=son[now][s[j]-'a'];
    if(!now)break;
    if(is_end[now])ok[j]=1;
  }

  for(int i=0;i<len;i++){
    if(!ok[i])continue;
    else ans=i+1;
    now=1;
    for(int j=i+1;j<len;j++){
      now=son[now][s[j]-'a'];
      if(!now)break;
      if(is_end[now]){
      ok[j]=1;
      }
    }
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    string s;
    cin>>s;
    ins(s);
  }
  for(int i=1;i<=m;i++){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
  }
  return 0;
}
/*
5 1
abc
aba
c
bcbac
a
aabcabcabcabcabaabababbbc
*/
