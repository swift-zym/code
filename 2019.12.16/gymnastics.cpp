/*
ID:swiftui
LANG:C++
TASK:gymnastics
*/
#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[11][21],b[11][21];
int main(){
  freopen("gymnastics.in","r",stdin);
  freopen("gymnastics.out","w",stdout);
  scanf("%d%d",&k,&n);
  for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
      scanf("%d",&a[i][j]);
      b[i][a[i][j]]=j;
    }
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    if(i==j)continue;
    bool flag=1;
    for(int ii=1;ii<=k;ii++){
      if(b[ii][i]<b[ii][j]){
        flag=0;
        break;
      }
    }
    ans+=flag;
  }
  printf("%d\n",ans);
  return 0;
}
