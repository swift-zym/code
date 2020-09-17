#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
}a[501];
struct edge{
  int s,t;
  double l;
  bool operator <(const edge &t)const{
    return l<t.l;
  }
}b[1000001];
int cnt;
double dis(node a,node b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int s,p,f[501];
int gf(int now){
  if(f[now]==now)return now;
  int fat=gf(f[now]);
  return f[now]=fat;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
  scanf("%d%d",&s,&p);
  for(int i=1;i<=p;i++){
    scanf("%d%d",&a[i].x,&a[i].y);
  }
  cnt=0;
  for(int i=1;i<=p;i++)
  for(int j=i+1;j<=p;j++){
    b[++cnt].s=i;
    b[cnt].t=j;
    b[cnt].l=dis(a[i],a[j]);
  }
  sort(b+1,b+cnt+1);
  double ans=0;
  for(int i=1;i<=p;i++)f[i]=i;
  for(int i=1,j=p-s;i<=cnt&&j;i++){
    int fs=gf(b[i].s),ft=gf(b[i].t);
    if(fs!=ft){
      f[fs]=ft;
      j--;
      ans=max(ans,b[i].l);
    }
  }
  printf("%0.2lf\n",ans);
  }
  return 0;
}
