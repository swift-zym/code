#include<bits/stdc++.h>
using namespace std;
int n,dp[100001],vis[100001];
struct node{
  int x,y,r,w;
  bool operator<(const node &t)const{
    return r<t.r;
  }
}a[100001];
double dis(node a,node b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(node a,node b){
  return dis(a,b)-double(a.r)<1e-6;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].r,&a[i].w);
  }
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    int sum=0;
    for(int j=1;j<i;j++){
      if(cmp(a[i],a[j])&&vis[j]==0){
        sum+=dp[j];
        vis[j]=1;
      }
    }
    dp[i]=max(a[i].w,sum);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(!vis[i])ans+=dp[i];
  }
  printf("%d\n",ans);
  return 0;
}
