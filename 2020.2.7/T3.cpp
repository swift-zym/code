#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,vis[1001],l[1001],r[1001],c[1001],cnt,x,y;
void dfs(int deep){
  if(deep==2*n+1){
    int sum=0,tmp=0;
    for(int i=1;i<=n;i++){
      c[i]=abs(l[i]-r[i]);
      sum+=c[i];
    }
    for(int i=1;i<=n;i++){
      tmp+=(sum-c[i]*n)*(sum-c[i]*n);
    }
    y++;
    x+=tmp;
    return;
  }
  if(vis[deep])dfs(deep+1);
  else{
    for(int i=deep+1;i<=2*n;i++){
      if(vis[i])continue;
      vis[i]=1;
      l[++cnt]=deep;
      r[cnt]=i;
      dfs(deep+1);
      cnt--;
      vis[i]=0;
    }
  }
}
void exgcd(int a,int b,int &X,int &Y){
  if(b==0){
    X=1;

    Y=0;
    return;
  }
  exgcd(b,a%b,X,Y);
  int t=X;X=Y;Y=t-a/b*Y;
}
signed main(){
  scanf("%lld",&n);
  dfs(1);
  y*=n;
  y*=n;
  y*=n;
  int X,Y;
  exgcd(y,1000000007,X,Y);
  x*=((X+1000000007)%1000000007);
  x%=1000000007;
  printf("%lld\n",x);
  return 0;
}
