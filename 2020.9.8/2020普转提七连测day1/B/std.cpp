#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
    int x,t;
    bool operator <(const node &y)const{
        return x+t<y.x+y.t;
    }
}a[100001];
#undef int
signed main(int argc,char *argv[]){
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    #define int long long
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].t);
    }
    sort(a+1,a+n+1);
    int now=0,sum=0;
    for(int i=1;i<=n;i++){
        if(max(now,a[i].x)+sum+a[i].t<=m){
            now=max(now,a[i].x);
            sum+=a[i].t;
        }
        else{
            printf("%lld\n",i-1);
            break;
        }
    }
    return 0;
}