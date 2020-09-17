#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
  int mx,sum,l,r;
}a[800001];
void pushup(int now){
  a[now].mx=max(a[now*2].mx,a[now*2+1].mx);
  a[now].sum=a[now*2].sum+a[now*2+1].sum;
}
void change(int now,int l,int r){
  int L=a[now].l,R=a[now].r;
  if(L==R){
    a[now].sum=sqrt(a[now].sum);
    a[now].mx=sqrt(a[now].mx);
    return;
  }
  int mid=(L+R)/2;
  if(r<=mid){
  if(a[now*2].mx>1)
    change(now*2,l,r);
  }
  else if(l>mid){
  if(a[now*2+1].mx>1)
    change(now*2+1,l,r);
  }
  else{
  if(a[now*2].mx>1)
    change(now*2,l,mid);
  if(a[now*2+1].mx>1)
    change(now*2+1,mid+1,r);
  }
  pushup(now);
}
int ask(int now,int l,int r){
  int L=a[now].l,R=a[now].r;
  if(l==L&&r==R){
    return a[now].sum;
  }
  int mid=(L+R)/2;
  if(r<=mid){
    return ask(now*2,l,r);
  }
  else if(l>mid){
    return ask(now*2+1,l,r);
  }
  else{
    return ask(now*2,l,mid)+ask(now*2+1,mid+1,r);
  }
}
int n,m,b[100001];
void build(int now,int l,int r){
  a[now].l=l;
  a[now].r=r;
  if(l==r){
    a[now].sum=a[now].mx=b[l];
    return;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  pushup(now);
}
signed main(){
  int num=0;
  while(scanf("%lld",&n)!=EOF){
  num++;
  printf("Case #%d:\n",num);
  for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
  build(1,1,n);
  scanf("%lld",&m);
  for(int i=1;i<=m;i++){
    int pos,l,r;
    scanf("%lld%lld%lld",&pos,&l,&r);
    if(l>r)swap(l,r);
    if(!pos){
      change(1,l,r);
    }
    else{
      printf("%lld\n",ask(1,l,r));
    }
  }
  printf("\n");
 }
  return 0;
}
