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
  scanf("%d",&n);
  printf("%d\n",(n<3)?1:2);
  for(int i=1;i<=n;i++){
    if(i!=1)putchar(' ');
    printf("%d",int(np[i+1])+1);
  }
  putchar(10);
  return 0;
}
