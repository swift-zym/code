#include<bits/stdc++.h>
using namespace std;
int n,a[1001];
int l[1001][1001],r[1001][1001];
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)l[i][i]=r[i][i]=a[i];
    for(int le=2;le<=n;le++)
    for(int i=1;i<=n-le+1;i++){
      int j=i+le-1,tmp=a[j],ll=l[i][j-1],rr=r[i][j-1];
      if(tmp==rr)l[i][j]=0;
      else if((tmp>ll&&tmp>rr)||(tmp<ll&&tmp<rr))l[i][j]=tmp;
      else if(rr<tmp&&ll>tmp)l[i][j]=tmp-1;
      else l[i][j]=tmp+1;
      tmp=a[i];ll=l[i+1][j];rr=r[i+1][j];
      if(tmp==ll)r[i][j]=0;
      else if((tmp>ll&&tmp>rr)||(tmp<ll&&tmp<rr))r[i][j]=tmp;
      else if(rr<tmp&&ll>tmp)r[i][j]=tmp+1;
      else r[i][j]=tmp-1;
    }
    if(a[1]==l[2][n]){
      puts("0");
    }
    else{
      puts("1");
    }
  }
  return 0;
}
