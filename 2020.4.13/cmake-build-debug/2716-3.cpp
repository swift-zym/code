#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t[5000001],tt[5000001];
void add(int now,int vaule){
    for(;now<=n;now+=(now&-now)){
        t[now]+=vaule;
    }
}
int ask(int now){
    int sum=0;
    for(;now;now-=(now&-now)){
        sum+=t[now];
    }
    return sum;
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%lld",&a);
        tt[i]=a;
        add(i,a);
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++) {
        char pos = getchar();
        while (pos != 'C' && pos != 'Q')pos = getchar();
        int x, y;
        scanf("%lld%lld", &x, &y);
        if (pos == 'C') {
            add(x, -t[x]);
            t[x] = y;
            add(x, t[x]);
        } else { 
            printf("%lld\n", ask(y) - ask(x - 1));
        }
    }
    return 0;

}
//