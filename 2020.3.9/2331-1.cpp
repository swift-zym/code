//AC自动机模板
#include<bits/stdc++.h>
using namespace std;
struct node{
    int fail,son[26],vis=0,end=0;
}a[1000000];
int cnt;
void ins(string s){
    int now=0;
    for(int i=0;i<s.length();i++){
        if(!a[now].son[s[i]-'A']){
            a[now].son[s[i]-'A']=++cnt;
        }
        now=a[now].son[s[i]-'A'];
    }
    a[now].end+=1;
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
                q.push(a[now].son[i]);
            }
            else{
                a[now].son[i]=a[a[now].fail].son[i];
            }
        }
    }
}
int query(string s){
    int l=s.length();
    int now=0,ans=0;
    for(int i=0;i<l;i++){
        now=a[now].son[s[i]-'A'];
        for(int j=now;j&&a[j].end!=-1;j=a[j].fail){
            ans+=a[j].end;
            a[j].vis=1;
            a[j].end=-1;
        }
    }
    return ans;
}
int solve(string s){
  int ans=-1,now=0,l=s.length();
  for(int i=0;i<l;i++){
    now=a[now].son[s[i]-'A'];
    if(a[now].vis)ans=i;
  }
  return ans+1;
}
string tmp[100001];
int main(){
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=m;i++){
        cin>>tmp[i];
        ins(tmp[i]);
    }
    a[0].fail=0;
    build();
    query(s);
    for(int i=1;i<=m;i++){
      printf("%d\n",solve(tmp[i]));
    }
    #ifdef WIN32
    system("pause");
    #endif
}
