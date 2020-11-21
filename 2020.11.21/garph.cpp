#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,q;
struct node{
    int x,v;
    bool operator <(const node &t)const{
        return v>t.v;
    }
};
int dis[300001],vis[300001];
int head[300001],nxt[600001],len[600001],to[600001],cnt;
int pre[300001],pre_len[300001];
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
priority_queue<node>p;
vector<int>v[300001];
void dij(int s){
    dis[s]=-1;
    p.push({s,-1});
    while(!p.empty()){
        node now=p.top();p.pop();vis[now.x]=1;
        for(int i=head[now.x];i;i=nxt[i]){
            if(max(dis[now.x],len[i])<dis[to[i]]){
                dis[to[i]]=max(dis[now.x],len[i]);
                pre[to[i]]=now.x;
                pre_len[to[i]]=len[i];
                if(!vis[to[i]])
                p.push({to[i],dis[to[i]]});
            }
        }
    }
}
int fa[300001][20],val[300001][20],dep[300001];
void dfs(int now){
    fa[now][0]=pre[now];
    val[now][0]=pre_len[now];
    for(int i=1;i<20;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
        val[now][i]=max(val[now][i-1],val[fa[now][i-1]][i-1]);
    }
    for(auto to:v[now]){
        if(to==pre[now])continue;
        dep[to]=dep[now]+1;
        dfs(to);
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int i=19;i>=0;i--){
        if(dep[fa[a][i]]>=dep[b]){
            a=fa[a][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(fa[a][i]!=fa[b][i]){
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}
int solve(int a,int b){
    int ans=-1;
    for(int i=19;i>=0;i--){
        if(dep[fa[a][i]]>dep[b]){
            ans=max(ans,val[a][i]);
            a=fa[a][i];
        }
    }
    if(a!=b){
        ans=max(ans,val[a][0]);
    }
    return ans;
}
int main(){
    //freopen("graph.in","r",stdin);
    //freopen("graph.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    memset(dis,0x3f,sizeof(dis));
    memset(pre_len,0x3f,sizeof(pre_len));
    for(int i=1;i<=n;i++){
        if(!vis[i])dij(i);
    }
    for(int i=1;i<=n;i++){
        v[pre[i]].push_back(i);
    }
    /*for(int i=0;i<=n;i++){
        cout<<i<<":";
        for(auto to:v[i]){
            cout<<to<<" ";
        }
        cout<<endl;
    }*/
    dfs(0);
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int tmp=lca(a,b),ans=-1;
        ans=max(ans,solve(a,tmp));
        ans=max(ans,solve(b,tmp));
        if(ans<1e9)
        printf("%d\n",ans);
        else
        puts("-1");
    }
    return 0;
}
