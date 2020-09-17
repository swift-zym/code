//
// Created by swift on 2020/6/26.
//

#include<bits/stdc++.h>
using namespace std;
struct edge{
    int a,b;
    double l;
    bool operator <(const edge &t)const{
        return l<t.l;
    }
}a[1000000];
struct node{
    double x,y;
}tmp[1000];
double sol(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int f[1000];
int gf(int now){
    if(f[now]==now)return now;
    int fa=gf(f[now]);
    f[now]=fa;
    return fa;
}
int s,p,cnt;
int main(){
    scanf("%d%d",&p,&s);
    for(int i=1;i<=p;i++){
        f[i]=i;
        scanf("%lf%lf",&tmp[i].x,&tmp[i].y);
    }
    for(int i=1;i<=p;i++)
        for(int j=i+1;j<=p;j++){
            a[++cnt].a=i;
            a[cnt].b=j;
            a[cnt].l=sol(tmp[i],tmp[j]);
        }
    sort(a+1,a+cnt+1);
    int num=0;
    double len=0;
    for(int i=1;i<=cnt&&num<p-s;i++){
        int x=gf(a[i].a),y=gf(a[i].b);
        if(x!=y){
            num++;
            f[x]=y;
            len=a[i].l;
        }
    }
    printf("%0.2lf\n",len);
    return 0;
}