#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y,z,col;
  bool operator <(const node &t)const{
    if(z!=t.z)
    return z<t.z;
    else return col<t.col;
  }
}a[100001];
int n,m,k,ans,fa[50001];
int gf(int now){
  if(fa[now]==now)return now;
  int father=gf(fa[now]);
  fa[now]=father;
  return father;
}
int solve(){
  ans=0;
  int v=0,now=0;
  for(int i=1;i<=n;i++)fa[i]=i;
  sort(a+1,a+m+1);
  for(int i=1;i<=m;i++){
    int fx=gf(a[i].x),fy=gf(a[i].y);
    if(fx!=fy){
      fa[fx]=fy;
      ans+=a[i].z;
      if(a[i].col==0)v++;
      now++;
      if(now==n-1)break;
    }
  }
  //cout<<v<<endl;
  return v;
}
int check(int x){
  for(int i=1;i<=m;i++){
    if(a[i].col==0)
    a[i].z+=x;
  }
  int num=solve();
  for(int i=1;i<=m;i++){
    if(a[i].col==0)
    a[i].z-=x;
  }
  return num;
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++){
    scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].col);
    a[i].x++;
    a[i].y++;
  }
  int l=-10000,r=10000,f;
  while(l<=r){
    //cout<<l<<" "<<r<<endl;
    int mid=(l+r)/2;
    //cout<<check(mid)<<endl;
    if(check(mid)>=k){
      l=mid+1;
      f=mid;
    }
    else{
      //printf("%d<%d",check(mid),k);
      r=mid-1;
    }
  }
  /*cout<<"f="<<f<<endl;
  if(check(f)!=k){
    puts("Error");
    cout<<check(l)<<" "<<k<<endl;
  }*/
  /*if(check(f)!=k){
    puts("Error");
  */
  /*while(check(f)<k){
    f--;
  }*/
  check(f);
  printf("%d\n",ans-f*k);
  return 0;
}
