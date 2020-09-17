#include<bits/stdc++.h>
using namespace std;
int dp[1024][1024][3],tmp[1024];
int solve(int x){
  int num=0;
  while(x){
    num++;
    x-=x&-x;
  }
  return num;
}
int n,m,a[101];
int main(){
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    int bas=0;
    for(int j=1;j<=m;j++){
      char c;
      cin>>c;
      bas*=2;
      bas+=(c=='H');
    }
    a[i]=bas;
  }

  for(int i=0;i<(1<<m);i++){
    tmp[i]=solve(i);
    //
  }
  for(int i=0;i<(1<<m);i++){
    if((i&a[1])||(i&(i>>1))||(i&(i>>2)))continue;
    dp[i][0][1]=tmp[i];
    //printf("dp[%d][%d][%d]=%d\n",i,0,1,tmp[i]);
  }
  for(int i=0;i<(1<<m);i++)
  for(int j=0;j<(1<<m);j++){
    if((i&j)||(i&a[2])||(j&a[1])||(i&(i>>1))||(i&(i>>2))||(j&(j>>1))||(j&(j>>2)))continue;
    dp[i][j][2]=tmp[i]+tmp[j];
    //printf("dp[%d][%d][%d]=%d\n",i,j,2,tmp[i]+tmp[j]);
  }
  for(int i=3;i<=n;i++){
    for(int j=0;j<(1<<m);j++){
      if((j&a[i])||(j&(j>>1))||(j&(j>>2)))continue;
      for(int k=0;k<(1<<m);k++){
          if((k&j)||(k&a[i-1])||(k&(k>>1))||(k&(k>>2)))continue;
          for(int ii=0;ii<(1<<m);ii++){
            if((ii&j)||(ii&k)||(ii&a[i-2])||(ii&(ii>>1))||(ii&(ii>>2)))continue;
            dp[j][k][i%3]=max(dp[j][k][i%3],dp[k][ii][(i-1)%3]+tmp[j]);
          }
          //printf("dp[%d][%d][%d]=%d\n",j,k,i%3,dp[j][k][i%3]);
      }
    }
  }
  int sum=0;
  for(int i=0;i<(1<<m);i++)
  for(int j=0;j<(1<<m);j++){
    sum=max(sum,dp[i][j][n%3]);
  }
  cout<<sum<<endl;
  return 0;
}
