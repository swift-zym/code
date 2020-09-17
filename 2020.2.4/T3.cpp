#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[100001],len[100001],num[100001],vis[100001],dep[100001],tmp[100001];
int a[100001],ans=1e12,cnt;
int n;
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)a[i]=i;
  for(int i=2;i<=n;i++){
    scanf("%lld%lld",&fa[i],&len[i]);
    vis[fa[i]]=1;
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      tmp[++cnt]=i;
      int now=i;
      while(now!=1){
        dep[cnt]++;
        now=fa[now];
      }
    }
  }
  do{
    memset(num,0,sizeof(num));
    bool flag=0;
    int mx=-1,now1=tmp[a[1]],now2;
    while(now1!=1){
      num[now1]++;
      now1=fa[now1];
    }
    for(int i=2;i<=cnt;i++){
      int sum=0;
      now1=tmp[a[i-1]],now2=tmp[a[i]];
      for(int j=1;j<=dep[a[i-1]]-dep[a[i]];j++){
        num[now1]++;
        if(num[now1]==3){
          flag=1;
          break;
        }
        sum+=len[now1];
        now1=fa[now1];
      }
      for(int j=1;j<=dep[a[i]]-dep[a[i-1]];j++){
        num[now2]++;
        if(num[now2]==3){
          flag=1;
          break;
        }
        sum+=len[now2];
        now2=fa[now2];
      }
      while(now1!=now2){
        num[now1]++;
        if(num[now1]==3){
          flag=1;
          break;
        }
        sum+=len[now1];
        num[now2]++;
        if(num[now2]==3){
          flag=1;
          break;
        }
        sum+=len[now2];
        now1=fa[now1];
        now2=fa[now2];
      }
      mx=max(mx,sum);
      if(flag)break;
    }
    now2=tmp[a[cnt]];
    while(now2!=1){
      num[now2]++;
      if(num[now2]==3){
      flag=1;
      break;
      }
      now2=fa[now2];
    }
    if(!flag)ans=min(ans,mx);
  }while(next_permutation(a+1,a+cnt+1));
  printf("%lld\n",ans);
  return 0;
}
