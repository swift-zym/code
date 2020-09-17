#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int nxt[1000001];
int main(){
  ios::sync_with_stdio(0);
  while(cin>>s1){
    if(s1=="#")break;
    cin>>s2;
    nxt[0]=-1;
    int l1=s1.length(),l2=s2.length();
    for(int i=1,j=-1;i<l2;i++){
      while(s2[i]!=s2[j+1]&&j!=-1)j=nxt[j];
      if(s2[i]==s2[j+1])j++;
      nxt[i]=j;
    }
    int ans=0;
    for(int i=0,j=-1;i<l1;i++){
      while(s1[i]!=s2[j+1]&&j!=-1)j=nxt[j];
      if(s1[i]==s2[j+1])j++;
      if(j==l2-1){
        ans++;
        j=nxt[j];
        i+=(l2-1);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
