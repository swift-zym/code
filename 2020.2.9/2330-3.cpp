#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
  int s,t,v;
  bool operator <(const node &t)const{
    return v<t.v;
  }
}a[100001];
int n,sum,f[100001],ans[100001];
int gf(int now){
  if(f[now]==now)return now;
  int fat=gf(f[now]);
  return f[now]=fat;
}
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<n;i++){
    scanf("%lld%lld%lld",&a[i].s,&a[i].t,&a[i].v);
    f[i]=i;
    sum+=a[i].v;
    ans[i]=1;
  }
  f[n]=n;
  ans[n]=1;
  sort(a+1,a+n);
  for(int i=1;i<n;i++){
    int fx=gf(a[i].s),fy=gf(a[i].t);
    sum+=(a[i].v+1)*(ans[fx]*ans[fy]-1);
    f[fx]=fy;
    ans[fy]+=ans[fx];
  }
  printf("%lld\n",sum);
  return 0;
}
