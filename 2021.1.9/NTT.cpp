#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 998244353
#define int long long
int n,m,idx[30000000];
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
void NTT(int *x,int len,int f){
    for(int i=0;i<len;i++){
        if(i<idx[i])swap(x[i],x[idx[i]]);
    }
    for(int mid=1;mid<len;mid<<=1){
        int bas=qpow(3,(MOD-1)/(mid<<1));
        if(f==-1)bas=qpow(bas,MOD-2);
        for(int s=0,t=(mid<<1);s<len;s+=t){
            int now=1;
            for(int k=0;k<mid;k++,now=(now*bas)%MOD){
                int a=x[s+k],b=now*x[s+mid+k]%MOD;
                x[s+k]=(a+b)%MOD;
                x[s+mid+k]=(a-b+MOD)%MOD;
            }
        }
    }
}
int a[3000000],b[3000000];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<=m;i++)scanf("%lld",&b[i]);
    int len=1,num=0;
    while(len<=n+m)len<<=1,num++;
    for(int i=0;i<len;i++){
        idx[i]=((idx[i>>1]>>1)|((i&1)<<(num-1)));
    }
    NTT(a,len,1);
    NTT(b,len,1);
    for(int i=0;i<len;i++)a[i]=(a[i]*b[i])%MOD;
    NTT(a,len,-1);
    int inv=qpow(len,MOD-2);
    for(int i=0;i<=n+m;i++){
        printf("%lld ",a[i]*inv%MOD);
    }
    puts("");
    return 0;
}