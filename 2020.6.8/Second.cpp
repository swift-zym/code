#include<bits/stdc++.h>
using namespace std;
int head[200001],nxt[400001],to[400001],cnt;
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int c[200001],va[200001],vb[200001];
int x[200001],y[200001];
int n;
void dfs(int now,int tmp){
    c[now]=tmp;
    for(int i=head[now];i;i=nxt[i]){
        if(c[to[i]]==-1){
            dfs(to[i],1-tmp);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)c[i]=-1;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
            va[x[i]]=va[y[i]]=0;
            vb[x[i]]=vb[y[i]]=0;
            head[i]=0;
        }
        for(int i=1;i<=n;i++){
            int a=x[i],b=y[i];
            if(va[a]){
                add(i,va[a]);add(va[a],i);va[a]=0;
            }
            else{
                va[a]=i;
            }
            if(vb[b]){
                add(i,vb[b]);add(vb[b],i);vb[b]=0;
            }
            else{
                vb[b]=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i]==-1){
                dfs(i,0);
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i]){
                putchar('r');
            }
            else{
                putchar('b');
            }
        }
        putchar(10);
    }
    return 0;
}