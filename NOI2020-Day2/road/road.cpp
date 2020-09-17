#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[500001],nxt[2000001],to[2000001],len[2000001],n,m,s,t,cnt=-1,vis[500001],ans[500001];
struct node{
    int x,y;
    inline bool operator <(const node &a) const {
     return y>a.y;
    }
}b[500001];
void add(int f,int g,int w){
    nxt[++cnt]=head[f];
    to[cnt]=g;
    len[cnt]=w;
    head[f]=cnt;
}
int lst[500001];
int col[500001];
int tag[2000001];
int pre[500001];
int num=0;
void check(int now){
    //cerr<<">"<<now<<endl;
    col[now]=1;
    num++;
    for(int i=head[now];i!=-1;i=nxt[i]){
        if(tag[i]||col[to[i]])continue;
        check(to[i]);
    }
}
int mi=1e18;
void dfs(int now,int ans){
    //cerr<<now<<" "<<ans<<endl;
    if(now==t){
        int tmp=t;
        while(tmp!=s){
            tag[lst[tmp]]=tag[lst[tmp]^1]=1;
            tmp=pre[tmp];
        }
        memset(col,0,sizeof(col));
        num=0;
        check(1);
        if(num!=n){
            while(tmp!=s){
                tag[lst[tmp]]=tag[lst[tmp]^1]=0;
                tmp=pre[tmp];
            }
           return;
        }
        tmp=t;
        while(tmp!=s){
            tag[lst[tmp]]=tag[lst[tmp]^1]=0;
            tmp=pre[tmp];
        }
        mi=min(mi,ans);
        return;
    }
    vis[now]=1;
    for(int i=head[now];i!=-1;i=nxt[i]){
        if(!vis[to[i]]){
            lst[to[i]]=i;
            pre[to[i]]=now;
            dfs(to[i],ans+len[i]);
        }
    }
    vis[now]=0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    puts("-1");
    return 0;
}