#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
using namespace std;
struct node{
    int ls,rs,sum,siz;
}v[4000000];
int tot;
int push_back(int aa,int bb,int cc,int dd){
    v[tot]={aa,bb,cc,dd};
    return tot++;
}
//struct tree{
    void pushup(int now){
        v[now].sum=0;v[now].siz=0;
        if(v[now].ls!=-1)v[now].sum+=v[v[now].ls].sum;
        if(v[now].rs!=-1)v[now].sum+=v[v[now].rs].sum;
        if(v[now].ls!=-1)v[now].siz+=v[v[now].ls].siz;
        if(v[now].rs!=-1)v[now].siz+=v[v[now].rs].siz;
    }
    int build(int maxn){
        return push_back(-1,-1,0,0);
    }
    void insert(int l,int r,int now,int pos){
        if(l==r){
            v[now].sum+=l;v[now].siz++;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid){
            v[now].ls=push_back(-1,-1,0,0);
            insert(l,mid,v[now].ls,pos);
        }
        else{
            v[now].rs=push_back(-1,-1,0,0);
            insert(mid+1,r,v[now].rs,pos);
        }
        pushup(now);
    }
    int query(int l,int r,int now,int k){
        //cout<<now<<" "<<k<<" "<<v[now].l<<" "<<v[now].r<<endl;
        if(l==r){
            return k*l;
        }
        if(k==v[now].siz){return v[now].sum;}
        int rsiz=v[now].rs==-1?0:v[v[now].rs].siz;
        //cout<<">"<<rsiz<<endl;
        //cout<<">"<<v[now].ls<<" "<<v[now].rs<<endl;
        //system("pause");
        int mid=(l+r)/2;
        if(rsiz>=k){
            return query(mid+1,r,v[now].rs,k);
        }
        else{
            int sum=0;
            sum+=query(l,mid,v[now].ls,k-rsiz);
            if(rsiz)sum+=v[v[now].rs].sum;
            return sum;
        }
    }
//}a[100001];
int root[100001];
int mem(int now1,int now2){
    if(now1==-1)return now2;
    if(now2==-1)return now1;
    v[now1].siz+=v[now2].siz;
    v[now1].sum+=v[now2].sum;
    v[now1].ls=mem(v[now1].ls,v[now2].ls);
    v[now1].rs=mem(v[now1].rs,v[now2].rs);
    return now1;
}
int n,m,a[100001];
int head[100001],nxt[200001],to[200001],cnt;
void add(int x,int y){
    nxt[++cnt]=head[x];
    to[cnt]=y;
    head[x]=cnt;
}
vector<pair<int,int> >s[100001];
int ans[100001];
void dfs(int now,int fa){
    root[now]=build(1e9);
    insert(0,(int)1e9,root[now],a[now]);
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs(to[i],now);
        //cout<<root[now]<<">"<<root[to[i]]<<endl;
        mem(root[now],root[to[i]]);
    }
    for(auto i:s[now]){
        ans[i.second]=query(0,(int)(1e9),root[now],i.first);
    }
}
void release(std::vector<int>&v)
{
    std::vector<int>_temp;
    _temp.swap(v);
}
inline string xyz;
inline int xyz;
signed main(){
    
    //freopen("in.txt","r",stdin);
    //freopen("in.ans","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        s[x].push_back(make_pair(y,i));
    }
    dfs(1,1);
    for(int i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
    //while(1);
    return 0;
}
/*
5 3
2 4 1 3 5
1 2
2 3
2 4
3 5
3 2
2 2
1 4
*/