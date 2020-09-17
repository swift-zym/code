#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int n;
struct node{
  int x,y;
}a[51];
struct edge{
  int f,t,l;
  bool operator<(const edge &tt)const{
    return l<tt.l;
  }
}tmp[5001];
int cnt,fa[51];
int get_len(node a,node b){
  return abs(a.x-b.x)+abs(a.y-b.y);
}
void add(int a,int b,int l){
  tmp[++cnt].f=a;
  tmp[cnt].t=b;
  tmp[cnt].l=l;
}
int gf(int now){
  if(fa[now]==now)return now;
  int father=gf(fa[now]);
  return fa[now]=father;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=n;i++){
    scanf("%d%d",&a[i].x,&a[i].y);
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      add(i,j,(get_len(a[i],a[j])+1)/2);
    }
  }
  sort(tmp+1,tmp+cnt+1);
  int num=0;int mx=0;
  for(int i=1;i<=cnt;i++){
    if(gf(tmp[i].f)!=gf(tmp[i].t)){
      fa[gf(tmp[i].f)]=gf(tmp[i].t);
      num++;
      mx=max(mx,tmp[i].l);
      if(num==n-1)break;
    }
  }
  printf("%d\n",mx);
  return 0;
}
