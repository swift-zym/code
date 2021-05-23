//题目名：奶牛舞会
#include<bits/stdc++.h>
using namespace std;
int head[100001],to[100001],nxt[100001],Size[100001],in[100001],dfn[100001],low[100001],vis[100001],Time,n,m,cnt,ansCnt;
stack<int>ans;
void tarjan(int now){
    dfn[now]=low[now]=++Time;
    ans.push(now);
    vis[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(!dfn[to[i]]){
            tarjan(to[i]);
            low[now]=min(low[now],low[to[i]]);
        }
        else if(vis[to[i]]){
            low[now]=min(low[now],dfn[to[i]]);
        }
    }
    if(low[now]==dfn[now]){
        ++ansCnt;
        while(ans.top()!=now){
            vis[ans.top()]=0;
            in[ans.top()]=ansCnt;
            Size[ansCnt]++;
            ans.pop();
        }
        vis[now]=0;
        in[now]=ansCnt;
        Size[ansCnt]++;
        ans.pop();
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        nxt[++cnt]=head[a];
        head[a]=cnt;
        to[cnt]=b;
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int out=0;
    for(int i=1;i<=ansCnt;i++){
        if(Size[i]!=1)++out;
    }
    printf("%d\n",out);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}