#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int dp[2001],v[2001],w[2001],a[2001];
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
      scanf("%d%d",&v[i],&w[i]);
    }
    for(int i=0;i<=2000;i++)dp[i]=1e8;
    for(int i=1;i<=a[1];i++)dp[i]=0;
    for(int i=a[1]+1;i<=a[n];i++){
      for(int j=1;j<=m;j++){
        if(i-w[j]>0){
          dp[i]=min(dp[i],dp[i-w[j]]+v[j]);
        }
      }
    }
    int sum=0;
    for(int i=1;i<=a[n];i++){
      sum+=dp[i];
    }
    printf("%d\n",sum);
  }
  return 0;
}
/*
1
2 2
1 3
1 1
1 2
*/
