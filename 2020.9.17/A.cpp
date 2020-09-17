#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll inv[10000001];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int n;
int f[10000001];
int siz[10000001];
ll ans;
int cnt;
int main(){
    inv[0]=inv[1]=1;
    for(int i=2;i<=10000000;i++){
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    }
    n=read();
    for(int i=2;i<=n;i++){
        f[i]=read();
    }
    for(int i=n;i>=1;i--){
        siz[i]++;
        siz[f[i]]+=siz[i];
    }
    for(int i=1;i<=n;i++){
        ans+=inv[siz[i]];
    }
    printf("%lld\n",ans%MOD);
    return 0;
}