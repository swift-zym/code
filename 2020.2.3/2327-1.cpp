#include<bits/stdc++.h>
using namespace std;
int head[100],nxt[1000],to[1000],len[1000],cnt;
int vis[100],ans[100],num[100],tmp[100];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
void clear(){
  memset(head,0,sizeof(head));
  memset(ans,-0x3f,sizeof(ans));
  memset(vis,0,sizeof(vis));
  memset(num,0,sizeof(num));
  cnt=0;
}
int SPFA(){
  queue<int>q;
  ans[0]=0;
  q.push(0);
  while(!q.empty()){
    int now=q.front();
    vis[now]=0;
    num[now]++;
    q.pop();
    for(int i=head[now];i;i=nxt[i]){
      if(ans[to[i]]<ans[now]+len[i]){
        ans[to[i]]=ans[now]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
          if(num[to[i]]>=24)return 0;
        }
      }
    }
  }
  return ans[24];
}
int T,r[25];
int main(){
  scanf("%d",&T);
  while(T--){
    for(int i=1;i<=24;i++)scanf("%d",&r[i]);
    int n;
    scanf("%d",&n);
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=n;i++){
      int v;
      scanf("%d",&v);
      tmp[v+1]++;
    }
    bool flag=0;
    for(int l=1;l<=n;l++){
      clear();
      add(0,24,l);
      for(int i=1;i<=24;i++){
        add(i-1,i,0);
        add(i,i-1,-tmp[i]);
      }
      for(int i=1;i<=8;i++){
        add(i+16,i,r[i]-l);
      }
      for(int i=9;i<=24;i++){
        add(i-8,i,r[i]);
      }
      if(SPFA()==l){
        printf("%d\n",l);
        flag=1;
        break;
      }
    }
    if(!flag){
      puts("No Solution");
    }
  }
  return 0;
}
