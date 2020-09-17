//AC自动机模板
#include<bits/stdc++.h>
using namespace std;
struct node{
    int fail,son[26],end=0;
}a[1000000];
int cnt,his[1000000],vis[1000000];
void dfs(int now){
  vis[now]=1;
  for(int i=0;i<=1;i++){
    if(vis[a[now].son[i]]){
      puts("TAK");
      exit(0);
    }
    else if(a[a[now].son[i]].end==0&&his[a[now].son[i]]==0){
      his[a[now].son[i]]=1;
      dfs(a[now].son[i]);
    }
  }
  vis[now]=0;
}
void ins(string s){
    int now=0;
    for(int i=0;i<s.length();i++){
        if(!a[now].son[s[i]-'0']){
            a[now].son[s[i]-'0']=++cnt;
        }
        now=a[now].son[s[i]-'0'];
    }
    a[now].end=1;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(a[0].son[i]){
            a[a[0].son[i]].fail=0;
            q.push(a[0].son[i]);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(a[now].son[i]){
                a[a[now].son[i]].fail=a[a[now].fail].son[i];
                if(a[a[a[now].fail].son[i]].end)a[a[now].son[i]].end=1;
                q.push(a[now].son[i]);
            }
            else{
                a[now].son[i]=a[a[now].fail].son[i];
            }
        }
    }
}
int main(){
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        ins(s);
    }
    a[0].fail=0;
    build();
    dfs(0);
    puts("NIE");
    #ifdef WIN32
    system("pause");
    #endif
}
