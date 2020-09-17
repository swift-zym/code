#include<iostream>
using namespace std;
int t;
int main(){
  scanf("%d",&t);
  while(t--){
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      char c=getchar();
      while(c!='R'&&c!='D'&&c!='C')c=getchar();
      if(c=='C')continue;
      if(i==1&&j==1){
        if(n==1){
          ans+=(c!='R');
        }
        if(m==1){
          ans+=(c!='D');
        }
        continue;
      }
      if(i==n&&j==m)continue;
      if(i==n){
        ans+=(c!='R');
      }
      if(j==m){
        ans+=(c!='D');
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
