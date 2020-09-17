#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100001],tmp[100001],ans=1000000000;
bool check(int x){
  int sum=0,use=1;
  for(int i=1;i<=n;i++){
    if(sum+tmp[i]>x){
      use++;
      if(use>k)return 0;
      sum=tmp[i];
      if(sum>x)return 0;
    }
    else{
      sum+=tmp[i];
    }
  }
  return 1;
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++)
    tmp[j]=(a[j]+i)%m;
    int l=1,r=1000000000;
    while(l!=r){
      int mid=(l+r)/2;
      if(check(mid)){
        r=mid;
      }
      else{
        l=mid+1;
      }
    }
    ans=min(ans,l);
  }
  printf("%d\n",ans);
  return 0;
}
