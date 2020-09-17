#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
int np[1000001];
void pre(){
  for(int i=2;i<=1000000;i++){
    if(!np[i])prime.push_back(i);
    for(int j=0;j<prime.size()&&prime[j]*i<=1000000;j++){
      np[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
int main(){
  pre();
  int n;
  while(scanf("%d",&n)!=EOF){
    if(!n)break;
    for(int i=1;i<prime.size();i++){
      if(!np[n-prime[i]]){
        printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
        break;
      }
    }
  }
}
