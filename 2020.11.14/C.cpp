#include<bits/stdc++.h>
using namespace std;
struct node{
    int ls,rs,v,tag;
}a[20000000];
int tot;
int newNode(){
    tot++;
    a[tot]={-1,-1,INT_MAX,0};
    return tot;
}
void pushdown(int now){
    if(!a[now].tag)return;
    if(a[now].ls==-1)a[now].ls=newNode();
    if(a[now].rs==-1)a[now].rs=newNode();
    a[a[now].ls].tag=a[a[now].rs].tag=a[now].tag;
    a[a[now].ls].v=a[a[now].rs].v=a[now].tag;
    a[now].tag=0;
}
void pushup(int now){
    a[now].v=INT_MAX;
    if(a[now].ls!=-1)a[now].v=min(a[now].v,a[a[now].ls].v);
    if(a[now].rs!=-1)a[now].v=min(a[now].v,a[a[now].rs].v);
}
int query(int now,int L,int R,int l,int r){
    int mid=(L+R)/2;
    //cout<<L<<" "<<R<<" "<<l<<" "<<r<<" "<<a[now].v<<endl;
    if(L==l&&R==r)return a[now].v;
    pushdown(now);
    if(r<=mid){
        return a[now].ls==-1?INT_MAX:query(a[now].ls,L,mid,l,r);
    }
    else if(l>mid){
        return a[now].rs==-1?INT_MAX:query(a[now].rs,mid+1,R,l,r);
    }
    else{
        int tmp=INT_MAX;
        tmp=min(tmp,a[now].ls==-1?INT_MAX:query(a[now].ls,L,mid,l,mid));
        tmp=min(tmp,a[now].rs==-1?INT_MAX:query(a[now].rs,mid+1,R,mid+1,r));
        return tmp;
    }
}
void change(int now,int L,int R,int l,int r,int v){
    int mid=(L+R)/2;
    if(L==l&&R==r){
        a[now].tag=a[now].v=v;
        return;
    }
    pushdown(now);
    if(r<=mid){
        if(a[now].ls==-1)a[now].ls=newNode();
        change(a[now].ls,L,mid,l,r,v);
    }
    else if(l>mid){
        if(a[now].rs==-1)a[now].rs=newNode();
        change(a[now].rs,mid+1,R,l,r,v);
    }
    else{
        if(a[now].ls==-1)a[now].ls=newNode();
        if(a[now].rs==-1)a[now].rs=newNode();
        change(a[now].ls,L,mid,l,mid,v);
        change(a[now].rs,mid+1,R,mid+1,r,v);
    }
    pushup(now);
}
int merge(int x,int y){
    if(x==-1)return y;
    if(y==-1)return x;
    a[x].v=min(a[x].v,a[y].v);
    a[x].tag=max(a[x].tag,a[y].tag);
    a[x].ls=merge(a[x].ls,a[y].ls);
    a[x].rs=merge(a[x].rs,a[y].rs);
    return x;
}
int mp[100001],dfn[100001],siz[100001];
int tim;
int n,m;
vector<int>v[100001];
vector<pair<int,int> >vv[100001];
void dfss(int now,int fa){
    //cerr<<now<<endl;
    tim++;
    mp[tim]=now;
    siz[now]=1;
    dfn[now]=tim;
    for(auto to:v[now]){
        if(to==fa)continue;
        dfss(to,now);
        siz[now]+=siz[to];
    }
}
struct Query{
  int s,t,id;  
};
int ans[100001];
vector<Query>q;
int dfs(int now,int fa){
    //cerr<<now<<endl;
    int id=newNode();
    for(auto i:vv[now]){
        if(query(id,1,n,dfn[i.first],dfn[i.first])>i.second){
            //cout<<"change "<<i.first<<" to "<<i.second<<endl;
            change(id,1,n,dfn[i.first],dfn[i.first],i.second);
        }
    }
    //cout<<query(id,1,n,1,n)<<endl;
    for(auto to:v[now]){
        if(to==fa)continue;
        int idd=dfs(to,now);
        id=merge(id,idd);
    }
    change(id,1,n,dfn[now],dfn[now]+siz[now]-1,INT_MAX);
    /*cout<<"set "<<dfn[now]<<" to "<<dfn[now]+siz[now]-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<query(id,1,n,i,i)<<endl;
    }*/
    ans[now]=query(id,1,n,1,n);
    return id;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        q.push_back({x,y,0});
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        vv[x].push_back(make_pair(y,z));
        vv[y].push_back(make_pair(x,z));
    }
    dfss(1,1);
    dfs(1,1);
    for(auto i:q){
        if(siz[i.s]<siz[i.t]){
            printf("%d\n",ans[i.s]==INT_MAX?-1:ans[i.s]);
        }
        else{
            printf("%d\n",ans[i.t]==INT_MAX?-1:ans[i.t]);
        }
    }
    return 0;
}