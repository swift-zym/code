#include<bits/stdc++.h>
#define int long long
#define MOD 9982443535
using namespace std;
int n,m,head[100001],nxt[400001],to[400001],cnt;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
namespace subtask1{
  int c[100001],num,ans;
  void dfs(int deep){
    if(deep==n+1){
      ans++;
      return;
    }
    for(int i=1;i<=num;i++){
      bool flag=1;
      for(int j=head[deep];j;j=nxt[j]){
        if(i==c[to[j]]){
          flag=0;
          break;
        }
      }
      if(flag){
        c[deep]=i;
        dfs(deep+1);
        c[deep]=0;
      }
    }
  }
  void solve(){
    for(int i=1;i<=n;i++){
      num=i;
      ans=0;
      dfs(1);
      if(i!=1)putchar(' ');
      printf("%lld",ans);
    }
  }
}
namespace subtask2{
  int siz[100001],num,vis[100001];
  void dfs(int now,int fa){
      vis[now]=1;
      siz[now]=1;
      for(int i=head[now];i;i=nxt[i]){
      if(to[i]!=fa){
        dfs(to[i],now);
        siz[now]+=siz[to[i]];
      }
      }
  }
  int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?(((tmp*tmp)%MOD)*a)%MOD:(tmp*tmp)%MOD;
  }
  void solve(){
    for(num=1;num<=n;num++){
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
      if(!vis[i]){
        dfs(i,i);
        ans+=(qpow(num-1,siz[i]-1)*num)%MOD;
        ans%=MOD;
        }
    }
    if(num!=1)putchar(' ');
    printf("%lld",ans);
  }
  }
}
signed main(){
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%lld%lld",&a,&b);
    add(a,b);
    add(b,a);
  }
  if(n<=50&&m<=50){
    subtask1::solve();
  }
  else{
    subtask2::solve();
  }
  putchar(10);
  return 0;
}
/*
6 6
1 3
2 4
1 4
2 5
2 6
3 4
*/
