#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,head[1000],nxt[10000],to[10000],cnt,du[1000],ans[1000],use[1000];
void add(int a,int b){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  head[a]=cnt;
  du[b]++;
}
signed main(){
  freopen("1.out.txt","r",stdin);
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%lld%lld",&a,&b);
    if(a>b){
      puts("Format Error:a>b");
    }
    add(a,b);
  }
  ans[1]=1;
  for(int i=1;i<=n;i++){
    int id=-1;
    for(int j=1;j<=n;j++){
      if(du[j]==0&&!use[j]){
        id=j;
        use[j]=1;
        break;
      }
    }
    if(id==-1){
      printf("Wrong Answer on i = %d\n",i);
      exit(0);
    }
    for(int i=head[id];i;i=nxt[i]){
      ans[to[i]]+=ans[id];
      du[to[i]]--;
    }
  }
  freopen("1.in.txt","r",stdin);;
  int y;
  scanf("%lld",&y);
  if(y==ans[n]&&n<=64){
    puts("Accept");
  }
  else if(n<=16384){
    puts("Wrong Answer 20%~80%");
  }
  else{
    puts("Wrong Answer");
    printf("---RIGHT---\n%lld\n---YOUR---\n%lld\n",y,ans[n]);
  }
  return 0;
}
