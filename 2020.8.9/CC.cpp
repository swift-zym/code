#include<iostream>
#include<vector>
using namespace std;
int a[11],du[11];
vector<int>v[11];
int vis[11];
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  int ans=0;
  do{
    memset(vis,0,sizeof(vis));
    int num=0;
    for(int i=1;i<=n;i++){
      for(int j=i-1;j>=1;j--){
        if(a[j]>a[i]){
          num++;
          du[j]++;du[i]++;
          v[i].push_back(j);
          v[j].push_back(i);
          break;
        }
      }
      for(int j=i+1;j<=n;j++){
        if(a[j]>a[i]){
          num++;
          du[j]++;du[i]++;
          v[i].push_back(j);
          v[j].push_back(i);
          break;
        }
      }
    }
    if(num>=n){
      ans++;
    }
    else{
      /*bool flag=0;
      int del=0;
      do{
        for(int i=1;i<=n;i++){
          if(vis[i]==0&&du[i]<=1){
            del++;
            flag=1;
            vis[i]=1;
            for(int j=0;j<v[i].size();j++){
              du[v[i][j]]--;
            }
          }
        }
      }while(flag);
      ans+=(del!=n);*/
    }
  }while(next_permutation(a+1,a+n+1));
  cout<<ans<<endl;
  return 0;
}
/*
0,0,2,16,104,688
*/
