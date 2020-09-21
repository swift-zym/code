#include<bits/stdc++.h>
#define MOD 1000000009
#define int long long
using namespace std;
int a[110000],b[110000];
int t[110000];
int n;
void add(int x,int v){
    for(;x<=n+5;x+=x&-x){
        t[x]+=v;
        t[x]%=MOD;
    }
}
int query(int x){
    for(;x;x-=x&-x){
        v+=t[x];
        v%=MOD;
    }
    return v;
}
int ans;
signed main(){
    freopen("protest.in","r",stdin);
    freopen("protest.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    memcpy(a,b,sizeof(a));
    sort(a,a+n+1);
    for(int i=0;i<=n;i++){
        b[i]=lower_bound(a,a+n+1,b[i])-a+1;
    }
    add(b[0],1);
    for(int i=1;i<=n;i++){
        ans=query(b[i]);
        add(b[i],ans);
    }
    printf("%lld\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}