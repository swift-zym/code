#include<bits/stdc++.h>
using namespace std;
int du[100001];
int n,m,f[100001],num1[100001],num2[100001];
int gf(int now){
  if(f[now]==now)return now;
  int fa=gf(f[now]);
  return f[now]=fa;
}
int main(){
  while(scanf("%d%d",&n,&m)!=EOF){
    memset(du,0,sizeof(du));
    memset(num1,0,sizeof(du));
    memset(num2,0,sizeof(du));
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      du[a]++;du[b]++;
      f[gf(a)]=gf(b);
    }
    for(int i=1;i<=n;i++){
      if(du[i]%2)num1[gf(i)]++;
      num2[gf(i)]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      if(num2[i]<=1)continue;
      if(num1[i]==0)++ans;
      else ans+=num1[i]/2;
    }
    printf("%d\n",ans);
  }
}
