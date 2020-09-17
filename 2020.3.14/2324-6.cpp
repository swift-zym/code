#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000
int n,m,pd1[MAXN],pd2[MAXN],f[MAXN],du[MAXN],tmp[MAXN],cnt,ans,v;
int gf(int now){
  if(f[now]==now)return now;
  int fa=gf(f[now]);
  return f[now]=fa;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<MAXN;i++)f[i]=i;
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    if(!a)a=++n;
    if(!b)b=++n;
    du[a]++;
    du[b]++;
    int fa=gf(a),fb=gf(b);
    f[fa]=fb;
  }
  for(int i=1;i<=n;i++){
   if(!du[i])continue;
   int fa=gf(i);
   if(i==fa)tmp[++cnt]=i;
   if(du[i]%2==1)v++,pd1[fa]=1;
   if(du[i]>2)pd2[fa]=1,ans++;
  }
  if(cnt!=1){
    for(int i=1;i<=cnt;i++){
      if(!pd1[tmp[i]]){
        v+=2;
        if(pd2[tmp[i]]==0){
          ans++;
        }
      }
    }
  }
  ans+=v/2;
  printf("%d\n",ans);
  return 0;
}
