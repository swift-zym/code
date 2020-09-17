#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,a[100001],la;
signed main(){
  scanf("%lld%lld%lld",&n,&m,&t);
  for(int i=1;i<=m;i++){
    int op;
    scanf("%lld",&op);
    if(op==1){
      int l,r,d;
      scanf("%lld%lld%lld",&l,&r,&d);
      if(t)l=(l+la)%(n+1),r=(r+la)%(n+1),d=(d+la)%(n+1);
      for(int i=l;i<=r;i++)a[i]+=d;
    }
    else if(op==2){
      int A,B,C;
      scanf("%lld%lld%lld",&A,&B,&C);
      if(t)A=(A+la)%(n+1),B=(B+la)%(n+1),C=(C+la)%(n+1);
      A*=(1<<C);B*=(1<<C);
      for(int i=0;i<(1<<C);i++){
        swap(a[A+i],a[B+i]);
      }
    }
    else{
      int l,r;
      scanf("%lld%lld",&l,&r);
      if(t)l=(l+la)%(n+1),r=(r+la)%(n+1);
      la=0;
      for(int i=l;i<=r;i++){
        la+=a[i];
      }
      printf("%lld\n",la);
    }
  }
  return 0;
}
