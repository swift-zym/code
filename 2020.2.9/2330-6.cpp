#include<bits/stdc++.h>
using namespace std;
struct edge{
  int a,b,c=-1,bel;
  bool operator <(const edge &t)const{
    return c<t.c;
  }
}a[1001];
struct node{
  int l,r,ned=0;
}b[1001];
int n,m,cnt,f[1001],num;
int gf(int now){
  if(f[now]==now)return now;
  int fat=gf(f[now]);
  return f[now]=fat;
}
void clear(){
  for(int i=1;i<=n;i++){
    f[i]=i;
  }
}
void dfs(int now,int add,int bel){
  if(now>b[bel].r){
    if(add==b[bel].ned)num++;
    return;
  }
  int tmp[101];
  for(int i=1;i<=n;i++)tmp[i]=f[i];
  int fx=gf(a[now].a),fy=gf(a[now].b);
  if(fx!=fy){
    f[fx]=fy;
    dfs(now+1,add+1,bel);
  }
  for(int i=1;i<=n;i++)f[i]=tmp[i];
  dfs(now+1,add,bel);
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
  }
  sort(a+1,a+m+1);
  for(int i=1;i<=m;i++){
    if(a[i].c==a[i-1].c){
      a[i].bel=cnt;
      b[cnt].r++;
    }
    else{
      cnt++;
      b[cnt].l=i;
      b[cnt].r=i;
      a[i].bel=cnt;
    }
  }
  clear();
  for(int i=1,j=0;i<=m&&j<n-1;i++){
    int fx=gf(a[i].a),fy=gf(a[i].b);
    if(fx!=fy){
      f[fx]=fy;
      b[a[i].bel].ned++;
      j++;
    }
    if(i==m&&j!=n-1){
      puts("0");
      return 0;
    }
  }
  clear();
  int ans=1;
  for(int i=1;i<=cnt;i++){
    if(b[i].ned>0){
      num=0;
      dfs(b[i].l,0,i);
      ans=(ans*num)%31011;
      for(int j=b[i].l;j<=b[i].r;j++){
        int fx=gf(a[j].a),fy=gf(a[j].b);
        if(fx!=fy){
          f[fx]=fy;
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
