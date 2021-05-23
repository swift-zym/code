#include"chameleon.h"
#include<bits/stdc++.h>
using namespace std;
int vis[1001];
int a[1001];
void Solve(int N) {
  for(int i=1;i<=2*N;i++){
    if(!vis[i]){
      int l=1,r=2*N;
      vis[i]=1;
      while(l!=r){
        int mid=(l+r)/2;
        vector<int>tmp;
        for(int j=l;j<=mid;j++){
          if(j==i)continue;
          tmp.push_back(j);
        }
        int v1=Query(tmp);
        tmp.push_back(i);
        int v2=Query(tmp);
        if(v2==v1+1){
          l=mid+1;
        }
        else{
          r=mid;
        }
      }
      vis[l]=1;
      Answer(i,l);
    }
  }
}
