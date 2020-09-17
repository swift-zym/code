#include<bits/stdc++.h>
using namespace std;
int last,n,m,head[5001],nxt[1000001],to[1000001],cnt,vis[1000001],q[5001],s,t;
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
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int opt,x,y;
    scanf("%d%d%d",&opt,&x,&y);
    x^=last;
    y^=last;
    if(opt==0){
      add(x,y);
      add(y,x);
    }
    else if(opt==1){
      del(x,y);
      del(y,x);
    }
    else{
      t=s=0;
      q[t++]=x;
      memset(vis,0,sizeof(vis));
      bool flag=0;
      while(s<t){
        int now=q[s++];
        for(int i=head[now];i;i=nxt[i]){
          if(!vis[to[i]]){
            vis[to[i]]=1;
            if(to[i]==y){
              flag=1;
              break;
            }
            q[t++]=to[i];
          }
        }
        if(flag)break;
      }
      if(flag){
        last=x;
        puts("Y");
      }
      else{
        last=y;
        puts("N");
      }
    }
  }
  return 0;
}
