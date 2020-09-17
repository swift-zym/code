#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200001],k[200001],ans[200001],tmp[200001];
int add(int a,int b){
  return a+b>n?a+b-n:a+b;
}
signed main(){
  freopen("ring.in","r",stdin);
  freopen("ring.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=1;i<=m;i++)scanf("%lld",&k[i]);
  for(int i=1;i<=n;i++)tmp[i]=i;
  for(int i=1;i<=m;i++)ans[i]=-1e8;
  do{
    for(int now=1;now<=m;now++){
    int v=0;
    for(int i=1;i<=n;i++){
      v+=a[tmp[i]]*a[tmp[add(i,k[now])]];
    }
    ans[now]=max(ans[now],v);
    }
  }while(next_permutation(tmp+1,tmp+n+1));
  for(int i=1;i<=m;i++){
    printf("%lld\n",ans[i]);
  }
  return 0;
}
