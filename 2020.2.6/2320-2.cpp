#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,fa[100001][21],dep[100001],dfn[100001],tmp[100001],T,ans;
vector<int>sv[100001],len[100001];
void dfs(int now,int f){
  dfn[now]=++T;
  fa[now][0]=f;
  for(int i=0;i<sv[now].size();i++){
    if(f!=sv[now][i]){
      dep[sv[now][i]]=dep[now]+1;
      tmp[sv[now][i]]=tmp[now]+len[now][i];
      dfs(sv[now][i],now);
    }
  }
}
int lca(int a,int b){
  if(dep[a]<dep[b])swap(a,b);
  for(int i=20;i>=0;i--){
    if(dep[fa[a][i]]>=dep[b]){
      a=fa[a][i];
    }
  }
  if(a==b)return a;
  for(int i=20;i>=0;i--){
    if(fa[a][i]!=fa[b][i]){
      a=fa[a][i];
      b=fa[b][i];
    }
  }
  return fa[a][0];
}
int dis(int a,int b){
  return tmp[a]+tmp[b]-2*tmp[lca(a,b)];
}
struct node{
  int id,v;
  bool operator <(const node &t)const{
    return v<t.v;
  }
};
set<node>st;
void file(){
    freopen("stone2.in","r",stdin);
    freopen("stone2.out","w",stdout);
}
void print(){
  for(set<node>::iterator i=st.begin();i!=st.end();i++){
    cerr<<i->id<<" ";
  }
  cerr<<endl;
}
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<n;i++){
    int a,b,l;
    scanf("%lld%lld%lld",&a,&b,&l);
    sv[a].push_back(b);
    len[a].push_back(l);
    sv[b].push_back(a);
    len[b].push_back(l);
  }
  dfs(1,1);
  for(int j=1;j<=20;j++)
  for(int i=1;i<=n;i++){
    fa[i][j]=fa[fa[i][j-1]][j-1];
  }
  scanf("%lld",&m);
  for(int i=1;i<=m;i++){
    char c=getchar();
    while(c!='+'&&c!='-'&&c!='?')c=getchar();
    if(c=='+'){
      int a;
      scanf("%lld",&a);
      set<node>::iterator v=st.lower_bound({0,dfn[a]});
      if(st.size()==0){
        st.insert({a,dfn[a]});
        continue;
      }
      set<node>::iterator l,r;
      if(v==st.end()){
        l=--st.end();
        r=st.begin();
      }
      else if(v==st.begin()){
        l=--st.end();
        r=v;
      }
      else{
        l=--v;
        r=++v;
      }
      ans+=dis(l->id,a)+dis(r->id,a)-dis(l->id,r->id);
      st.insert({a,dfn[a]});
    }
    else if(c=='-'){
      int a;
      scanf("%lld",&a);
      set<node>::iterator v=st.lower_bound({0,dfn[a]});
      if(st.size()==1){
        st.erase(v);
        continue;
      }
      set<node>::iterator l,r;
      if(v==--st.end()){
        r=st.begin();
        l=--v;
        ++v;
      }
      else if(v==st.begin()){
        l=--st.end();
        r=++v;
        --v;
      }
      else{
        l=--v;
        v++;
        r=++v;
        --v;
      }
      ans-=dis(l->id,a)+dis(r->id,a)-dis(l->id,r->id);
      st.erase(v);
    }
    else{
      printf("%lld\n",ans/2);
    }
  }
  return 0;
}
