#include<bits/stdc++.h>
#define eps 1e-6
using namespace std;
struct node{
  double x,y;
  bool operator <(const node &t)const{
    return t.y-y>eps;
  }
}a[1100000];
double f;
char s[1100000];
int n;
int main(){
  scanf("%lf",&f);
  scanf("%s",s+1);
  n=strlen(s+1);
  int sum=0;
  for(int i=1;i<=n;i++){
    sum+=(s[i]-'0');
    a[i].x=i;
    a[i].y=double(f*i)-double(sum);
  }
  sort(a+1,a+n+1);
  double mi=sum/n;
  int id=0;
  for(int i=1;i<n;i++){
    int j=i+1;
    double nmi=double(abs((a[i].y-a[j].y))/double(a[i].x-a[j].x));
    int nid=min(a[i].x,a[j].x);
    if(mi-nmi>eps||(abs(mi-nmi)<eps&&nid<id)){
      mi=nmi;
      id=nid;
    }
  }
  printf("%d\n",id);
  return 0;
}
