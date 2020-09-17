//AC自动机模板
#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
struct node{
    int fail,son[26],end=0;
}a[10000];
int cnt,dp[200][10000];
void ins(string s){
    int now=0;
    for(int i=0;i<s.length();i++){
        if(!a[now].son[s[i]-'A']){
            a[now].son[s[i]-'A']=++cnt;
        }
        now=a[now].son[s[i]-'A'];
    }
    a[now].end=1;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(a[0].son[i]){
            a[a[0].son[i]].fail=0;
            a[a[0].son[i]].end|=a[a[a[0].son[i]].fail].end;
            q.push(a[0].son[i]);
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(a[now].son[i]){
                a[a[now].son[i]].fail=a[a[now].fail].son[i];
                a[a[now].son[i]].end|=a[a[a[now].son[i]].fail].end;
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
    int n,m;
    string s;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        ins(s);
    }
    a[0].fail=0;
    build();
    int ans=1;
    for(int i=1;i<=m;i++){
      ans*=26;
      ans%=MOD;
    }
    dp[0][0]=1;
    for(int i=0;i<m;i++)
    for(int j=0;j<=cnt;j++)
    for(int k=0;k<=25;k++){
      if(!a[a[j].son[k]].end){
        dp[i+1][a[j].son[k]]=(dp[i+1][a[j].son[k]]+dp[i][j]+MOD)%MOD;
      }
    }
    for(int i=0;i<=cnt;i++){
      ans=(ans-dp[m][i]+MOD)%MOD;
    }
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
}
