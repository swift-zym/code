#include<bits/stdc++.h>
using namespace std;
int n,a[500001],b[500001];
void dfs(int deep,int id,int x,int y,string ans){
  if(deep==2*n){
    if(x==y){
      puts(ans.c_str());
      exit(0);
    }
    return;
  }
  if(id==1){
    if(a[deep+1]>=a[deep]){
      dfs(deep+1,1,x+1,y,ans+"A");
    }
    if(b[deep+1]>a[deep]){
      dfs(deep+1,2,x,y+1,ans+"B");
    }
  }
  else{
    if(b[deep+1]>=b[deep]){
      dfs(deep+1,2,x,y+1,ans+"B");
    }
    if(a[deep+1]>b[deep]){
      dfs(deep+1,1,x+1,y,ans+"A");
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=2*n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=2*n;i++){
    scanf("%d",&b[i]);
  }
  dfs(1,1,1,0,"A");
  dfs(1,2,0,1,"B");
  puts("-1");
  return 0;
}
