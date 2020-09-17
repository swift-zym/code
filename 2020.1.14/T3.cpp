#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define int long long
using namespace std;
bool check(int n){
  char a,b;
  bool ua=0,ub=0;
  char s[20];
  sprintf(s,"%lld",n);
  int len=strlen(s);
  for(int i=0;i<len;i++){
    if(ua == false){
        ua=true;
        a=s[i];
    }
    else if(s[i]==a){}
    else if(ub == false){
        ub=true;
        b=s[i];
    }
    else if(s[i]==b){}
    else{
      return false;
    }
  }
  return true;
}
unordered_map<int,int>ma;
vector<int>v;
int mxdep;
void dfs(int a,int b,int deep,int now){
  if(!ma[now]){
    ma[now]=1;
    v.push_back(now);
  }
  if(deep==14)
  return;
  dfs(a,b,deep+1,now*10+a);
  dfs(a,b,deep+1,now*10+b);
}
signed main(){
  for(int i=0;i<=9;i++){
    for(int j=i;j<=9;j++){
      dfs(i,j,1,0);
    }
  }
  ma[10000000000000ll]=1;
  v.push_back(10000000000000ll);
  int T;
  scanf("%lld",&T);
  while(T--){
    int n,siz=v.size();
    scanf("%lld",&n);
    if(ma[n]){
      puts("1");
      continue;
    }
    bool flag=0;
    for(int i=0;i<siz;i++){
      if(ma[n-v[i]]){
        puts("2");
        flag=1;
        break;
      }
    }
    if(flag){
      continue;
    }
    puts("3");
  }
  return 0;
}
