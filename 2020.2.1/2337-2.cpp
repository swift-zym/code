#include<iostream>
using namespace std;
int T,n,a[10001],b[10001],c[10001];
double solve(double x){
  double mx=x*x*a[1]+x*b[1]+c[1];
  for(int i=2;i<=n;i++){
    mx=max(mx,x*x*a[i]+x*b[i]+c[i]);
  }
  return mx;
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    double l=0,r=1000;
    while(r-l>1e-8){
      //cout<<l<<" "<<r<<endl;
      double mid=(l+r)/2,mmid=(mid+r)/2;
      if(solve(mid)<solve(mmid)){
        r=mmid;
      }
      else{
        l=mid;
      }
    }
    printf("%0.4lf\n",solve(l));
  }
}
