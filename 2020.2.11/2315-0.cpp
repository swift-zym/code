#include<bits/stdc++.h>
#define int long long
using namespace std;
int bas[100];
int c[100][100];
int x,y,k,b;
int C(int x,int y){
  if(x<0||y<0)return 0;
  return c[x][y];
}
int now;
vector<int>v;
int solve(int x){
  if(x<=0)return 0;
  v.clear();
  for(int i=now;i>=0;i--){
    if(x>=bas[i])x-=bas[i],v.push_back(i);
  }
  int ans=0;
  for(int i=0;i<v.size();i++){
    if(k-i>0)ans+=C(v[i],k-i);
  }
  if(v.size()>=k)ans++;
  return ans;
}
signed main(){
  scanf("%lld%lld%lld%lld",&x,&y,&k,&b);
  bas[0]=1;
  while(bas[now]<y)bas[now+1]=bas[now]*b,now++;
  for(int i=0;i<=now;i++){
    c[i][0]=1;
    for(int j=1;j<=i;j++){
      c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
  }
  printf("%lld\n",solve(y)-solve(x-1));
  return 0;
}
