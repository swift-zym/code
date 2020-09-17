#include<bits/stdc++.h>
using namespace std;
struct tree{
int n,t[1000000];
void build(int maxn){
  n=maxn;
}
void add(int a,int v){
  for(int i=a;i<=n;i+=(i&-i)){
    t[i]+=v;
  }
}
int sum(int a){
  int v=0;
  for(int i=a;i>=1;i-=(i&-i)){
    v+=t[i];
  }
  return v;
}
}t;
int n,k;
int main(){
  scanf("%d%d",&n,&k);
  t.build(n);
  for(int i=1;i<=k;i++){
    char c=getchar();
    while(c<'A'||c>'C')c=getchar();
    int a,b;
    scanf("%d",&a);
    if(c=='A'){
      printf("%d\n",t.sum(a));
    }
    else if(c=='B'){
      scanf("%d",&b);
      t.add(a,b);
    }
    else{
      scanf("%d",&b);
      t.add(a,-b);
    }
  }
  return 0;
}
