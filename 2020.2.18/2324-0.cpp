#include<bits/stdc++.h>
using namespace std;
int n,m,du[1001],fa[1001];
int gf(int now){
  if(fa[now]==now)return now;
  int f=gf(fa[now]);
  return fa[now]=f;
}
int main(){
  while(scanf("%d",&n)){
    if(!n)break;
    scanf("%d",&m);
    memset(du,0,sizeof(du));
    for(int i=1;i<=n;i++){
      fa[i]=i;
    }
    for(int i=1;i<=m;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      du[a]++;
      du[b]++;
      fa[gf(a)]=gf(b);
    }
    int flag=1;
    int num=0;
    for(int i=1;i<=n;i++){
      if(fa[i]==i)num++;
      if(du[i]%2)flag=0;
    }
    if(num!=1)flag=0;
    printf("%d\n",flag);
  }
  return 0;
}
