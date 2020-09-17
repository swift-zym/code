//AC自动机模板
#include<bits/stdc++.h>
using namespace std;
struct node{
    int fail,son[26],end=0;
}a[1000000];
int cnt;
void ins(string s){
    int now=0;
    for(int i=0;i<s.length();i++){
        if(!a[now].son[s[i]-'a']){
            a[now].son[s[i]-'a']=++cnt;
        }
        now=a[now].son[s[i]-'a'];
    }
    a[now].end=s.length();
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
int st1[1000001],st2[1000001],tp;
void query(string s){
    int l=s.length();
    int now=0;
    for(int i=0;i<l;i++){
        now=a[now].son[s[i]-'a'];
        st1[++tp]=i;
        st2[tp]=now;
        if(a[now].end){
          tp-=a[now].end;
          if(!tp)now=0;
          else now=st2[tp];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    string s,tmp;
    cin>>tmp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        ins(s);
    }
    a[0].fail=0;
    build();
    query(tmp);
    for(int i=1;i<=tp;i++){
      putchar(tmp[st1[i]]);
    }
    putchar(10);
    #ifdef WIN32
    system("pause");
    #endif
}
