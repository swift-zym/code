/*
ID:swiftui
LANG:C++
TASK:lineup
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
unordered_map<string,int>ma;
string s[8]={"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
int n,a[9],vis[9];
int b[8],c[8];
void dfs(int deep){
  if(deep>8){
    bool flag=1;
    for(int i=1;i<=n;i++){
    for(int j=1;j<=8;j++){
      if(a[j]==b[i]){
        flag=0;
        if(j!=1&&a[j-1]==c[i])flag=1;
        if(j!=8&&a[j+1]==c[i])flag=1;
        break;
      }
    }
    if(!flag)break;
    }
    if(flag){
      for(int i=1;i<=8;i++){
        cout<<s[a[i]]<<endl;
      }
      exit(0);
    }
    return;
  }
  for(int i=0;i<8;i++){
    if(!vis[i]){
      a[deep]=i;
      vis[i]=1;
      dfs(deep+1);
      vis[i]=0;
    }
  }
}
int main(){
  freopen("lineup.in","r",stdin);
  freopen("lineup.out","w",stdout);
  ios::sync_with_stdio(0);
  sort(s,s+8);
  for(int i=0;i<8;i++){
    ma[s[i]]=i;
  }
  cin>>n;
  for(int i=1;i<=n;i++){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cin>>s2;
    cin>>s2;
    cin>>s2;
    cin>>s2;
    b[i]=ma[s1];
    c[i]=ma[s2];
  }
  dfs(1);
  return 0;
}
