#include<bits/stdc++.h>
using namespace std;
int n,q,a[100001];
int main(){
  freopen("T2.in","r",stdin);
  freopen("T2.ans","w",stdout);
  scanf("%d",&n);
  scanf("%d",&q);
  for(int i=1;i<=q;i++){
    int opt;
    scanf("%d",&opt);
    if(opt==1){
      int l,r;
      scanf("%d%d",&l,&r);
      for(int j=l;j<=r;j++){
        a[j]=1;
      }
    }
    else if(opt==2){
      int l,r;
      scanf("%d%d",&l,&r);
      for(int j=l;j<=r;j++){
        a[j]=0;
      }
    }
    else{
      int l,r,x;
      scanf("%d",&x);
      if(a[x]){
        puts("0");
        continue;
      }
      l=r=x;
      while(l>=2&&a[l-1]==0)l--;
      while(r<=(n-1)&&a[r+1]==0)r++;
      if(l==1||r==n){
        puts("INF");
      }
      else{
        printf("%d\n",r-l+1);
      }
    }
  }
  return 0;
}
