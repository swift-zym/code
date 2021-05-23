#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return ans;
}
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
inline void print(int x){
     if(x<0) putchar('-'),x=-x;
     if(x>9) print(x/10);
     putchar(x%10+'0');
}
signed main(){
    int T=read();
    while(T--){
        int a=read(),b=read(),h=read();
        if(!h){
            print(a);
            putchar(10);
            continue;
        }
        if(a<=b){
            print(qpow(b,h)*a%MOD);
            putchar(10);
        }
        else{
            int num=b>1?(qpow(b,h)-1)*qpow(b-1,MOD-2)%MOD:h;
            int ans=num*abs(a-b);
            print((ans+qpow(b,h)*a)%MOD);
            putchar(10);
        }
    }
    return 0;
}
/*
3
100 200 300
*/
//14 41 142