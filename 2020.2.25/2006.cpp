#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[10001],nxt[500001],to[500001],len[500001],n,m,s,cnt,vis[10001],ans[10001],num[10001];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
int my_atoi(string s){
  int ans=0,len=s.length();
  for(int i=0;i<len;i++){
    ans*=10;
    ans+=(s[i]-'0');
  }
  return ans;
}
signed main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++)ans[i]=9223372036854775807;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      string s;
      cin>>s;
      if(s!="-"){
        if(s.length()<=9)
        add(i,j,atoi(s.c_str()));
        else
        add(i,j,my_atoi(s));
      }
    }
    queue<int>q;
    q.push(s);
    vis[s]=1;
    ans[s]=0;
    while(!q.empty()){
    int now=q.front();
    num[now]++;
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
        if(ans[now]+len[i]<ans[to[i]]){
            ans[to[i]]=ans[now]+len[i];
            if(!vis[to[i]]){
                q.push(to[i]);
                vis[to[i]]=1;
            }
        }
    }
    }
    for(int i=1;i<=n;i++)if(i!=s)printf("(%lld -> %lld) = %lld\n",s,i,ans[i]);
    return 0;
}
