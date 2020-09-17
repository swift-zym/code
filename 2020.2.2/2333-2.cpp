#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,nxt[1000001],ans;
string s;
signed main(){
  ios::sync_with_stdio(0);
  cin>>n>>s;
  nxt[0]=-1;
  for(int i=1,j=-1;i<n;i++){
    while(j!=-1&&s[i]!=s[j+1])j=nxt[j];
    j+=(s[i]==s[j+1]);
    nxt[i]=j;
  }
  for(int i=0;i<n;i++){
    int now=i;
    while(nxt[now]!=-1)now=nxt[now];
    if(nxt[i]!=-1)nxt[i]=now;
    ans+=i-now;
  }
  cout<<ans<<endl;
  return 0;
}
