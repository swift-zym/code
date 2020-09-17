#include<bits/stdc++.h>
using namespace std;
struct trie{
  int son[2];
}tr[4000000];
int cnt=1;
void ins(int a){
  vector<int>v;
  while(a){
    v.push_back(a%2);
    a/=2;
  }
  while(v.size()!=32)v.push_back(0);
  int now=1;
  for(int i=v.size()-1;i>=0;i--){
    if(tr[now].son[v[i]]){
      now=tr[now].son[v[i]];
    }
    else{
      tr[now].son[v[i]]=++cnt;
      now=tr[now].son[v[i]];
    }
  }
}
int solve(int a){
  vector<int>v;
  while(a){
    v.push_back(a%2);
    a/=2;
  }
  while(v.size()!=32)v.push_back(0);
  int now=1,ans=0;
  for(int i=v.size()-1;i>=0;i--){
    if(tr[now].son[1-v[i]]){
      ans+=1<<i;
      now=tr[now].son[1-v[i]];
    }
    else{
      now=tr[now].son[v[i]];
    }
  }
  return ans;
}
int n,head[100001],to[200001],nxt[200001],len[200001],_cnt,tmp[100001];
void add(int a,int b,int l){
  nxt[++_cnt]=head[a];
  to[_cnt]=b;
  head[a]=_cnt;
  len[_cnt]=l;
}
void dfs(int now,int fa){
  for(int i=head[now];i;i=nxt[i]){
    if(to[i]==fa)continue;
    tmp[to[i]]=(tmp[now]^len[i]);
    dfs(to[i],now);
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    add(a,b,l);
    add(b,a,l);
  }
  dfs(1,1);
  for(int i=1;i<=n;i++){
    ins(tmp[i]);
  }
  int mx=-1;
  for(int i=1;i<=n;i++){
    mx=max(mx,solve(tmp[i]));
  }
  printf("%d\n",mx);
  return 0;
}
