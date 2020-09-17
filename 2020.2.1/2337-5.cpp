#include<iostream>
using namespace std;
int T;
double H,h,d;
double check(double x){
  if(x==0)return 0;
  if(x/(H-h)*H>d){
    double l1=d-x;
    double l2=x/(H-h)*H-x;
    double l3=h/l2*(l2-l1);
    return l1+l3;
  }
  else{
    return x/(H-h)*H-x;
  }
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%lf %lf %lf",&H,&h,&d);
    double l=0,r=d;
    while(r-l>1e-8){
      double mid=(l+r)/2,mmid=(mid+r)/2;
      if(check(mid)<check(mmid)){
        l=mid;
      }
      else{
        r=mmid;
      }
    }
    printf("%0.3lf\n",check(l));
  }
  return 0;
}
