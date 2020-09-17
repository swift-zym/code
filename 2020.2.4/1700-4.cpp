#include<bits/stdc++.h>
using namespace std;
struct tree{
int n,t[1000000];
void build(int maxn){
  n=maxn;
}
void add(int a,int v){
  for(int i=a;i<=n;i+=(i&-i)){
    t[i]+=v;
  }
}
int sum(int a){
  int v=0;
  for(int i=a;i>=1;i-=(i&-i)){
    v+=t[i];
  }
  return v;
}
}t;
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  t.build(n+1);
  for(int i=1;i<=m;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int l,r;
      scanf("%d%d",&l,&r);
      t.add(l,1);
      t.add(r+1,-1);
    }
    else{
      int l;
      scanf("%d",&l);
      printf("%d\n",t.sum(l)%2);
    }
  }
}
