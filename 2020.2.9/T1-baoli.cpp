#include<bits/stdc++.h>
#define int long long
using namespace std;
int ls[100010<<5],rs[100010<<5],vaule[100010<<5],root[100010],cnt;
void build(int &now,int l,int r){
    now=++cnt;
    if(l==r)return;
    int mid=(l+r)/2;
    build(ls[now],l,mid);
    build(rs[now],mid+1,r);
}
int add(int lastRoot,int l,int r,int to){
     int newRoot=++cnt;
     ls[newRoot]=ls[lastRoot];rs[newRoot]=rs[lastRoot];vaule[newRoot]=vaule[lastRoot]+1;
     if(l==r)return newRoot;
     int mid=(l+r)/2;
     if(to<=mid)ls[newRoot]=add(ls[newRoot],l,mid,to);
     else rs[newRoot]=add(rs[newRoot],mid+1,r,to);
     return newRoot;
}
int sum(int now,int l,int r,int L,int R){
    if(l==L&&r==R)return vaule[now];
    int mid=(l+r)/2;
    if(R<=mid){
      return sum(ls[now],l,mid,L,R);
    }
    else if(L>mid){
      return sum(rs[now],mid+1,r,L,R);
    }
    else{
      return sum(ls[now],l,mid,L,mid)+sum(rs[now],mid+1,r,mid+1,R);
    }
}
int ask(int l,int r,int v){
  return sum(root[r],0,100001,v,100001)-sum(root[l-1],0,100001,v,100001);
}
int n,w,m;
struct node{
  int a,b;
  bool operator <(const node &t)const{
    return b<t.b;
  }
}a[100001];
int cal(int x,int pos){
  return x*ask(1,pos,x);
}
void file(){
  freopen("T1.in","r",stdin);
  freopen("T1.ans","w",stdout);
}
signed main(){
    scanf("%lld%lld",&n,&w);
    int mx=-1;
    for(int i=1;i<=n;i++){
      scanf("%lld%lld",&a[i].a,&a[i].b);
      mx=max(a[i].a,mx);
    }
    sort(a+1,a+n+1);
    build(root[0],0,100001);
    for(int i=1;i<=n;i++){
        root[i]=add(root[i-1],0,100001,a[i].a);
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
      int c;
      scanf("%lld",&c);
      int pos=lower_bound(a+1,a+n+1,node{0,c})-a;
      int ans=(n-pos+1)*c*w;
      pos--;
      if(pos){
      int mx_ans=-1,id;
      for(int i=0;i<=mx+1;i++){
        if(cal(i,pos)>mx_ans)mx_ans=cal(i,pos),id=i;
      }
      ans+=mx_ans;
      }
      printf("%lld\n",ans);
    }
    return 0;
}
