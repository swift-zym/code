#include<bits/stdc++.h>
using namespace std;
int n,m,head[5001],nxt[200001],to[200001],len[200001],cnt;
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
int ans[5001][2],vis[5001];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    add(a,b,l);
    add(b,a,l);
  }
  memset(ans,0x3f,sizeof(ans));
  ans[1][1]=0;
  queue<int>q;
  q.push(1);
  while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
      if(ans[now][1]+len[i]<ans[to[i]][1]){
        ans[to[i]][0]=ans[to[i]][1];
        ans[to[i]][1]=ans[now][1]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
      if(ans[now][1]+len[i]<ans[to[i]][0]&&ans[now][1]+len[i]>ans[to[i]][1]){
        ans[to[i]][0]=ans[now][1]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
      if(ans[now][0]+len[i]<ans[to[i]][0]){
        ans[to[i]][0]=ans[now][0]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
    }
  }
  printf("%d\n",ans[n][0]);
  return 0;
}
