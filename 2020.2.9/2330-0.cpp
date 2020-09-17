#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[10001],nxt[1000001],to[1000001],len[1000001],n,m,cnt,vis[10001],ans[10001],num[10001];
const int mod = (1ll << 31) - 1ll;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)ans[i]=2147483647;
    for(int i=1;i<=m;i++){
        int f,g,w;
        scanf("%lld%lld%lld",&f,&g,&w);
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
    q.push(1);
    vis[1]=1;
    ans[1]=0;
    while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
        if(ans[now]+len[i]<ans[to[i]]){
            ans[to[i]]=ans[now]+len[i];
            num[to[i]]=1;
            if(!vis[to[i]]){
                q.push(to[i]);
                vis[to[i]]=1;
            }
        }
        else if(ans[now]+len[i]==ans[to[i]]){
            num[to[i]]++;
        }
    }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
      if(num[i]){
        ans*=num[i];
        ans%=mod;
      }
    }
    printf("%lld\n",ans);
    return 0;
}
