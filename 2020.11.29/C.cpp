#include<iostream>
#define N 2000
#define int long long
using namespace std;
int p,a[10000],ans[10000];
int jc[10000],inv[10000],jcinv[10000];
int bas[10000000];
void prepare(){
    jc[0]=inv[0]=jcinv[0]=1;
    jc[1]=inv[1]=jcinv[1]=1;
    for(int i=2;i<=N;i++){
        jc[i]=jc[i-1]*i%p;
        inv[i]=(p-p/i)*inv[p%i]%p;
        jcinv[i]=jcinv[i-1]*inv[i]%p;
    }
    bas[0]=1;
    for(int i=1;i<=N*N;i++){
        bas[i]=bas[i-1]*2%p;
    }
}
int C(int m,int n){
    return jc[m]*jcinv[n]%p*jcinv[m-n]%p;
}
void solveA047863(){
    for(int i=0;i<=N;i++){
        for(int k=0;k<=i;k++){
            a[i]+=C(i,k)*bas[k*(i-k)]%p;
            a[i]%=p;
        }
    }
}
void solve(){
    for(int i=0;i<=N;i++)
    for(int k=0;k<=i;k++){
        ans[i]+=C(i,k)*bas[k*(i-k)]%p*a[k]%p;
        ans[i]%=p;
    }
}
signed main(){
    int T;
    scanf("%lld%lld",&T,&p);
    prepare();
    solveA047863();
    solve();
    while(T--){
        int n;
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}