//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,head[200001],nxt[400001],to[400001],cnt,du[200001],ma[200001],f[200001],deep[200001];
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
struct tree{
    int t[400001];
    void add(int now,int v){
        for(int i=now;i<=n;i+=i&-i){
            t[i]+=v;
        }
    }
    int ask(int now){
        int v=0;
        for(int i=now;i;i-=i&-i){
            v+=t[i];
        }
        return v;
    }
}st,ed;
void dfs(int now,int fa,int dep=0){
    f[now]=fa;
    deep[now]=dep;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs(to[i],now,dep+1);
    }
}
vector<int>v[200001];
int vis[200001];
void work(int a,int c){
    for(int i=0;i<v[a].size();i++){
        //cout<<v[a][i]<<"set 1"<<endl;
        vis[v[a][i]]=1;
    }
    v[a].push_back(c);
    //cout<<a<<" add "<<c<<endl;
}
void query(int a,int b,int c){
    if(deep[a]<deep[b])swap(a,b);
    while(deep[a]!=deep[b]){
        work(a,c);
        a=f[a];
    }
    if(a==b){
        work(a,c);
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=vis[i];
        }
        printf("%d\n",ans);
        memset(vis,0,sizeof(vis));
        return;
    }
    while(a!=b){
        work(a,c);
        work(b,c);
        a=f[a];b=f[b];
    }
    work(a,c);
    int ans=0;
    for(int i=1;i<=m;i++){
        ans+=vis[i];
    }
    memset(vis,0,sizeof(vis));
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
        du[a]+=2;
        du[b]+=2;
    }
    bool flag=1;
    int num=0,now;
    for(int i=1;i<=n;i++){
        if(du[i]!=2&&du[i]!=4)flag=0;
        if(du[i]==2)now=i,num++;
    }
    if(num!=2)flag=0;
    if(flag){
        int pre=0;
        for(int i=1;i<=n;i++){
            ma[now]=i;
            for(int j=head[now];j;j=nxt[j]){
                if(to[j]!=pre){
                    pre=now;
                    now=to[j];
                    break;
                }
            }
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(ma[a]>ma[b])swap(a,b);
            printf("%d\n",st.ask(ma[b])-ed.ask(ma[a]-1));
            st.add(ma[a],1);
            ed.add(ma[b],1);
        }
    }
    else{
        dfs(1,1);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            query(a,b,i);
        }
    }
    return 0;
}