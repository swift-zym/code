#include<iostream>
using namespace std;
int n,head[300001],nxt[600001],to[600001],cnt;
int mx,id;
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
}
void dfs(int now,int fa,int len){
  if(len>mx){
    mx=len;
    id=now;
  }
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    dfs(to[i],now,len+1);
  }
}
int getLen(int s){
  mx=-1;
  dfs(s,s,0);
  mx=-1;
  dfs(id,id,0);
  return mx;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
    add(b,a);
    printf("%d\n",getLen(a));
  }
  return 0;
}
