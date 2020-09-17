#include<bits/stdc++.h>
using namespace std;
int x[1001],y[1001],n,flag;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    char s[2001];
    scanf("%s",s+1);
    for(int j=1;j<=n;j++){
      if(s[j]=='#'){
        x[i]++;
        y[j]++;
        flag=1;
      }
    }
  }
  if(!flag){
    puts("-1");
    return 0;
  }
  int mi=10000;
  for(int i=1;i<=n;i++){
    mi=min(mi,n-x[i]+(y[i]==0));
  }
  for(int i=1;i<=n;i++){
    if(y[i]!=n)mi++;
  }
  printf("%d\n",mi);
  return 0;
}
