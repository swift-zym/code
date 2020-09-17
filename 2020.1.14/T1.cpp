#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len,ans;
char s[1100000];
string a[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
void dfs(string now,int deep){
  if(deep==n+1){
    for(int i=0;i<len+1;i++){
      string tmp=now;
      tmp.erase(i,(n-len));
      if(tmp==string(s))return;
    }
    ans++;
    ans%=998244353;
    return;
  }
  for(int i=0;i<=25;i++){
    dfs(now+a[i],deep+1);
  }
}
signed main(){
  scanf("%lld",&n);
  scanf("%s",s);
  len=strlen(s);
  dfs("",1);
  printf("%lld\n",ans);
  return 0;
}
