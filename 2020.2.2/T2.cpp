#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int last,head[100001],nxt[1000001],to[1000001],cnt,vis[100001],q[100001],s,t;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void del(int a,int b){
  for(int i=head[a],pre=0;i;pre=i,i=nxt[i]){
    if(to[i]==b){
      if(!pre){
        head[a]=nxt[head[a]];
      }
      else{
        nxt[pre]=nxt[i];
      }
    }
  }
}
inline bool ask(int x,int y){
  t=s=0;
  q[t++]=x;
  vis[x]=1;
  memset(vis,0,sizeof(vis));
  bool flag=0;
  while(s<t){
    int now=q[s++];
    if(now==y){
      flag=1;
      break;
    }
    for(int i=head[now];i;i=nxt[i]){
      int tmp=to[i];
      if(!vis[tmp]){
        vis[tmp]=1;
        if(tmp==y){
          flag=1;
          break;
        }
        q[t++]=tmp;
      }
    }
    if(flag)break;
  }
  return flag;
}
int tmp[100001];
void dfs(int now){
  tmp[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(!tmp[to[i]])dfs(to[i]);
  }
}
int n,Q,ans,lastans;
int main(){
  scanf("%d%d",&n,&Q);
  for(int i=1;i<=n;i++){
    int k;
    scanf("%d",&k);
    for(int j=1;j<=k;j++){
      int a;
      scanf("%d",&a);
      add(i,a);
      add(a,i);
    }
  }
  for(int i=1;i<=n;i++){
    if(!tmp[i]){
      dfs(i);
      ans++;
    }
  }
  for(int i=1;i<=Q;i++){
    char c=getchar();
    while(c!='-'&&c!='?')c=getchar();
    int x,y;
    scanf("%d%d",&x,&y);
    x^=lastans;
    y^=lastans;
    if(c=='-'){
      del(x,y);
      del(y,x);
      if(!ask(x,y)){
        ans++;
      }
      lastans=ans;
      printf("%d\n",ans);
    }
    else{
      lastans=ask(x,y);
      printf("%d\n",lastans);
    }
  }
  return 0;
}
