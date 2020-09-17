//AC自动机模板
#include<bits/stdc++.h>
using namespace std;
struct node{
    int fail,son[26],end=0,sta=0;
    char ch;
}a[1000];
int cnt;
void ins(string s,int id){
    int now=0;
    for(int i=0;i<s.length();i++){
        if(!a[now].son[s[i]-'A']){
            a[now].son[s[i]-'A']=++cnt;
        }
        now=a[now].son[s[i]-'A'];
    }
    a[now].sta|=(1<<(id-1));
    a[now].end=1;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(a[0].son[i]){
            a[a[0].son[i]].fail=0;
            q.push(a[0].son[i]);
        }
        a[a[0].son[i]].ch='A'+i;
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(a[now].son[i]){
                a[a[now].son[i]].fail=a[a[now].fail].son[i];
                q.push(a[now].son[i]);
            }
            else{
                a[now].son[i]=a[a[now].fail].son[i];
            }
            a[a[now].son[i]].ch='A'+i;
        }
        int tmp=a[now].fail;
        while(tmp!=0&&a[tmp].sta==0){
          tmp=a[tmp].fail;
        }
        a[now].sta|=a[tmp].sta;
    }
}
struct tmp{
  int now,sta,id;
};
int fa[2500050],ch[2500050],num;
int n,vis[1000][1<<12];
void bfs(){
  queue<tmp>q;
  q.push({0,0,0});
  vis[0][0]=1;
  while(!q.empty()){
    //cout<<h<<" "<<t<<endl;
    tmp h=q.front();
    q.pop();
    //vis[h.now][h.sta]=1;
    if(h.sta==(1<<n)-1){
      vector<char>v;
      do{
        v.push_back(ch[h.id]+'A');
        h.id=fa[h.id];
      }while(h.id);
      for(int i=v.size()-1;i>=0;i--){
        putchar(v[i]);
      }
      putchar(10);
      exit(0);
    }
    for(int i=0;i<=25;i++){
      if(a[h.now].son[i]){
        if(vis[a[h.now].son[i]][a[a[h.now].son[i]].sta|h.sta])continue;
        vis[a[h.now].son[i]][a[a[h.now].son[i]].sta|h.sta]=1;
        ch[++num]=i;fa[num]=h.id;
        q.push({a[h.now].son[i],a[a[h.now].son[i]].sta|h.sta,num});
      }
    }
    /*if(a[b[h].now].fail){
      if(!vis[a[b[h].now].fail][a[a[b[h].now].fail].sta|b[h].sta]){
      ++t;
      b.push_back({a[b[h].now].fail,a[a[b[h].now].fail].sta|b[h].sta,h});
      }
    }*/
  }
}
int main(){
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        ins(s,i);
    }
    a[0].fail=0;
    build();
    bfs();
    #ifdef WIN32
    system("pause");
    #endif
}
