#include<bits/stdc++.h>
using namespace std;
int head[10001],nxt[500001],to[500001],len[500001],n,m,s,cnt,vis[10001],ans[10001],num[10001];
void add(int a,int b,int l){
  nxt[++cnt]=head[a];
  to[cnt]=b;
  len[cnt]=l;
  head[a]=cnt;
}
int main(int argc,char *argv[]){
    freopen(argv[1],"r",stdin);
    cin>>n>>s;
    for(int i=1;i<=n;i++)ans[i]=2147483647;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      string s;
      cin>>s;
      if(s!="-"){
        add(i,j,atoi(s.c_str()));
      }
    }
    queue<int>q;
    q.push(s);
    vis[s]=1;
    ans[s]=0;
    while(!q.empty()){
    int now=q.front();
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
    for(int i=1;i<=n;i++)if(i!=s)printf("(%d -> %d) = %d\n",s,i,ans[i]);
    return 0;
}
