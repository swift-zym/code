#include<bits/stdc++.h>
using namespace std;
int n,flag,a[2001],ans[2001],vis[200001];
void dfs(int now,int f,int t,int sf,int st){
  if(flag)return;
  if(f==t){
  if(a[2*n]-sf-st<1||a[2*n]-sf-st>500)return;
  if(vis[a[now]-sf]==0&&vis[a[now]-st]==0)return;
  ans[f]=a[2*n]-sf-st;
  for(int i=1;i<=n;i++){
    if(i!=1)putchar(' ');
    printf("%d",ans[i]);
  }
  putchar(10);
  flag=1;
  }
  else{
  if(a[now]-sf>=1&&a[now]-sf<=500&&vis[a[now]-sf]){
    ans[f]=a[now]-sf;
    dfs(now+1,f+1,t,a[now],st);
    ans[f]=0;
  }
  if(a[now]-st>=1&&a[now]-st<=500&&vis[a[now]-st]){
    ans[t]=a[now]-st;
    dfs(now+1,f,t-1,sf,a[now]);
    ans[t]=0;
  }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
  sort(a+1,a+2*n+1);
  int m;
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
    int tmp;
    scanf("%d",&tmp);
    vis[tmp]=1;
  }
  dfs(1,1,n,0,0);
  return 0;
}
