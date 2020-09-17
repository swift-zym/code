#include<bits/stdc++.h>
using namespace std;
struct edge{
  int s,t,l;
  bool operator <(const edge t)const{
    return l<t.l;
  }
}a[100000];
int cnt;
void add(int A,int B,int l){
  a[++cnt].s=A;
  a[cnt].t=B;
  a[cnt].l=l;
}
int n,f[300];
int gf(int now){
  if(f[now]==now)return now;
  int fat=gf(f[now]);
  return f[now]=fat;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    f[i]=i;
    int b;
    scanf("%d",&b);
    add(0,i,b);
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    int b;
    scanf("%d",&b);
    add(i,j,b);
  }
  sort(a+1,a+cnt+1);
  int ans=0;
  for(int i=1,j=n-1;i<=cnt&&j;i++){
    int fx=gf(a[i].s),fy=gf(a[i].t);
    if(fx!=fy){
      f[fx]=fy;
      ans+=a[i].l;
    }
  }
  printf("%d\n",ans);
  return 0;
}
