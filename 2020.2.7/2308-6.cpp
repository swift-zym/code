#include<bits/stdc++.h>
using namespace std;
int n,c[21],p[21],l[21];
int exgcd(int a,int b,int &x,int &y){
  if(!b){
    x=1;y=0;
    return a;
  }
  int tmp=exgcd(b,a%b,x,y);
  int t=x;x=y;y=t-a/b*y;
  return tmp;
}
bool check(int x){
  for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++){
    int A=p[i]-p[j],B=x,C=c[j]-c[i],x,y;
    int d=exgcd(A,B,x,y);
    if(C%d)continue;
    A/=d;B/=d;C/=d;
    if(B<0)B=-B;
    x=(x*C%B+B)%B;
    if(x<=l[i]&&x<=l[j])return 0;
  }
  return 1;
}
int main(){
  scanf("%d",&n);
  int mx=-1;
  for(int i=1;i<=n;i++)scanf("%d%d%d",&c[i],&p[i],&l[i]),mx=max(mx,c[i]);
  for(int i=mx;;i++){
    if(check(i)){
      printf("%d\n",i);
      return 0;
    }
  }
  return 0;
}
