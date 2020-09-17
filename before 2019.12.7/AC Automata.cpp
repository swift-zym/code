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
        now=a[now].son[s[i]-'a'];
        for(int j=now;j&&a[j].end!=-1;j=a[j].fail){
            ans+=a[j].end;
            a[j].end=-1;
        }
    }
    return ans;
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
    cin>>s;
    printf("%d\n",query(s));
    #ifdef WIN32
    system("pause");
    #endif
}