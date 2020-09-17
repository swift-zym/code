//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
using namespace std;
struct edge{
    int s,t,l,a;
    bool operator <(const edge &t)const{
        return a>t.a;
    }
}e[400001];
int T,n,m;
int head[400001],nxt[800001],to[800001],len[800001],cnt,dis[400001];
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
struct heap{
    int x,v;
    bool operator <(const heap &t)const{
        return v>t.v;
    }
};
int vis[400001];
priority_queue<heap>p;
int f[400001];
int gf(int now){
    if(f[now]==now)return f[now];
    return f[now]=gf(f[now]);
}
int tot,val[400001],ff[400001][21];
vector<int>v[400001];
void dfs(int now){
    for(int i=0;i<v[now].size();i++){
        dfs(v[now][i]);
        dis[now]=min(dis[now],dis[v[now][i]]);
    }
}
int main(){
    //freopen("return5.in","r",stdin);
    //freopen("return5.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        cnt=0;
        memset(head,0,sizeof(head));
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&e[i].s,&e[i].t,&e[i].l,&e[i].a);
            add(e[i].s,e[i].t,e[i].l);
            add(e[i].t,e[i].s,e[i].l);
        }
        tot=n;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[1]=0;
        p.push({1,0});
        while(!p.empty()){
            heap now=p.top();p.pop();
            //cout<<now.x<<","<<now.v<<endl;
            if(vis[now.x])continue;;
            vis[now.x]=1;
            for(int i=head[now.x];i;i=nxt[i]){
                if(vis[to[i]])continue;
                if(dis[to[i]]>dis[now.x]+len[i]){
                    dis[to[i]]=dis[now.x]+len[i];
                    p.push({to[i],dis[to[i]]});
                }
            }
        }
        sort(e+1,e+m+1);
        for(int i=1;i<=2*n;i++)f[i]=i,v[i].clear();
        int num=n-1;
        memset(ff,0,sizeof(ff));
        for(int i=1;i<=m;i++){
            if(!num)break;
            int fx=gf(e[i].s),fy=gf(e[i].t);
            if(fx!=fy){
                num--;
                tot++;
                f[fx]=f[fy]=tot;
                v[tot].push_back(fx);
                v[tot].push_back(fy);
                //cout<<tot<<"->"<<fx<<endl;
                //cout<<tot<<"->"<<fy<<endl;
                ff[fx][0]=tot;
                ff[fy][0]=tot;
                val[tot]=e[i].a;
            }
        }
        ff[tot][0]=tot;
        //cout<<"tot="<<tot<<endl;
        for(int i=1;i<=20;i++)
            for(int j=1;j<=tot;j++){
                ff[j][i]=ff[ff[j][i-1]][i-1];
            }
        dfs(tot);
        int q,k,s;
        scanf("%d%d%d",&q,&k,&s);
        int lastans=0;
        for(int i=1;i<=q;i++){
            int v,p;
            scanf("%d%d",&v,&p);
            //cout<<">"<<v<<endl;
            v=(v+k*lastans-1)%n+1;
            p=(p+k*lastans)%(s+1);
            for(int i=20;i>=0;i--){
                if(val[ff[v][i]]>p){
                    v=ff[v][i];
                }
            }
            //cout<<":"<<v<<endl;
            lastans=dis[v];
            printf("%d\n",lastans);
        }
    }

    return 0;
}