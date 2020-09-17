#include<iostream>
using namespace std;
int a[2000],b[2000];
int t,n,m;
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&m);
    int ans=1e8;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      if(a[i]==b[j]){
        ans=min(ans,a[i]);
      }
    }
    if(ans==1e8){
      puts("NO");
    }
    else{
      puts("YES");
      printf("%d %d\n",1,ans);
    }
  }
  return 0;
}
