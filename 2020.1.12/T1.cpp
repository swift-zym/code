#include<bits/stdc++.h>
#define int long long
using namespace std;
int y,n,m;
vector<int>v;
void pre(){
  while(y){
    v.push_back(y%2);
    y/=2;
  }
}
signed main(){
  freopen("1.in.txt","r",stdin);
  freopen("1.out.txt","w",stdout);
  scanf("%lld",&y);
  pre();
  n=v.size()+2;
  for(int i=1;i<n-1;i++)
     for(int j=i+1;j<n;j++){
        m++;
     }
  for(int i=0;i<n-2;i++){
     if(v[i]){
	m++;
     }
  }
  printf("%lld %lld\n",n,m);
  for(int i=1;i<n-1;i++)
    for(int j=i+1;j<n;j++){
	printf("%lld %lld\n",i,j);
    }
  for(int i=0;i<n-2;i++){
     if(v[i]){
       printf("%lld %lld\n",i+2,n);
     }
  }
  return 0;
}
