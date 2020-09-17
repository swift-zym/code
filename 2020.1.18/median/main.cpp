#include<bits/stdc++.h>
using namespace std;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int n,m,a[500001],b[500001];
vector<int>v;
int main(){
  freopen("example_median3.in","r",stdin);
  freopen("example_median3.out","w",stdout);
  n=ri();
  m=ri();
  for(int i=1;i<=n;i++)a[i]=ri();
  for(int i=1;i<=n;i++)b[i]=ri();
  for(int i=1;i<=m;i++){
    int opt=ri();
    if(opt==1){
      int x=ri(),y=ri(),z=ri();
      if(!x){
        a[y]=z;
      }
      else{
        b[y]=z;
      }
    }
    else{
        int l1=ri(),r1=ri(),l2=ri(),r2=ri();
        v.clear();
        for(int j=l1;j<=r1;j++)v.push_back(a[j]);
        for(int j=l2;j<=r2;j++)v.push_back(b[j]);
        sort(v.begin(),v.end());
        printf("%d\n",v[(v.size()+1)/2-1]);
    }
  }
  return 0;
}
