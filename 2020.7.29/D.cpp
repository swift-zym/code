#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int t,n,k;
signed main(){
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&n,&k);
    int l1,r1,l2,r2;
    scanf("%lld%lld",&l1,&r1);
    scanf("%lld%lld",&l2,&r2);
    if(l2<l1){
      swap(l1,l2);
      swap(r1,r2);
    }

    if(r1>=l2){
      k-=n*abs(r1-l2);
      if(k<=0){
        puts("0");
      }
      else{
      int v=abs(l1-l2)+abs(r1-r2);
      if(k<=n*v){
        printf("%lld\n",k);
      }
      else{
        printf("%lld\n",n*v+(k-n*v)*2ll);
      }
      }
    }
    else{
      int c=l2-r1;
      int v=r2-l1;
      int ans=1e18,now=0;
      for(int i=1;i<=n;i++){
        if(i!=1)
        ans=min(ans,now+2ll*k);
        now+=c;
        if(k<=v){
          now+=k;
          k-=k;
          ans=min(ans,now);
          break;
        }
        else{
          now+=v;
          k-=v;
        }
      }
      if(k!=0){
        now+=2*k;
        ans=min(ans,now);
      }
      printf("%lld\n",ans);
    }
  }
  return 0;
}
