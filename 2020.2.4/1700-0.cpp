#include<bits/stdc++.h>
using namespace std;
int n,m,t[1000000];
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
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    int a;
    scanf("%d",&a);
    add(i,a);
  }
  for(int i=1;i<=m;i++){
    int k,a,b;
    scanf("%d%d%d",&k,&a,&b);
    if(k==0){
      printf("%d\n",sum(b)-sum(a-1));
    }
    else{
      add(a,b);
    }
  }
  return 0;
}
