#include<bits/stdc++.h>
using namespace std;
#define MAXN 3000010
vector<int>v[3000010];
int son[MAXN][2];
int dfn[MAXN],low[MAXN],T,vis[MAXN],num,bel[MAXN];
stack<int>s;
void tarjan(int now){
  dfn[now]=low[now]=++T;
  s.push(now);
  vis[now]=1;
  for(int i=0;i<v[now].size();i++){
    if(!dfn[v[now][i]]){
      tarjan(v[now][i]);
      low[now]=min(low[v[now][i]],low[now]);
    }
    else if(vis[v[now][i]]){
      low[now]=min(low[now],dfn[v[now][i]]);
    }
  }
  if(dfn[now]==low[now]){
    int tmp;
    ++num;
    do{
      tmp=s.top();
      bel[tmp]=num;
      vis[tmp]=0;
      s.pop();
    }while(tmp!=now);
  }
}
void add(int a,int b){
  v[a].push_back(b);
  a^=1;
  b^=1;
  v[b].push_back(a);
}
int n,cnt;
void ins(string s,int id){
  int now=n+1,pre;
  int len=s.length();
  for(int i=0;i<len;i++){
    if(!son[now][s[i]-'0'])son[now][s[i]-'0']=++cnt;
    pre=now;now=son[now][s[i]-'0'];add(id,now*2);
  }
  int tmp=++cnt;
  add(id,tmp*2+1);add(tmp*2,now*2);
  son[pre][s[len-1]-'0']=tmp;
}
vector<string>vv;
bool cmp(string a,string b){
  return a.length()<b.length();
}
int main(){
  ios::sync_with_stdio(0);
  cin>>n;
  cnt=n+1;
  for(int i=1;i<=n;i++){
    string tmp;
    cin>>tmp;
    vv.push_back(tmp);
  }
  sort(vv.begin(),vv.end(),cmp);
  for(int i=1;i<=n;i++){
    string s=vv[i-1];
    int len=s.length();
    for(int j=0;j<len;j++){
      if(s[j]=='?'){
        s[j]='0';
        ins(s,i*2);
        s[j]='1';
        ins(s,i*2+1);
        break;
      }
      else if(j+1==len){
        ins(s,i*2);
        add(i*2+1,i*2);
      }
    }
  }
  for(int i=1;i<=cnt*2+1;i++){
    if(!dfn[i])tarjan(i);
  }
  for(int i=1;i<=cnt;i++){
    if(bel[i*2]==bel[i*2+1]){
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
