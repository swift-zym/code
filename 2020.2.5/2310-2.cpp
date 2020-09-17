#include<bits/stdc++.h>
using namespace std;
int vis[1000001],ans[1000001],n,a[100001];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    vis[a[i]]+=1;
  }
  for(int i=1;i<=1000000;i++){
    if(vis[i]){
      for(int j=1;j<=1000000/i;j++){
        if(vis[i*j]){
          ans[i*j]+=vis[i];
          if(j==1)ans[i*j]--;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    printf("%d\n",ans[a[i]]);
  }
  return 0;
}
