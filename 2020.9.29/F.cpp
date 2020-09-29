#include<bits/stdc++.h>
using namespace std;
int n,t,s,e;
int head[1001],nxt[2000001],to[2000001],len[2000001],cnt;
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int vis[1001],ans[1001],step[1001];
int main(){
    scanf("%d%d%d%d",&n,&t,&s,&e);
    for(int i=1;i<=t;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    memset(ans,0x3f,sizeof(ans));
    ans[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=nxt[i]){
            if(ans[to[i]]>ans[now]+len[i]){
                ans[to[i]]=ans[now]+len[i];
                step[to[i]]=step[now]+1;
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    int sum=0;
    sum+=ans[t];
    if(n-step[t]%2!=0){
        assert(0);
    }
    return 0;
}
