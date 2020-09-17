#include<bits/stdc++.h>
using namespace std;
int n,m,h[16],r[16],ans=2147483647;
void dfs(int deep,int v,int sum,int s){
  if(v<0||deep>m+1)return;
  if(v==0&&deep==m+1){
    sum+=r[1]*r[1];
    ans=min(ans,sum);
    return;
  }
  if(sum+s+r[1]*r[1]>ans||v>(r[deep-1]*r[deep-1]*h[deep-1]*s))return;
  if(deep+1>m+1)return;
  for(int i=r[deep-1]-1;i>=s;i--)
  for(int j=h[deep-1]-1;j>=s;j--){
    if(v-i*i*j>=0){
      r[deep]=i;
      h[deep]=j;
      dfs(deep+1,v-i*i*j,sum+(i*2*j),s-1);
      r[deep]=0;
      h[deep]=0;
    }
  }
}
int main(){
  scanf("%d%d",&n,&m);
  r[0]=h[0]=sqrt(n);
  dfs(1,n,0,m);
  cout<<(ans==2147364847?0:ans)<<endl;;
  return 0;
}
