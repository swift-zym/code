#include<bits/stdc++.h>
using namespace std;
int dp[11000][1100];
int pre[1100];
int n,m,k,cnt;
void judge(int a){
  int nxt=-1;
  int bf=a;
  for(int i=1;i<=m;i++){
    int tmp=a%3;
    a/=3;
    if(tmp==nxt)return;
    nxt=tmp;
  }
  pre[++cnt]=bf;
}
bool check(int a,int b){
  for(int i=1;i<=m;i++){
    int tmp1=a%3,tmp2=b%3;
    if(tmp1==tmp2)return 0;
    a/=3;
    b/=3;
  }
  return 1;
}
int pos;
int main(){
  scanf("%d%d",&n,&m);
  scanf("%d",&k);
  int bas=0;
  for(int i=0;i<pow(3,m);i++){
    judge(i);
  }
  for(int i=1;i<=m;i++){
    int tmp;
    scanf("%d",&tmp);
    bas*=3;
    bas+=tmp-1;
  }
  for(int i=1;i<=cnt;i++){
    if(bas==pre[i])pos=i;
  }
  if(!pos){
    puts("0");
    return 0;
  }
  for(int i=1;i<=n;i++){
    if(i==k){
      if(i==1)dp[i][pos]=1;
      for(int j=1;j<=cnt;j++){
        if(check(bas,pre[j])){
          dp[i][pos]+=dp[i-1][j];
          dp[i][pos]%=1000000;
        }
      }
    }
    else{
      for(int j=1;j<=cnt;j++){
        if(i==1)dp[i][j]=1;
        for(int k=1;k<=cnt;k++){
          if(check(pre[j],pre[k])){
            dp[i][j]+=dp[i-1][k];
            dp[i][j]%=1000000;
          }
        }
      }
    }
  }
  int sum=0;
  for(int i=1;i<=cnt;i++){
    sum+=dp[n][i];
    sum%=1000000;
  }
  printf("%d\n",sum);
  return 0;
}
