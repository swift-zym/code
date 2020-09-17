#include <bits/stdc++.h>
using namespace std;
struct node{
    int i,j,c,w;
    bool operator <(const node &t)const{
        return c*t.w<t.c*w;
    }
}a[1000001];
int vis[1001],cnt,w[1001];
int n,x,m;
int main() {
    scanf("%d%d%d",&n,&x,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            a[++cnt].i=i;a[cnt].j=j;
            scanf("%d",&a[cnt].c);
        }
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=cnt;i++){
        a[i].w=w[a[i].i];
    }
    sort(a+1,a+cnt+1);
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(vis[a[i].j])continue;
        if(x<a[i].w)continue;
        ans+=a[i].c;
        vis[a[i].j]=1;
        x-=a[i].w;
    }
    printf("%d\n",ans);
    return 0;
}