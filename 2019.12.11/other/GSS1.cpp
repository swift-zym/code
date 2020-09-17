#include<bits/stdc++.h>
using namespace std;
struct node{
  int l,r,sum,sa,sb,ans;
}a[400001];
int b[100001];
int n,m;
void pushup(int now){
  a[now].sa=max(a[now*2].sa,a[now*2].sum+a[now*2+1].sa);
  a[now].sb=max(a[now*2+1].sb,a[now*2].sb+a[now*2+1].sum);
  a[now].ans=max(a[now*2].ans,max(a[now*2+1].ans,a[now*2].sb+a[now*2+1].sa));
  a[now].sum=a[now*2].sum+a[now*2+1].sum;
}
void build(int now,int l,int r){
  a[now].l=l;
  a[now].r=r;
  if(l==r){
    a[now].ans=a[now].sum=a[now].sa=a[now].sb=b[l];
    return;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  pushup(now);
}
node ask(int now,int l,int r){
  if(a[now].l==l&&a[now].r==r){
    return a[now];
  }
  int L=a[now].l,R=a[now].r;
  int mid=(L+R)/2;
  if(r<=mid){
    return ask(now*2,l,r);
  }
  else if(l>mid){
    return ask(now*2+1,l,r);
  }
  else{
    node a,b,c;
    b=ask(now*2,l,mid);
    c=ask(now*2+1,mid+1,r);
    a.sum=b.sum+c.sum;
    a.sa=max(b.sa,b.sum+c.sa);
    a.sb=max(c.sb,b.sb+c.sum);
    a.ans=max(b.ans,max(c.ans,b.sb+c.sa));
    return a;
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]);
  }
  build(1,1,n);
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",ask(1,l,r).ans);
  }
  return 0;
}
