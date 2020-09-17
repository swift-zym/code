#include<iostream>
using namespace std;
int n,c,x[100001];
bool check(int mid){
  int last=x[1],now=1;
  for(int i=2;i<=c;i++){
    if(now==n+1)return 0;
    while(x[now]-last<mid){
      if(now==n+1)return 0;
      now++;
    }
    last=x[now];
    now++;
  }
  return 1;
}
int main(){
  scanf("%d%d",&n,&c);
  for(int i=1;i<=n;i++)scanf("%d",&x[i]);
  sort(x+1,x+n+1);
  int l=0,r=x[n],ans;
  while(l<=r){
    int mid=(l+r)/2;
    if(check(mid)){
      ans=mid;
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  printf("%d\n",ans);
  return 0;
}
