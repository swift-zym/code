#include<bits/stdc++.h>
using namespace std;
string s;
int nxt[1000001],len;
int main(){
  ios::sync_with_stdio(0);
  cin>>len;
  cin>>s;
  nxt[0]=-1;
  for(int i=1,j=-1;i<len;i++){
    while(j!=-1&&s[i]!=s[j+1])j=nxt[j];
    if(s[i]==s[j+1])j++;
    nxt[i]=j;
  }
  printf("%d\n",len-1-nxt[len-1]);
  return 0;
}
