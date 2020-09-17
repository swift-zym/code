#include<bits/stdc++.h>
using namespace std;
int head[10001],nxt[500001],to[500001],len[500001],n,m,s,cnt,vis[10001],ans[10001];
int head1[10001],nxt1[500001],to1[500001],len1[500001],cnt1,vis1[10001],ans1[10001];
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++)ans[i]=ans1[i]=2147483647;
    for(int i=1;i<=m;i++){
        int f,g,w;
        scanf("%d%d%d",&g,&f,&w);
        to[++cnt]=g;
        len[cnt]=w;
        nxt[cnt]=head[f];
        head[f]=cnt;
        to1[++cnt1]=f;
        len1[cnt1]=w;
        nxt1[cnt1]=head1[g];
        head1[g]=cnt1;
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
    queue<int>q1;
    q1.push(s);
    vis1[s]=1;
    ans1[s]=0;
    while(!q1.empty()){
    int now=q1.front();
    q1.pop();
    vis1[now]=0;
    for(int i=head1[now];i;i=nxt1[i]){
        if(ans1[now]+len1[i]<ans1[to1[i]]){
            ans1[to1[i]]=ans1[now]+len1[i];
            if(!vis1[to1[i]]){
                q1.push(to1[i]);
                vis1[to1[i]]=1;
            }
        }
    }
    }
    int mx=-1;
    for(int i=1;i<=n;i++)mx=max(mx,ans[i]+ans1[i]);;
    printf("%d\n",mx);
    return 0;
}
