#include<iostream>
using namespace std;
int n,m,a[1000001];
bool check(int x){
  int num=1,sum=0;
  for(int i=1;i<=n;i++){
    if(a[i]>x)return 0;
    else if(sum+a[i]<=x){
      sum+=a[i];
    }
    else{
      if(num==m)return 0;
      num++;
      sum=a[i];
    }
  }
  return 1;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  int l=0,r=1000000000,ans;
  while(l<=r){
    int mid=(l+r)/2;
    if(check(mid)){
      ans=mid;
      r=mid-1;
    }
    else{
      l=mid+1;
    }
  }
  printf("%d\n",ans);
  return 0;
}
