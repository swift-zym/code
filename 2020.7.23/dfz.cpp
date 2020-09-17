//
// Created by swift on 2020/7/23.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,cnt,head[40001],nxt[80001],to[80001],len[80001];
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
int rt,siz[40001],dep[40001],vis[40001],mi,id,all;
int t[40001];
void add(int now,int v){
    //cout<<"add  "<<now<<" "<<v<<endl;
    for(int i=now;i<=k;i+=i&-i){
        //cout<<":"<<i<<endl;
        t[i]+=v;
    }
}
int ask(int now){
    //cout<<"query "<<now<<endl;
    int v=0;
    for(int i=now;i;i-=i&-i){
        //cout<<":"<<i<<endl;
        v+=t[i];
    }
    return v;
}
void getRoot(int now,int fa){
    siz[now]=1;
    int nmi=0;
    for(int i=head[now];i;i=nxt[i]){
        if(vis[to[i]]||to[i]==fa)continue;
        getRoot(to[i],now);
        siz[now]+=siz[to[i]];
        nmi=max(nmi,siz[to[i]]);
    }
    nmi=max(nmi,all-siz[now]);
    if(nmi<mi){
        mi=nmi;
        rt=now;
    }
}
int s[40001],tp;
int ans;
void getAnswer(int now,int fa){
    if(dep[now]<=k){
        //cout<<now<<endl;
        ans++;
        //cout<<"+="<<ask(k-dep[now])<<endl;
        ans+=ask(k-dep[now]);
        s[++tp]=now;
    }
    //siz[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(vis[to[i]]||to[i]==fa)continue;;
        dep[to[i]]=dep[now]+len[i];
        getAnswer(to[i],now);
        //siz[now]+=siz[to[i]];
    }
}
void solve(int now,int fa){
    //cout<<">"<<now<<endl;
    vis[now]=1;tp=0;
    for(int i=head[now];i;i=nxt[i]){
        if(vis[to[i]])continue;
        //cout<<">>"<<to[i]<<endl;
        int bef=tp;
        dep[to[i]]=len[i];
        getAnswer(to[i],now);
        for(int j=bef+1;j<=tp;j++){
            add(dep[s[j]],1);
        }
    }
    for(int i=1;i<=tp;i++){
        add(dep[s[i]],-1);
    }
    tp=0;
    for(int i=head[now];i;i=nxt[i]){
        if(vis[to[i]])continue;
        rt=0;mi=1e8;
        all=siz[to[i]];
        getRoot(to[i],to[i]);
        solve(rt,now);
    }
}
signed main(){
    scanf("%lld",&n);
    all=n;
    for(int i=1;i<n;i++){
        int a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    scanf("%lld",&k);
    rt=0;mi=1e8;
    getRoot(1,1);
    solve(rt,rt);
    printf("%lld\n",ans);
    return 0;
}