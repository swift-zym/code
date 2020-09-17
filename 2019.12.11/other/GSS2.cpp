#include<bits/stdc++.h>
#define int long long
using namespace std;
struct que{
  int l,r,id;
  bool operator <(const que &t)const{
    return r<t.r;
  }
}q[100001];
struct node{
  int sum,mx,ls,lm,l,r;
  void DEBUG(){
  }
}a[400001];
int pre[200001];
void pushup(int now){
  a[now].sum=max(a[now*2].sum,a[now*2+1].sum);
  a[now].mx=max(a[now*2].mx,a[now*2+1].mx);
}
void pushdown(int now){
  a[now*2].mx=max(a[now*2].mx,a[now*2].sum+a[now].lm);
  a[now*2].sum+=a[now].ls;
  a[now*2].lm=max(a[now*2].lm,a[now*2].ls+a[now].lm);
  a[now*2].ls+=a[now].ls;
  a[now*2+1].mx=max(a[now*2+1].mx,a[now*2+1].sum+a[now].lm);
  a[now*2+1].sum+=a[now].ls;
  a[now*2+1].lm=max(a[now*2+1].lm,a[now*2+1].ls+a[now].lm);
  a[now*2+1].ls+=a[now].ls;
  a[now].ls=a[now].lm=0;
}
void change(int now,int l,int r,int v){
  a[now].DEBUG();
  int L=a[now].l,R=a[now].r;
  if(L==l&&R==r){
    a[now].ls+=v;
    a[now].sum+=v;
    a[now].lm=max(a[now].lm,a[now].ls);
    a[now].mx=max(a[now].mx,a[now].sum);
    return;
  }
  pushdown(now);
  int mid=(L+R)/2;
  if(r<=mid){
    change(now*2,l,r,v);
  }
  else if(l>mid){
    change(now*2+1,l,r,v);
  }
  else{
    change(now*2,l,mid,v);
    change(now*2+1,mid+1,r,v);
  }
  pushup(now);
  a[now].DEBUG();
}
node ask(int now,int l,int r){
  int L=a[now].l,R=a[now].r;
  if(l==L&&r==R){
    return a[now];
  }
  pushdown(now);
  int mid=(L+R)/2;
  if(r<=mid){
    return ask(now*2,l,r);
  }
  else if(l>mid){
    return ask(now*2+1,l,r);
  }
  else{
    node aa,bb=ask(now*2,l,mid),cc=ask(now*2+1,mid+1,r);
    aa.mx=max(bb.mx,cc.mx);
    aa.sum=bb.sum+cc.sum;
    return aa;
  }
}
void build(int now,int l,int r){
  a[now].l=l;
  a[now].r=r;
  a[now].ls=a[now].lm=a[now].sum=a[now].mx=0;
  if(l==r)return;
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
}
int b[100001],n,m,ans[100001];
signed main(){
  scanf("%lld",&n);
  build(1,1,n);
  for(int i=1;i<=n;i++){
    scanf("%lld",&b[i]);
  }
  scanf("%lld",&m);
  for(int i=1;i<=m;i++){
    scanf("%lld%lld",&q[i].l,&q[i].r);
    q[i].id=i;
  }
  sort(q+1,q+m+1);
  int pos=1;
  for(int i=1;i<=n;i++){
    change(1,pre[b[i]+100000]+1,i,b[i]);
    pre[b[i]+100000]=i;
    while(pos<=m&&q[pos].r==i){
      ans[q[pos].id]=ask(1,q[pos].l,q[pos].r).mx;
      pos++;
    }
  }
  for(int i=1;i<=m;i++){
    printf("%lld\n",ans[i]);
  }
  return 0;
}
