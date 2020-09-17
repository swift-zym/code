#include<bits/stdc++.h>
using namespace std;
int n,k,m,op;
int a1[100001],b1[100001],a2[100001],b2[100001],a[100001],b[100001],c[100001],la;
int main(){
  scanf("%d%d%d%d",&n,&k,&m,&op);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&a1[i],&b1[i]);
  }
  for(int i=1;i<=k;i++){
    scanf("%d%d%d",&a[i],&b[i],&c[i]);
  }
  for(int i=1;i<=m;i++){
    scanf("%d%d",&a2[i],&b2[i]);
    if(op)a2[i]^=la,b2[i]^=la;
    la=0;
    for(int j=1;j<=n;j++){
      bool flag=1;
      for(int ii=1;ii<=k;ii++){
        if(b1[j]>c[ii]){
          double tmp=double(a1[j])+double(a2[i]-a1[j])/double(b1[j]-b2[i])*double(b1[j]-c[ii]);
          if(!(a[ii]-tmp>1e-6||tmp-b[ii]>1e-6)){
          flag=0;
          break;
          }
        }
        if(!flag)break;
      }
      if(flag)la++;
    }
    printf("%d\n",la);
  }
  return 0;
}
