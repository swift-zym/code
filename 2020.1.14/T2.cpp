#include<bits/stdc++.h>
using namespace std;
int n,m,Q;
int head[300001],nxt[600001],to[600001],len[600001],cnt,vis[300001],mid,s,t,flag;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
void dfs(int now){
  if(flag)return;
  if(now==t){
    flag=1;
    return;
  }
  vis[now]=1;
  for(int i=head[now];i;i=nxt[i]){
    if(len[i]-mid<=0&&!vis[to[i]]){
      dfs(to[i]);
    }
    if(flag)return;
  }
}
bool check(int a,int b){
  memset(vis,0,sizeof(vis));
  s=a;
  t=b;
  flag=0;
  dfs(s);
  return flag;
}
int main(){
  scanf("%d%d%d",&n,&m,&Q);
  for(int i=1;i<=m;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    add(a,b,l);
    add(b,a,l);
  }
  for(int i=1;i<=Q;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    int l=1,r=1000001;
    while(l!=r){
      mid=(l+r)/2;
      if(check(a,b)){
        r=mid;
      }
      else{
        l=mid+1;
      }
    }
    if(l==1000001){
      puts("-1");
    }
    else
    printf("%d\n",l);
  }
  return 0;
}
