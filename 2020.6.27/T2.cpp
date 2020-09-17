//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
int n;
double x,y,xx,yy;
double cx[7],cy[7];
int a[7],vis[7];
double pi=3.1415926535,r[7];
double len(double ax,double ay,double bx,double by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
double ans=1e8;
void check(){
    double tmp=0;
    for(int i=1;i<=n;i++) {
        double mi = 1e9;
        mi = min(mi, fabs(x - cx[a[i]]));
        mi = min(mi, fabs(xx - cx[a[i]]));
        mi = min(mi, fabs(y - cy[a[i]]));
        mi = min(mi, fabs(yy - cy[a[i]]));
        for(int j=1;j<i;j++) {
            mi = min(mi, len(cx[a[i]], cy[a[i]], cx[a[j]], cy[a[j]]) - r[a[j]]);
        }
        if(mi<0)continue;
        r[a[i]]=mi;
        tmp+=pi*mi*mi;
    }
    ans=min(ans,fabs(xx-x)*fabs(yy-y)-tmp);
}
void dfs(int deep){
    if(deep==n+1){check();return;}
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a[deep]=i;
            dfs(deep+1);
            vis[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    scanf("%lf%lf%lf%lf",&x,&y,&xx,&yy);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&cx[i],&cy[i]);
    }
    dfs(1);
    printf("%0.0lf\n",ans);
    return 0;
}