#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tbsn{
  vector<int>v;
};
tbsn tbsn_plus(tbsn a,tbsn b){
  tbsn c;
  for(int i=0;i<min(a.v.size(),b.v.size());i++){
    c.v.push_back((a.v[i]+b.v[i])%3);
  }
  if(a.v.size()>b.v.size()){
    for(int i=min(a.v.size(),b.v.size());i<max(a.v.size(),b.v.size());i++){
      c.v.push_back(a.v[i]);
    }
  }
  else if(b.v.size()>a.v.size()){
    for(int i=min(a.v.size(),b.v.size());i<max(a.v.size(),b.v.size());i++){
      c.v.push_back(b.v[i]);
    }
  }
  return c;
}
tbsn to_tbsn(int a){
  tbsn b;
  while(a){
    b.v.push_back(a%3);
    a/=3;
  }
  return b;
}
int to_int(tbsn a){
  int b=0,bas=1;
  for(int i=0;i<a.v.size();i++){
    b+=bas*a.v[i];
    bas*=3;
  }
  return b;
}
int n,m,a[41],b[41],c[41],fa[41];
int gf(int now){
  if(fa[now]==now)return now;
  int father=gf(fa[now]);
  return fa[now]=father;
}
int tmp[41],ans;
void dfs(int deep,int num){
  if(num==n-1){
    tbsn d;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
      if(tmp[i]){
        d=tbsn_plus(d,to_tbsn(c[i]));
        int af=gf(a[i]),bf=gf(b[i]);
        if(af==bf)return;
        fa[af]=bf;
      }
    }
    ans+=to_int(d);
    ans%=1000000007;
    return;
  }
  if(deep==m+1)return;
  dfs(deep+1,num);
  tmp[deep]=1;
  dfs(deep+1,num+1);
  tmp[deep]=0;
}
signed main(){
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=m;i++){
    scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
  }
  dfs(1,0);
  printf("%lld\n",ans);
  return 0;
}
/*
5 7
3 2 7400
4 1 1618
4 2 9110
4 3 4264
5 1 537
5 2 4240
5 3 655
*/
