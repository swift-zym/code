#include<iostream>
#include<cmath>
using namespace std;
int n,l,a[100001];
double sum[100001];
bool check(double x){
  for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]-x;
  double mi=0;
  for(int i=l;i<=n;i++){
    mi=min(mi,sum[i-l]);
    if(sum[i]-mi>=0)return 1;
  }
  return 0;
}
int main(){
  scanf("%d%d",&n,&l);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  double l=-1e8,r=1e8;
  while(r-l>1e-6){
    double mid=(l+r)/2;
    if(check(mid)){
      l=mid;
    }
    else{
      r=mid;
    }
  }
  printf("%d\n",int(r*1000));
  return 0;
}
