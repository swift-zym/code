#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
    int l,r,k;
    scanf("%d%d%d",&l,&r,&k);
    int bf=k;
    for(int j=l;j<=r;j++){
      int v=min(k,a[j]);
      k-=v;
      a[j]-=v;
      if(!k)break;
    }
    printf("%d\n",bf-k);
  }
  
  return 0;
}
