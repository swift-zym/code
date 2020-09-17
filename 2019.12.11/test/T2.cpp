#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
int ans,a[101];
int solve(int x){
  int v=0;
  while(x){
    x-=x&-x;
    v++;
  }
  return v;
}
unordered_map<int,int>ma;
void dfs(int deep,int last,int sum){
  if(last>sum){
  ma.clear();
  for(int i=1;i<deep;i++){
    ma[a[i]]++;
  }
  int tmp=0;
  for(int i=1;i<deep;i++){
    tmp+=solve(ma[a[i]]);
    ma[a[i]]=0;
  }
  ans=max(ans,tmp);
  return;
  }
  for(int i=last;i<=sum;i++){
    a[deep]=i;
    dfs(deep+1,i,sum-i);
  }
}
int li[]={0,1,1,2,2,3,3
  ,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,7,8,8,8,8,8,8};
int main(){
  /*int t;
  scanf("%d",&t);
  while(t--){
    ans=0;
    int n;
    scanf("%d",&n);
    if(n<=30){
      printf("%d\n",li[n]);
      continue;
    }
    dfs(1,1,n);
    printf("%d\n",ans);
  }*/
  freopen("T2-list.out","w",stdout);
  for(int i=1;i<=20;i++){
    cerr<<i<<endl;
    ans=0;
    dfs(1,1,i);
    printf("%d:%d\n",i,ans);
  }
  return 0;
}
