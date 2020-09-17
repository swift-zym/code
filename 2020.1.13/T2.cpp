#include<bits/stdc++.h>
using namespace std;
int n,m,Q,head[300001],to[600001],nxt[600001],cnt,du[300001];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
namespace subtask1{
  int tag[3001];
  void solve(){
    for(int i=1;i<=Q;i++){
      int a,b,c;
      scanf("%d",&a);
      if(a==0){
        scanf("%d",&b);
        int ans=tag[b];
        for(int j=head[b];j;j=nxt[j]){
          ans+=tag[to[j]];
        }
        printf("%d\n",ans);
      }
      else{
        scanf("%d%d",&b,&c);
        tag[b]+=c;
      }
    }
  }
}
namespace subtask2{
  int mx,id,cnt=0,add[300001],bel[300001],cen[300001],tag[300001];
  void dfs(int now){
    bel[now]=cnt;
    if(du[now]>mx){
      mx=du[now];
      id=now;
    }
    for(int i=head[now];i;i=nxt[i]){
      if(!bel[to[i]]){
        dfs(to[i]);
      }
    }
  }
  void solve(){
    for(int i=1;i<=n;i++){
      if(!bel[i]){
        ++cnt;
        mx=-1;
        dfs(i);
        cen[id]=1;
      }
    }
    for(int i=1;i<=Q;i++){
      int a,b,c;
      scanf("%d",&a);
      if(a==0){
        scanf("%d",&b);
        printf("%d\n",tag[b]+add[bel[b]]);
      }
      else{
        scanf("%d%d",&b,&c);
        if(cen[b]){
          add[bel[b]]+=c;
        }
        else{
          tag[b]+=c;
          for(int j=head[b];j;j=nxt[j]){
            tag[to[j]]+=c;
          }
        }
      }
    }
  }
}
namespace subtask3{
  int tag[300001],add1[300001],add1_v=0;
  void solve(){
    for(int i=head[1];i;i=nxt[i]){
      add1[to[i]]=1;
    }
    for(int i=1;i<=Q;i++){
      int a,b,c;
      scanf("%d",&a);
      if(a==0){
        scanf("%d",&b);
        if(add1[b])
        printf("%d\n",tag[b]+add1_v);
        else
        printf("%d\n",tag[b]);
      }
      else{
        scanf("%d%d",&b,&c);
        if(b==1){
          tag[1]+=c;
          add1_v+=c;
        }
        else{
          tag[b]+=c;
          for(int j=head[b];j;j=nxt[j]){
            tag[to[j]]+=c;
          }
        }
      }
    }
  }
}
namespace subtask_fin{
  vector<int>v[300001];
  bool cmp(int a,int b){
    return du[a]>du[b];
  }
  int k,tag[300001],add[300001];
  void solve(){
  scanf("%d%d%d",&n,&m,&Q);
  k=sqrt(m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
    du[a]++;
    du[b]++;
  }
  for(int i=1;i<=n;i++){
    if(v[i].size()>=2){
      sort(v[i].begin(),v[i].end(),cmp);
    }
  }
  for(int i=1;i<=Q;i++){
    int a,b,c;
    scanf("%d",&a);
    if(a==0){
      scanf("%d",&b);
      if(du[b]<=k){
        int ans=tag[b]+add[b];
        for(int i=0;i<v[b].size();i++){
          ans+=tag[v[b][i]];
        }
        printf("%d\n",ans);
      }
      else{
        printf("%d\n",tag[b]+add[b]);
      }
    }
    else{
      scanf("%d%d",&b,&c);
      tag[b]+=c;
      for(int i=0;i<v[b].size();i++){
        if(du[v[b][i]]<=k)break;
        add[v[b][i]]+=c;
      }
    }
  }
  }
}
int main(){
  subtask_fin::solve();
  return 0;
  scanf("%d%d%d",&n,&m,&Q);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
    add(b,a);
    du[a]++;
    du[b]++;
  }
  /*test*/
  int mx=-1;
  for(int i=2;i<=n;i++)mx=max(mx,du[i]);
  if(n<=3000&&m<=3000&&Q<=3000){
    subtask1::solve();
  }
  else if(mx<=10){
    subtask3::solve();
  }
  else{
    subtask2::solve();
  }
  return 0;
}
