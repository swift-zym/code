#include<bits/stdc++.h>
#define int long long
using namespace std;
int son[500050][26],cnt=1,tag[500050],fa[500050],siz[500050];
void ins(string s){
  int len=s.length(),now=1;
  for(int i=len-1;i>=0;i--){
    if(!son[now][s[i]-'a']){
      son[now][s[i]-'a']=++cnt;
    }
    now=son[now][s[i]-'a'];
  }
  tag[now]=1;
}
vector<int>tmp[500050];
void rebuild(int now){
  if(now!=1&&tag[now]){
    tmp[fa[now]].push_back(now);
    fa[now]=now;
  }
  for(int i=0;i<=25;i++){
    if(son[now][i]){
      fa[son[now][i]]=fa[now];
      rebuild(son[now][i]);
    }
  }
}
bool cmp(int a,int b){
  return siz[a]<siz[b];
}
void sort_tree(int now){
  siz[now]=1;
  for(int i=0;i<tmp[now].size();i++){
    sort_tree(tmp[now][i]);
    siz[now]+=siz[tmp[now][i]];
  }
  sort(tmp[now].begin(),tmp[now].end(),cmp);
}
int n,ans,dfs_num;
void solve(int now){
  int now_num=dfs_num++;
  for(int i=0;i<tmp[now].size();i++){
    ans+=dfs_num-now_num;
    solve(tmp[now][i]);
  }
}
signed main(){
  ios::sync_with_stdio(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    string s;
    cin>>s;
    ins(s);
  }
  fa[1]=1;
  rebuild(1);
  sort_tree(1);
  solve(1);
  cout<<ans<<endl;
  return 0;
}
