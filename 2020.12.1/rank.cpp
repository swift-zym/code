#include<bits/stdc++.h>
#define int long long
using namespace std;
struct team{
    int a,b;
    bool operator <(const team &c)const{
        if(b-a!=c.b-c.a)
        return b-a<c.b-c.a;
        return a>c.a;
    }
}c[300001];
int n,x,y,ans;
int check(){
    int rnk=0;
    for(int i=1;i<=n;i++){
        if(c[i].a>x)rnk++;
    }
    return rnk+1;
}
signed main(){
    freopen("rank.in","r",stdin);
    freopen("rank.txt","w",stdout);
    scanf("%lld",&n);
    scanf("%lld%lld",&x,&y);
    n--;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&c[i].a,&c[i].b);
    }
    sort(c+1,c+n+1);
    ans=check();
    for(int i=1;i<=n;i++){
        if(c[i].b-c[i].a<x){
            x-=c[i].b-c[i].a+1;
            c[i].a=0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}