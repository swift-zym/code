#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,ml,md,num[1001],head[1001],nxt[20001],to[20001],len[20001],ans[20001],vis[20001],cnt;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
bool SPFA(int s){
  queue<int>q;
  memset(ans,0x3f,sizeof(ans));
  memset(vis,0,sizeof(vis));
  memset(num,0,sizeof(num));
  q.push(s);
  ans[s]=0;
  while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
      if(ans[to[i]]>ans[now]+len[i]){
        ans[to[i]]=ans[now]+len[i];
        num[to[i]]++;
        if(num[to[i]]>=n)return 0;
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
    }
  }
  return 1;
}
int main(){
  scanf("%d%d%d",&n,&ml,&md);
  for(int i=1;i<=n;i++)add(0,i,0);
  for(int i=1;i<=ml;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    add(a,b,l);
  }
  for(int i=1;i<=md;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    add(b,a,-l);
  }
  if(SPFA(0)==0||SPFA(1)==0){
    puts("-1");
  }
  else if(ans[n]==INF){
    puts("-2");
  }
  else{
    printf("%d\n",ans[n]);
  }
  return 0;
}
