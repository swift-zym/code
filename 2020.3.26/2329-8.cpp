#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,c,is[101][101];
int head[1000000],nxt[1000000],to[1000000],len[1000000],id[101][101],cnt,ans[1000000],vis[1000000];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
int mx[4]={0,1,0,-1},my[]={1,0,-1,0};
int main(){
  scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    id[i][j]=(i-1)*n+j;
    scanf("%d",&is[i][j]);
  }
  for(int d=0;d<=k;d++)
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    if(is[i][j]){
      if(d){
        add(n*n*d+id[i][j],id[i][j],a);
      }
      else{
        for(int tmp=0;tmp<=3;tmp++){
          int x=i+mx[tmp],y=j+my[tmp];
          if(x<=0||x>n||y<=0||y>n)continue;
          if(tmp<=1){
            add(n*n*d+id[i][j],n*n*(d+1)+id[x][y],0);
          }
          else{
            add(n*n*d+id[i][j],n*n*(d+1)+id[x][y],b);
          }
        }
      }
    }
    else{
      if(d==k){
        add(n*n*d+id[i][j],id[i][j],c+a);
      }
      else{
          for(int tmp=0;tmp<=3;tmp++){
            int x=i+mx[tmp],y=j+my[tmp];
            if(x<=0||x>n||y<=0||y>n)continue;
            if(tmp<=1){
              add(n*n*d+id[i][j],n*n*(d+1)+id[x][y],0);
            }
            else{
              add(n*n*d+id[i][j],n*n*(d+1)+id[x][y],b);
            }
          }
      }
    }
  }
  queue<int>q;
  memset(ans,0x3f,sizeof(ans));
  q.push(1);
  ans[1]=0;
  while(!q.empty()){
    int now=q.front();q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
      if(ans[to[i]]>ans[now]+len[i]){
        ans[to[i]]=ans[now]+len[i];
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
    }
  }
  int mi=1e8;
  for(int i=0;i<=k;i++){
    //printf("%d->%d\n",i,ans[i*n*n+id[n][n]]);
    mi=min(mi,ans[i*n*n+id[n][n]]);
  }
  printf("%d\n",mi);
  return 0;
}
