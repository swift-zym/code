//
// Created by swift on 2020/7/22.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[50001],ans[50001],nxt[200001],to[200001],len[200001],cnt,vis[50001];
queue<int>q;
void SPFA(){
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=nxt[i]){
            if(max(ans[now],len[i])<ans[to[i]]){
                ans[to[i]]=max(ans[now],len[i]);
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
}
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
    len[cnt]=l;
}
struct edge{
    int a,b,x;
    bool operator <(const edge &t)const{
        return x<t.x;
    }
}a[100001];
int n,m;
struct fra{
    int x,y;
    bool operator <(const fra &t)const{
        return x*t.y<y*t.x;
    }
    void check(){
        int g=__gcd(x,y);
        x/=g;y/=g;
    }
    void print(){
        if(y==1){
            printf("%lld\n",x);
        }
        else{
            printf("%lld/%lld",x,y);
        }
    }
}mi;
int s,t;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].x);
    }
    scanf("%lld%lld",&s,&t);
    memset(ans,0x3f,sizeof(ans));
    ans[s]=0;
    sort(a+1,a+m+1);
    mi={100000,1};
    for(int i=m;i>=1;i--){
        add(a[i].a,a[i].b,a[i].x);
        add(a[i].b,a[i].a,a[i].x);
        q.push(a[i].a);q.push(a[i].b);
        vis[a[i].a]=vis[a[i].b]=1;
        SPFA();
        //cout<<a[i].x<<" "<<ans[t]<<endl;
        if(ans[t]<=1e16) {
            fra tmp = {ans[t],a[i].x};
            tmp.check();
            if (tmp < mi) {
                mi.x = tmp.x;
                mi.y = tmp.y;
            }
        }
    }
    if(mi.x==100000)
    puts("IMPOSSIBLE");
    else
    mi.print();
    return 0;
}