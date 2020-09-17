#include<bits/stdc++.h>
using namespace std;
int n,dp[100001];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    dp[i]=max((i+1)/2,1);
  }
  int sum=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      if(i%j==0){
        sum+=dp[j];
        sum%=998244353;
      }
    }
  }
  printf("%d\n",sum);
  return 0;
}
  //if i-wo_qiu_de-ni_qiu_de==j:ni_qiu_de>=dp[j],wo_qiu_de>=ni_qiu_de
  //wo_qiu_de+ni_qiu_de==i-j,
  //ni_qiu_de==i-j-wo_qiu_de
  //i-j-wo_qiu_de>=dp[j]&&wo_qiu_de>=ni_qiu_de
  //i-j-wo_qiu_de<=wo_qiu_de<=i-j-dp[j]
  //wo_qiu_de>=(i-j)/2
