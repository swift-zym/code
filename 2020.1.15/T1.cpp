#include<bits/stdc++.h>
using namespace std;
int a[400001],b[400001],c[800001],cnt[4];
int ans,x,y,n;
int tmp;
bool flag=1;
namespace subtask_baoli{
  int c1[400001],c2[400001],v[400001],maxn;
  void dfs(int deep,int cx,int cy,int cans){
    if(deep==n+1){
      if(cx<0||cy<0)return;
      maxn=max(maxn,cans);
      return;
    }
    dfs(deep+1,cx,cy,cans);
    dfs(deep+1,cx+c1[deep],cy+c2[deep],cans+v[deep]);
  }
  void solve(){
    for(int i=1;i<=n;i++){
      char s[101];
      scanf("%s",s);
      scanf("%d",&v[i]);
      c1[i]=(s[0]=='1')?1:-1;
      c2[i]=(s[1]=='1')?1:-1;
    }
    dfs(1,0,0,0);
    printf("%d\n",maxn);
  }
}
int main(){
  scanf("%d",&n);
  /*if(n<=10){
    subtask_baoli::solve();
    return 0;
  }*/
  for(int i=1;i<=n;i++){
    char s[101];
    int v;
    scanf("%s",s);
    scanf("%d",&v);
    if(i==1)tmp=v;
    else if(v!=tmp)flag=0;
    int va=(s[0]=='1'),vb=(s[1]=='1');
    if(va&&vb){
      ans+=v;
      x++;
      y++;
      continue;
    }
    else if(va){
      a[++cnt[1]]=v;
    }
    else if(vb){
      b[++cnt[2]]=v;
    }
    else{
      c[++cnt[3]]=v;
    }
  }
  if(cnt[1]>=2)
  sort(a+1,a+cnt[1]+1);
  if(cnt[2]>=2)
  sort(b+1,b+cnt[2]+1);
  if(cnt[3]>=2)
  sort(c+1,c+cnt[3]+1);
  if(cnt[1]==0&&cnt[2]==0){
    for(int i=cnt[3];i>=1;i--){
      if(!x)break;
      ans+=c[i];
      x--;
    }
    printf("%d\n",ans);
  }
  else if(flag){
    int mi=min(cnt[1],cnt[2]);
    for(int i=mi;i>=1;i--){
      ans+=a[cnt[1]--];
      ans+=b[cnt[2]--];
    }
    for(int i=cnt[1];i>=1;i--){
      if(!y)break;
      ans+=a[i];
      x++;
      y--;
    }
    for(int i=cnt[2];i>=1;i--){
      if(!x)break;
      ans+=b[i];
      x--;
      y++;
    }
    for(int i=cnt[3];i>=1;i--){
      if((!x)||(!y))break;
      ans+=c[i];
      x--;y--;
    }
    printf("%d\n",ans);
  }
  else{
    int mi=min(cnt[1],cnt[2]);
    for(int i=mi;i>=1;i--){
      ans+=a[cnt[1]--];
      ans+=b[cnt[2]--];
    }
    if(cnt[1]==0){
      for(int i=1;i<=cnt[2];i++){
        c[++cnt[3]]=b[i];
      }
      sort(c+1,c+cnt[3]+1);
      for(int i=cnt[3];i>=1;i--){
          if(!x)break;
          ans+=c[i];
          x--;
      }
      printf("%d\n",ans);
    }
    else{
      for(int i=1;i<=cnt[1];i++){
        c[++cnt[3]]=a[i];
      }
      sort(c+1,c+cnt[3]+1);
      for(int i=cnt[3];i>=1;i--){
          if(!y)break;
          ans+=c[i];
          y--;
      }
      printf("%d\n",ans);
    }

  }
  return 0;
}
