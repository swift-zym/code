#include<bits/stdc++.h>
using namespace std;
int n,a[15];
bool flag;
void dfs(int deep,int sum,int num){
  if(deep==n+1&&sum==0&&num!=0){
    flag=1;
    return;
  }
  if(deep==n+1)return;
  dfs(deep+1,sum,num);
  if(flag)return;
  dfs(deep+1,(sum^a[deep]),num+1);
}
int main(){
  for(int i=1;i<=10;i++){
    scanf("%d",&n);
    flag=0;
    for(int j=1;j<=n;j++)scanf("%d",&a[j]);
    dfs(1,0,0);
    if(flag){
      puts("NO");
    }
    else{
      puts("YES");
    }
  }
  return 0;
}
