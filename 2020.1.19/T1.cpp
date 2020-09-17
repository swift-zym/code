#include<bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int a,int b){
  if(b==0)return 1;
  int tmp=qpow(a,b/2);
  return b%2?tmp*tmp*a:tmp*tmp;
}
int n,cnt;
int a[101],b[101];
signed main(){
  scanf("%lld",&n);
  int t=n;
  while(n){
    a[++cnt]=n%3;
    n/=3;
  }
  //1 1 1 2
  //27 9 3 1
  for(int i=1;i<=cnt;i++){
    if(a[i]==2){
      b[i]++;
      a[i]=0;
      a[i+1]++;
      cnt=max(cnt,i+1);
    }
    else if(a[i]==3){
      a[i]=0;
      a[i+1]++;
      cnt=max(cnt,i+1);
    }
  }
  vector<int>x,y;
  for(int i=1;i<=cnt;i++){
    if(a[i]){
      x.push_back(pow(3,i-1));
    }
    if(b[i]){
      y.push_back(pow(3,i-1));
    }
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int siz=x.size();
  for(int i=0;i<siz;i++){
    if(i)putchar(' ');
    printf("%lld",x[i]);
  }
  siz=y.size();
  putchar(10);
  printf("%lld ",t);
  for(int i=0;i<siz;i++){
    if(i!=0)putchar(' ');
    printf("%lld",y[i]);
  }
  putchar(10);
  return 0;
}
