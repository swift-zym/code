//AC自动机模板
#include<bits/stdc++.h>
using namespace std;
struct node{
    int fail,son[27],end=0,num=0;
}a[1000010];
int cnt,ed[201],in[1100000],ans[1100000];
void ins(string s,int id){
    int now=0;
    for(int i=0;i<s.length();i++){
        if(!a[now].son[s[i]-'a']){
            a[now].son[s[i]-'a']=++cnt;
        }
        now=a[now].son[s[i]-'a'];
    }
    if(!a[now].end){
    a[now].end=id;
    }
    ed[id]=a[now].end;
}
void build(){
    queue<int>q;
    for(int i=0;i<=26;i++){
        if(a[0].son[i]){
            a[a[0].son[i]].fail=0;
            in[0]++;
            q.push(a[0].son[i]);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<=26;i++){
            if(a[now].son[i]){
                a[a[now].son[i]].fail=a[a[now].fail].son[i];
                in[a[a[now].son[i]].fail]++;
                q.push(a[now].son[i]);
            }
            else{
                a[now].son[i]=a[a[now].fail].son[i];
            }
        }
    }
}
void query(string s){
    int l=s.length();
    int now=0;
    for(int i=0;i<l;i++){
        now=a[now].son[s[i]-'a'];
        a[now].num++;
    }
}
void work(){
  queue<int>q;
  for(int i=0;i<=cnt;i++)
  if(in[i]==0)q.push(i);
  while(!q.empty()){
    int now=q.front();q.pop();
    ans[a[now].end]=a[now].num;
    in[a[now].fail]--;
    a[a[now].fail].num+=a[now].num;
    if(in[a[now].fail]==0)q.push(a[now].fail);
  }
}
int main(){
    int n;
    string tmp[201],s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp[i];
        ins(tmp[i],i);
        s+=tmp[i];
        s+="{";
    }
    a[0].fail=0;
    build();
    query(s);
    work();
    for(int i=1;i<=n;i++){
      printf("%d\n",ans[ed[i]]);
    }
    #ifdef WIN32
    system("pause");
    #endif
}
