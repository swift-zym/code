#include<iostream>
#include<queue>
#define int long long
using namespace std;
int t;
int n,head[100001],nxt[200001],to[200001],len[200001],cnt;
struct node{
  int len,num;
  bool operator <(const node &t)const{
    return (len-len/2)*num<(t.len-t.len/2)*t.num;
  }
};
priority_queue<node>p;
int sum;
int dfs(int now,int fa,int tmp){
  //cout<<now<<" "<<fa<<" "<<tmp<<endl;
  int vv=0;
  for(int i=head[now];i;i=nxt[i]){
    //cout<<">"<<to[i]<<" "<<now<<endl;
    if(to[i]==fa)continue;
    int v=dfs(to[i],now,tmp+len[i]);
    vv+=v;
    node new_node;
    new_node.len=len[i];
    new_node.num=v;
    p.push(new_node);
  }
  if(vv==0){
    sum+=tmp;
    return 1;
  }
  return vv;
}
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
int s;
signed main(){
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&n,&s);
    cnt=sum=0;
    for(int i=1;i<=n;i++)head[i]=0;
    for(int i=1;i<n;i++){
      int a,b,l;
      scanf("%lld%lld%lld",&a,&b,&l);
      add(a,b,l);
      add(b,a,l);
    }
    dfs(1,1,0);
    int ans=0;
    //cout<<sum<<endl;
    while(sum>s){
      //cout<<sum<<" "<<s<<endl;
      ans++;
      node now=p.top();p.pop();
      //cout<<now.len<<">"<<now.num<<endl;
      sum-=(now.len-now.len/2)*now.num;
      now.len=now.len/2;
      p.push(now);
    }
    while(!p.empty())p.pop();
    printf("%lld\n",ans);
  }
  return 0;
}
