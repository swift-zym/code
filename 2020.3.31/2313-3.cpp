#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000001],b[2000001],c[2000001],n,dp1[2000001],dp2[2000001],s1[2000001],s2[2000001];
struct node{
  int id,v;
}q[2000001];
//FFT
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld",&a[i],&b[i]);
    a[i+n]=a[i];
    b[i+n]=b[i];
    c[i]=c[i+n]=b[i-1];
  }
  c[1]=c[n+1]=b[n];
  for(int i=1;i<=n*2;i++)s1[i]=s1[i-1]+a[i]-b[i];
  for(int i=n*2;i>=1;i--)s2[i]=s2[i+1]+a[i]-c[i];
  int l=1,r=1;
  q[r]={0,0};
  for(int i=1;i<=n*2;i++){
    while(l<=r&&q[l].id+n+1<=i){
      dp1[q[l++].id+1]=0;
    }
    while(l<=r&&q[r].v>s1[i]){
      dp1[q[r--].id+1]=1;
    }
    q[++r]={i,s1[i]};
  }
  l=r=1;
  q[r]={n*2+1,0};
  for(int i=n*2;i>=1;i--){
    while(l<=r&&q[l].id-n-1>=i){
      dp2[q[l++].id-1]=0;
    }
    while(l<=r&&q[r].v>s2[i]){
      dp2[q[r--].id-1]=1;
    }
    q[++r]={i,s2[i]};
  }
  for(int i=1;i<=n;i++){
    if(dp1[i]&&dp2[i+n]){
      puts("NIE");
    }
    else{
      puts("TAK");
    }
  }
  return 0;
}
