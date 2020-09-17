#include<iostream>
#include<cmath>
using namespace std;
#define MOD 1000000007
#define int long long
int vis[1001][1001];
void exgcd(int a,int b,int &x,int &y){
  if(!b){
    x=1;y=0;
    return;
  }
  exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
}
int n,m,k,s,num,sum;
void dfs(int x,int y,int ans){
  if(vis[x][y]){
    ans=ceil(double(ans)/2);
  }
  if(x==n&&y==m){
    num++;
    sum+=ans;
    sum%=MOD;
  }
  if(x!=n){
    dfs(x+1,y,ans);
  }
  if(y!=m){
    dfs(x,y+1,ans);
  }
}

signed main(){
  scanf("%lld%lld%lld%lld",&n,&m,&k,&s);
  for(int i=1;i<=k;i++){
    int a,b;
    scanf("%lld%lld",&a,&b);
    vis[a][b]=1;
  }
  dfs(1,1,s);
  int x,y;
  exgcd(num,MOD,x,y);
  x=(x+MOD)%MOD;
  printf("%lld\n",(sum*x)%MOD);
  return 0;
}
