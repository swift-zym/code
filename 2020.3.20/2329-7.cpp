#include<bits/stdc++.h>
using namespace std;
int head[310000],nxt[3100000],to[3100000],len[3100000],cnt;
int n,m,v[310000],vis[310000],ans[310000];
void add(int a,int b,int l){
  //cout<<"Add "<<a<<" "<<b<<endl;
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&v[i]);
  for(int i=1;i<=m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    add(a,b,0);
    add(a+n,b+n,0);
    add(a+2*n,b+2*n,0);
    if(c==2){
      add(b,a,0);
      add(b+n,a+n,0);
      add(b+2*n,a+2*n,0);
    }
  }
  for(int i=1;i<=n;i++){
    add(i,i+n,-v[i]);
    add(i+n,i+2*n,v[i]);
  }
  add(n,3*n+1,0);
  add(3*n,3*n+1,0);
  for(int i=1;i<=3*n+1;i++){
    ans[i]=-1e8;
  }
  queue<int>q;
  q.push(1);
  ans[1]=0;
  while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
      if(ans[to[i]]<ans[now]+len[i]){
        ans[to[i]]=ans[now]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
    }
  }
  printf("%d\n",ans[3*n+1]);
  return 0;
}
