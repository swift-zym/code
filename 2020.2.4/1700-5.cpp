#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t[1025][1025];
int sum(int x,int y){
  int v=0;
  for(int i=x;i>=1;i-=(i&-i))
  for(int j=y;j>=1;j-=(j&-j)){
    v+=t[i][j];
  }
  return v;
}
void add(int x,int y,int v){
  for(int i=x;i<=n;i+=(i&-i))
  for(int j=y;j<=n;j+=(j&-j)){
    t[i][j]+=v;
  }
}
signed main(){
  scanf("%lld",&n);
  int opt;
  while(scanf("%lld",&opt)!=EOF){
    if(opt==3)break;
    else if(opt==2){
      int X1,X2,Y1,Y2;
      scanf("%lld%lld%lld%lld",&X1,&Y1,&X2,&Y2);
      printf("%lld\n",sum(X2+1,Y2+1)-sum(X2+1,Y1)-sum(X1,Y2+1)+sum(X1,Y1));
    }
    else{
      int x,y,k;
      scanf("%lld%lld%lld",&x,&y,&k);
      add(x+1,y+1,k);
    }
  }
  return 0;
}
