#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,z,a[100001],sum[100001];
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d%d%d",&n,&k,&z);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=-1;
    for(int i=2;i<=n;i++){
      if(i>k+1)break;
      int v=sum[i],kk=k;
      kk-=(i-1);
      int num=min(kk/2,z);
      v+=num*(a[i]+a[i-1]);
      kk-=num*2;
      if(kk!=1||num==z)
      v+=sum[i+kk]-sum[i];
      else
      v+=max(a[i-1],a[i+1]);
      ans=max(ans,v);
    }
    printf("%d\n",ans);
  }
  return 0;
}
