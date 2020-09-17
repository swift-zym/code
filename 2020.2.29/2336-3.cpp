#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mx,ans[100001];
bool dfs(int deep){
  if(deep>mx)return ans[deep-1]==n;
  if(ans[deep-1]*((1ll<<(mx-deep+1)))<n)return 0;
  for(int i=0;i<deep;i++)
  for(int j=i;j<deep;j++){
    if(ans[i]+ans[j]>n)break;
    if(ans[i]+ans[j]<=ans[deep-1])continue;
    ans[deep]=ans[i]+ans[j];
    if(dfs(deep+1))return 1;
  }
  return 0;
}
signed main(){
  while(scanf("%lld",&n)!=EOF){
    if(!n)break;
    for(mx=0;;mx++){
      if(dfs(1)){
        for(int i=0;i<=mx;i++){
          if(i)putchar(' ');
          printf("%lld",ans[i]);
        }
        putchar(10);
        break;
      }
    }
  }
  return 0;
}
