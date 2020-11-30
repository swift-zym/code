#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int>v[200001];
struct edge{
    int u,v,w;
};
vector<edge>e;
int n,q,dep[200001],f[200001],vis[200001],col[200001];
void dfs(int now,int fa,int deep){
    f[now]=fa;dep[now]=deep;
    for(auto to:v[now]){
        if(to==fa)continue;
        dfs(to,now,deep+1);
    }
}
void pos(int x,int y){
    memset(vis,0,sizeof(vis));
    while(dep[x]!=dep[y]){
        if(dep[x]<dep[y])swap(x,y);
        vis[x]=1;
        x=f[x];
    }
    while(x!=y){
        if(dep[x]<dep[y])swap(x,y);
        vis[x]=vis[y]=1;
        x=f[x];y=f[y];
    }
    vis[x]=1;
    return;
}
void modify(int x,int y){
    pos(x,y);
    for(auto s:e){
        if(vis[s.u]&&vis[s.v])col[s.w]=0;
        else if(vis[s.u]||vis[s.v])col[s.w]=1;
    }
}
int query(int x,int y){
    int ans=0;
    pos(x,y);
    for(auto s:e){
        if(vis[s.u]&&vis[s.v])ans+=col[s.w];
    }
    return ans;
}
namespace subtask{
    int dfn[200001];
    int val[1000000],tag[1000000];
    void pushdown(int now,int l,int r){
        if(tag[now]==-1)return;
        tag[now*2]=tag[now*2+1]=tag[now];
        int mid=(l+r)/2;
        val[now*2]=tag[now]*(mid-l+1);
        val[now*2+1]=tag[now]*(r-mid);
        tag[now]=-1;
    }
    void pushup(int now){val[now]=val[now*2]+val[now*2+1];}
    int query(int now,int l,int r,int L,int R){
        if(l==L&&r==R)return val[now];
        pushdown(now,l,r);
        int mid=(l+r)/2;
        if(R<=mid)return query(now*2,l,mid,L,R);
        else if(L>mid)return query(now*2+1,mid+1,r,L,R);
        else return query(now*2,l,mid,L,mid)+query(now*2+1,mid+1,r,mid+1,R);
    }
    void change(int now,int l,int r,int L,int R,int v){
        if(l==L&&r==R){
            val[now]=(r-l+1)*v;
            tag[now]=v;
            return;
        }
        pushdown(now,l,r);
        int mid=(l+r)/2;
        if(R<=mid)change(now*2,l,mid,L,R,v);
        else if(L>mid)change(now*2+1,mid+1,r,L,R,v);
        else{
            change(now*2,l,mid,L,mid,v);
            change(now*2+1,mid+1,r,mid+1,R,v);
        }
        pushup(now);
    }
    void solve(){
        int now;
        memset(tag,-1,sizeof(tag));
        for(int i=1;i<=n;i++){
            if(v[i].size()==1)now=i;
        }
        dfn[now]=1;
        for(int i=1;i<n;i++){
            for(auto to:v[now]){
                if(!dfn[to]){
                    dfn[to]=dfn[now]+1;
                    now=to;
                    break;
                }
            }
        }
        change(1,1,n,1,n,1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int t,a,b;
            scanf("%d%d%d",&t,&a,&b);
            a=dfn[a];b=dfn[b];
            if(a>b)swap(a,b);
            if(t==0){
                if(a!=b)
                printf("%d\n",query(1,1,n,a,b-1));
                else
                puts("0");
            }
            else{
                if(a!=b)
                change(1,1,n,a,b-1,0);
                change(1,1,n,b,b,1);
                if(a-1)change(1,1,n,a-1,a-1,1);
            }
        }
    }
};
namespace subtask2{
    int pre[200001][21];
    void dfs(int now){
        pre[now][0]=f[now];
        for(int i=1;i<=20;i++){
            pre[now][i]=pre[pre[now][i-1]][i-1];
        }
        for(auto to:v[now]){
            if(!pre[to][0])dfs(to);
        }
    }
    int lca(int a,int b){
        if(dep[a]<dep[b])swap(a,b);
        for(int i=20;i>=0;i--){
            if(dep[pre[a][i]]>=dep[b]){
                a=pre[a][i];
            }
        }
        if(a==b)return a;
        for(int i=20;i>=0;i--){
            if(pre[a][i]!=pre[b][i]){
                a=pre[a][i];
                b=pre[b][i];
            }
        }
        return pre[a][0];
    }
    void solve(){
        dfs(1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int t,a,b;
            scanf("%d%d%d",&t,&a,&b);
            if(t==0){
                printf("%d\n",dep[a]+dep[b]-dep[lca(a,b)]*2);
            }
        }
    }
}
int main(){
    freopen("colour.in","r",stdin);
    freopen("colour.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);v[b].push_back(a);
        e.push_back({a,b,i});
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()!=2){
            if(v[i].size()==1)
            num++;
            else
            num=-1;
        }
    }
    fill(col+1,col+n,1);
    dfs(1,1,1);
    if(num==2){
        subtask::solve();
        return 0;
    }
    if(true||n>2000){
        subtask2::solve();
        return 0;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t==0)printf("%d\n",query(a,b));
        else modify(a,b);
    }
    return 0;
}