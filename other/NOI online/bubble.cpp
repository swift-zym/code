#include<bits/stdc++.h>
using namespace std;
int n,m,p[200001],tmp[200001];
int solve(int k){
  k=min(n,k);
  for(int i=1;i<=n;i++){
    tmp[i]=p[i];
  }
  for(int i=1;i<=k;i++){
    for(int j=1;j<n;j++){
      if(tmp[j]>tmp[j+1])swap(tmp[j],tmp[j+1]);
    }
  }
  int v=0;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(tmp[i]>tmp[j])v++;
    }
  }
  return v;
}
int main(){
  freopen("bubble.in","r",stdin);
  freopen("bubble.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&p[i]);
  for(int i=1;i<=m;i++){
    int t,c;
    scanf("%d%d",&t,&c);
    if(t==1){
      swap(p[c],p[c+1]);
    }
    else{
      printf("%d\n",solve(c));
    }
  }
  return 0;
}
