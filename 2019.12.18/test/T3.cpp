//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001];
namespace subtask0{
  void solve(){
    int mx=-1,num;
    if(k==1){
      for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++){
        if((a[i]&a[j])>mx){
          mx=(a[i]&a[j]);
          num=1;
        }
        else if((a[i]&a[j])==mx){
          num++;
        }
      }
    }
    else if(k==2){
      for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++){
        if((a[i]^a[j])>mx){
          mx=(a[i]^a[j]);
          num=1;
        }
        else if((a[i]^a[j])==mx){
          num++;
        }
      }
    }
    else{
      for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++){
        if((a[i]|a[j])>mx){
          mx=(a[i]|a[j]);
          num=1;
        }
        else if((a[i]|a[j])==mx){
          num++;
        }
      }
    }
    printf("%d %d\n",mx,num);
  }
}
namespace subtask1{
    int vis[100001];
    int b[100001][25];
    int ok[100001];
    void solve(){
      for(int i=1;i<=n;i++){
        int cnt=25;
        int tmp=a[i];
        while(tmp){
          b[i][--cnt]=(tmp%2);
          tmp/=2;
        }
        vis[i]=1;
      }
      for(int i=1;i<=24;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
          ok[j]=0;
          if(vis[j]&&b[j][i]==1){
            sum++;
            ok[j]=1;
          }
        }
        if(sum>1){
          for(int j=1;j<=n;j++){
            vis[j]=ok[j];
          }
        }
      }
      vector<int>ans;
      for(int i=1;i<=n;i++){
        if(vis[i])ans.push_back(a[i]);
      }
      int siz=ans.size();
      printf("%d %d\n",ans[0]&ans[1],siz*(siz-1)/2);
    }
}
namespace subtask2{
    void solve(){}
}
namespace subtask3{
    void solve(){}
}
int main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  if(n<=1000){
    subtask0::solve();
    return 0;
  }
  if(k==1){
    subtask1::solve();
  }
  else if(k==2){
    subtask2::solve();
  }
  else{
    subtask3::solve();
  }
  return 0;
}
