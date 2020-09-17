#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    double x,y;
}a[1001];
int cnt;
struct edge{
    int x,y;
    double l;
    bool operator<(const edge &e)const{
        return l<e.l;
    }
}b[1100000];
double len(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int f[1001];
int gf(int now){
    return f[now]==now?now:f[now]=gf(f[now]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i==j)continue;
        cnt++;
        b[cnt].x=i;
        b[cnt].y=j;
        b[cnt].l=len(a[i],a[j]);
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        b[++cnt]={x,y,0};
    }
    sort(b+1,b+cnt+1);
    for(int i=1;i<=n;i++)f[i]=i;
    double ans;
    int num=n-1;
    for(int i=1;i<=cnt&&num;i++){
        int x=b[i].x,y=b[i].y;
        double l=b[i].l;
        x=gf(x);y=gf(y);
        if(x!=y){
            num--;
            f[x]=y;
            ans+=l;
        }
    }
    //ans+=0.005;
    printf("%0.2lf\n",ans);
    return 0;
}