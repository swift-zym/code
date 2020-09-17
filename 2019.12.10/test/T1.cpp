#include<iostream>
using namespace std;
int n,a[100001];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
  printf("%0.6lf\n",double(n+1)/2.0);
  return 0;
}
