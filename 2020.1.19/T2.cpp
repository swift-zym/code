#include<bits/stdc++.h>
using namespace std;
int head[13001],nxt[260001],to[260001],len[260001],cnt,ans[13001],vis[13001];
void add(int a,int b,int l){
  //cout<<"add "<<a<<" "<<b<<endl;
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
int n,m,k;
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    for(int j=0;j<=k;j++){
      if(j!=k){
        add(a+j*n,b+(j+1)*n,0);
        add(b+j*n,a+(j+1)*n,0);
      }
      add(a+j*n,b+j*n,l);
      add(b+j*n,a+j*n,l);
    }
  }
  for(int i=1;i<=(k+1)*n;i++){
    ans[i]=1e8;
  }
  ans[1]=0;
  queue<int>q;
  q.push(1);
  while(!q.empty()){
    int now=q.front();q.pop();vis[now]=0;
    //cout<<"now="<<now<<endl;
    for(int i=head[now];i;i=nxt[i]){
      //cout<<now<<"->"<<to[i]<<" "<<ans[to[i]]<<" "<<len[i]<<endl;
      if(ans[to[i]]>max(ans[now],len[i])){
        ans[to[i]]=max(ans[now],len[i]);
        if(!vis[to[i]]){
          vis[to[i]]=1;
          q.push(to[i]);
        }
      }
    }
  }
  int mi=1e8;
  for(int i=0;i<=k;i++){
    mi=min(mi,ans[(i+1)*n]);
  }
  if(mi==1e8){
    puts("-1");
  }
  else{
    printf("%d\n",mi);
  }
  return 0;
}
