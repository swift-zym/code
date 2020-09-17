//题目名：受欢迎的牛
#include<bits/stdc++.h>
using namespace std;
int du[1000001],head[1000001],to[5000001],nxt[5000001],n,m,cnt,Time,dfn[1000001],low[1000001],vis[1000001],ansCnt,in[10001];
stack<int>ans;
void tarjan(int now){
    dfn[now]=low[now]=++Time;
    vis[now]=1;
    ans.push(now);
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
        ansCnt++;
        while(ans.top()!=now){
            in[ans.top()]=ansCnt;
            vis[ans.top()]=0;
            ans.pop();
        }
        in[now]=ansCnt;
        ans.pop();
        vis[now]=0;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        to[++cnt]=b;
        nxt[cnt]=head[a];
        head[a]=cnt;
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=nxt[j]){
            if(in[i]!=in[to[j]]){
                du[in[i]]++;
            }
        }
    }
    int id=-1;
    for(int i=1;i<=ansCnt;i++){
        if(du[i]==0){
        if(id!=-1){
            printf("0\n");
            return 0;
        }
        id=i;
        }
    }
    int out=0;
    for(int i=1;i<=n;i++){
        if(in[i]==id)out++;
    }
    printf("%d\n",out);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
