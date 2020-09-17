#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
struct node{
  int a,b,c;
  bool operator <(const node &t)const{
    return a>t.a;
  }
}a[1001];
vector<int>X,Y;
int n,x,mx,dp1[100001],dp2[100001],ans,tmp[100001];
bool cmp(int a,int b){
  return a>b;
}
signed main(){
  scanf("%lld%lld",&n,&x);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
    mx=max(mx,a[i].a);
    int bas=1;
    while(a[i].b>=bas){
      a[i].b-=bas;
      X.push_back(bas*a[i].a%MOD);
      bas*=2;
    }
    if(a[i].b){
      Y.push_back(a[i].b*a[i].a%MOD);
    }
    bas=1;
    while(a[i].c>=bas){
      a[i].c-=bas;
      X.push_back(bas*a[i].a%MOD);
      printf("\n-push_back(%d)-\n",bas);
      bas*=2;
    }
    if(a[i].c){
      X.push_back(a[i].c*a[i].a%MOD);
    }
  }
  sort(a+1,a+n+1);
  sort(X.begin(),X.end(),cmp);
  sort(Y.begin(),Y.end(),cmp);
  dp1[0]=1;
  cout<<X.size()<<endl;
  for(int i=0;i<X.size();i++){
    for(int j=x+mx-1;j>=0;j--){
      if(j+X[i]>=x+mx)continue;
      dp1[j+X[i]]+=dp1[j];
    }
  }
  for(int i=0;i<=x+mx-1;i++){
    printf("dp1[%d]=%d\n",i,dp1[i]);
  }
  dp2[0]=1;
  for(int i=1;i<=n;i++){
    memset(tmp,0,sizeof(tmp));
    for(int j=x+mx-1;j>=0;j--){
      for(int k=1;k <= a[i].b;k++){
        if(k*a[i].a+j>=x+mx)break;
        dp2[j+k*a[i].a]+=dp2[j];
        tmp[j+k*a[i].a]+=dp2[j];
        tmp[j+k*a[i].a]%=MOD;
        dp2[j+k*a[i].a]%=MOD;
      }
      /*for(int j=0;j<x+mx;j++){
        printf("dp2[%d]=%d\n",j,dp2[j]);
      }
      puts("----------------------");*/
    }
    for(int j=0;j<x+mx&&j<x+a[i].a;j++){
      if(j-x<0)continue;
      ans+=(dp1[j-x]*tmp[j])%MOD;
      ans%=MOD;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
