#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,q;
struct node{
    int x,v;
    bool operator <(const node &t)const{
        return v>t.v;
    }
};
struct edge{
    int s,t,v;
    bool operator <(const edge &t)const{
        return v<t.v;
    }
};
vector<edge>e;
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
int f[300001];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
vector<pair<int,int> >vv[300001];
void dfss(int now,int fa){
    v[fa].push_back(now);
    vis[now]=1;
    for(auto i:vv[now]){
        if(i.first==fa)continue;
        pre_len[i.first]=i.second;
        pre[i.first]=now;
        dfss(i.first,now);
    }
}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
        e.push_back({a,b,l});
    }
    for(int i=1;i<=n;i++)f[i]=i;
    sort(e.begin(),e.end());
    memset(dis,0x3f,sizeof(dis));
    memset(pre_len,0x3f,sizeof(pre_len));
    for(int i=0;i<m;i++){
        if(gf(e[i].s)!=gf(e[i].t)){
            vv[e[i].s].push_back(make_pair(e[i].t,e[i].v));
            vv[e[i].t].push_back(make_pair(e[i].s,e[i].v));
            f[gf(e[i].s)]=e[i].t;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            pre[i]=0;
            pre_len[i]=1e9;
            dfss(i,0);
        }
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
