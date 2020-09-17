#include<bits/stdc++.h>
using namespace std;
char s[1100];
int dp[1100][1100],len;
bool cmp(char a,char b){
  return (a=='('&&b==')')||(a=='['&&b==']');
}
int main(){
  scanf("%s",s);
  len=strlen(s);
  for(int l=1;l<len;l++){
    for(int i=0;i+l<len;i++){
      if(cmp(s[i],s[i+l]))
        dp[i][i+l]=dp[i+1][i+l-1]+2;
      for(int k=i;k<i+l;k++){
        dp[i][i+l]=max(dp[i][i+l],dp[i][k]+dp[k+1][i+l]);
      }
    }
  }
  printf("%d\n",len-dp[0][len-1]);
  return 0;
}
