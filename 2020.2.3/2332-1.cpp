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
int n,a[100001];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]),ins(a[i]);
  int mx=-1;
  for(int i=1;i<=n;i++){
    mx=max(mx,solve(a[i]));
  }
  printf("%d\n",mx);
  return 0;
}
