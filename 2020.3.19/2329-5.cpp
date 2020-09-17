#include<bits/stdc++.h>
using namespace std;
int head[100001],nxt[500001],to[500001],len[500001],n,m,s=1,cnt,vis[100001],ans[100001],num[100001];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)ans[i]=2147483647;
    for(int i=1;i<=m;i++){
        int f,g,w=1;
        scanf("%d%d",&f,&g);
        to[++cnt]=g;
        len[cnt]=w;
        nxt[cnt]=head[f];
        head[f]=cnt;
        to[++cnt]=f;
        len[cnt]=w;
        nxt[cnt]=head[g];
        head[g]=cnt;
    }
    queue<int>q;
    num[s]=1;
    q.push(s);
    vis[s]=1;
    ans[s]=0;
    while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
        if(ans[now]+len[i]<ans[to[i]]){
            num[to[i]]=num[now];
            ans[to[i]]=ans[now]+len[i];
            if(!vis[to[i]]){
                q.push(to[i]);
                vis[to[i]]=1;
            }
        }
        else if(ans[now]+len[i]==ans[to[i]]){
          num[to[i]]+=num[now];
          num[to[i]]%=100003;
        }
    }
    }
    for(int i=1;i<=n;i++)printf("%d\n",num[i]);
    return 0;
}
