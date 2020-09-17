#include<bits/stdc++.h>
using namespace std;
int head[300001],nxt[3000001],to[3000001],len[3000001],n,m,s,cnt,vis[300001],ans[300001];
struct node{
    int x,y;
    inline bool operator <(const node &a) const {
     return y>a.y;
    }
};
void add(int a,int b,int l,bool fir=1){
  if(fir)add(b,a,l,0);
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
int g(int i,int j){
  return (i-1)*(m+1)+j;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
    memset(head,0,sizeof(head));
    cnt=0;
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=(n+1)*(m+1);i++)ans[i]=2147483647;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      char c=getchar();
      while(c!='\\'&&c!='/')c=getchar();
      if(c=='\\'){
        add(g(i,j),g(i+1,j+1),0);
        add(g(i,j+1),g(i+1,j),1);
      }
      else{
        add(g(i,j),g(i+1,j+1),1);
        add(g(i,j+1),g(i+1,j),0);
      }
    }
    priority_queue<node>q;
    q.push((node){1,0});
    ans[1]=0;
    while(!q.empty()){
        node now=q.top();
        q.pop();
        if(now.y!=ans[now.x])continue;
        for(int i=head[now.x];i;i=nxt[i]){
            if(ans[now.x]+len[i]<ans[to[i]]){
                //printf("upd ans[%d](%d) from ans[%d](%d)\n",to[i],ans[to[i]],now.x,ans[now.x]);
                ans[to[i]]=ans[now.x]+len[i];
                q.push((node){to[i],ans[to[i]]});
            }
        }
    }
    if(ans[(n+1)*(m+1)]==2147483647){
      puts("NO SOLUTION");
      continue;
    }
    printf("%d\n",ans[(n+1)*(m+1)]);
    }
    return 0;
}
