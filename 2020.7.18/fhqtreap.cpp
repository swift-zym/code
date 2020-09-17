#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[410000],nxt[410000],to[410000],cnt;
void addE(int a,int b){
    //cout<<a<<" "<<b<<endl;
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int top[410000],ma1[410000],ma2[410000],siz[410000],son[410000],T,dep[410000],fat[410000];
void dfs1(int now,int fa,int deep){
    fat[now]=fa;
    dep[now]=deep;
    siz[now]=1;
    int mx=0;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs1(to[i],now,deep+1);
        siz[now]+=siz[to[i]];
        if(siz[to[i]]>siz[mx])mx=to[i];
    }
    son[now]=mx;
}
void dfs2(int tp,int now,int fa){
    ma1[now]=++T;
    ma2[T]=now;
    if(son[now])
        dfs2(tp,son[now],now);
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa||to[i]==son[now])continue;
        dfs2(to[i],to[i],now);
    }
    top[now]=tp;
}
struct bcj{
    int fa[410000];
    void init(){
        for(int i=1;i<=405000;i++)fa[i]=i;
    }
    int gf(int now){
        if(fa[now]==now)return now;
        return fa[now]=gf(fa[now]);
    }
}bc;
int n,m;
struct query{
    int id,x,y;
}q[100001];
struct seg{
    int a[410000];
    int ask(int now,int pos){
        int sum=0;
        for(int i=pos;i;i-=i&-i){
            sum+=a[i];
        }
        return sum;
    }
    void add(int now,int l,int r,int v){
        for(int i=l;i<=n;i+=i&-i){
            a[i]+=v;
        }
        for(int i=r+1;i<=n;i+=i&-i){
            a[i]-=v;
        }
    }
}base;
void add(int x,int y,int v){
    //cout<<v<<endl;
    while(top[x]!=top[y]){
        if(dep[x]<dep[y])swap(x,y);
        //cout<<top[x]<<" "<<x<<endl;
        base.add(1,ma1[top[x]],ma1[x],v);
        x=fat[top[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    //cout<<x<<" "<<y<<endl;
    base.add(1,ma1[y],ma1[x],v);
}
int getSiz(int x){
    return base.ask(1,ma1[x]);
}
signed main(){
    scanf("%lld%lld",&n,&m);
    bc.init();
    for(int i=1;i<=m;i++){
        char c=getchar();
        while(c!='A'&&c!='Q')c=getchar();
        q[i].id=(c=='Q');
        scanf("%lld%lld",&q[i].x,&q[i].y);
        if(q[i].id==0){
            addE(q[i].x,q[i].y);
            addE(q[i].y,q[i].x);
            bc.fa[bc.gf(q[i].y)]=bc.gf(q[i].x);
        }
    }
    for(int i=1;i<=n;i++){
        if(bc.gf(i)==i){
            addE(i,n+1);
            addE(n+1,i);
        }
    }
    n++;
    base.add(1,1,n,1);
    bc.init();
    dfs1(n,n,1);
    dfs2(n,n,n);
    for(int i=1;i<=m;i++){
        if(dep[q[i].x]>dep[q[i].y]){
            swap(q[i].x,q[i].y);
        }
        if(q[i].id==0){
            //cout<<"#"<<q[i].x<<" "<<q[i].y<<" "<<i<<endl;
            //cout<<"#ADD#"<<bc.gf(q[i].x)<<"#"<<q[i].x<<endl;
            add(bc.gf(q[i].x),q[i].x,getSiz(q[i].y));
            bc.fa[bc.gf(q[i].y)]=bc.gf(q[i].x);
        }
        else{
            int sx=getSiz(bc.gf(q[i].x)),sy=getSiz(q[i].y);
            printf("%lld\n",(sx-sy)*sy);
        }
    }
    return 0;
}