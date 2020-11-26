#include<iostream>
#include<cstring>
#define MOD 19260817
#define int long long
using namespace std;
int n,m,q;
int num[1000][1000];
int jc[2000000];
int qpow(int a,int b){
    if(!b)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int C(int m,int n){
    if(m<n)return 0;
    return jc[m]*qpow(jc[n],MOD-2)%MOD*qpow(jc[m-n],MOD-2)%MOD;
}
int head[1000],nxt[1000],to[1000],vis[1000],cnt;
int added[1000];
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int tot,cur;
void dfs(int now,int v){
    for(int i=0;i<=n;i++){
        tot+=num[now][i];
    }
    cur+=num[now][v];
    added[now]=1;
    for(int i=head[now];i;i=nxt[i]){
        if(vis[i]||added[to[i]])continue;
        dfs(to[i],v);
    }
}
signed main(){
    freopen("mc.in","r",stdin);
    freopen("mc.out","w",stdout);
    jc[0]=1;
    for(int i=1;i<=1000000;i++){
        jc[i]=jc[i-1]*i%MOD;
    }
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        num[i][b]+=a;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=q;i++){
        int opt;
        scanf("%lld",&opt);
        if(opt==1){
            int a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            num[a][c]+=b;
        }
        else if(opt==2){
            int a;
            scanf("%lld",&a);
            vis[2*a]=vis[2*a-1]=1;
        } 
        else{
            tot=0;cur=0;
            memset(added,0,sizeof(added));
            int a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            dfs(a,c);
            int ans=C(cur,b)*qpow(C(tot,b),MOD-2)%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
5 5 5
5 1
9 2
8 1
8 1
6 2
5 2
1 2
2 2
1 1
5 3
1 1 3 2
2 1
3 3 4 1
3 2 3 1
3 1 2 1*/