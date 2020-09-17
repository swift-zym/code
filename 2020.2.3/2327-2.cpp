#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int head[100001],nxt[200001],to[200001],len[200001],cnt;
int vis[100001],ans[100001],num[100001];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  len[cnt]=l;
}
signed main(){
  scanf("%lld%lld",&n,&k);
  for(int i=1;i<=k;i++){
    int a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a==1){
      add(b,c,0);
      add(c,b,0);
    }
    else if(a==2){
      add(b,c,1);
    }
    else if(a==3){
      add(c,b,0);
    }
    else if(a==4){
      add(c,b,1);
    }
    else{
      add(b,c,0);
    }
    if(a%2==0&&b==c){
      puts("-1");
      return 0;
    }
  }
  queue<int>q;
  for(int i=1;i<=n;i++){
    q.push(i);
    vis[i]=1;
    ans[i]=1;
  }
  while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
      if(ans[to[i]]<ans[now]+len[i]){
        ans[to[i]]=ans[now]+len[i];
        num[to[i]]++;
        if(num[to[i]]>=n){
          puts("-1");
          return 0;
        }
        if(!vis[to[i]]){
          q.push(to[i]);
          vis[to[i]]=1;
        }
      }
    }
  }
  int sum=0;
  for(int i=1;i<=n;i++)sum+=ans[i];
  printf("%lld\n",sum);
  return 0;
}
