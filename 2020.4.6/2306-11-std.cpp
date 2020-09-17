#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=1e9+7;
inline ll poww(ll a,ll b,ll mod)//快速幂
{
    ll base=a,ans=1;
    while(b)
        {
          if(b&1)
             ans=(1ll*ans*base)%mod;
          base=(1ll*base*base)%mod;
          b>>=1;
        }
    return 1ll*ans;
}
inline ll read()//快读
{
    ll p=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}
    return 1ll*f*p;}
ll n,m,sum,mod,ans=1,A[19];
inline void Exgcd(ll a,ll b,ll &x,ll &y)
//扩欧用来求逆元
{
    if(!b){x=1,y=0;return ;}
    Exgcd(b,a%b,y,x);y-=a/b*x;
}
inline ll rev(ll k,ll p)
//求k在mod p下的逆元(转换一下变成正整数)
{
    if(!k)return 0;
    ll x=0,y=0,a=k,b=p;
    Exgcd(a,b,x,y);
    x=(x%b+b)%b;
    if(!x)x+=b;
    return 1ll*x;
}
inline ll mul(ll n,ll p,ll pk)
//求n!%pi^ci,pk=pi^ci
{
    if(!n)return 1;
    ll ans=1;
    for(ll i=2;i<=pk;i++)
        if(i%p)ans=ans*i%pk;
    ans=poww(ans,n/pk,pk);
    for(ll i=2;i<=n%pk;i++)
        if(i%p)ans=ans*i%pk;
    return 1ll*ans*mul(n/p,p,pk)%pk;
    //递归下去求解(n/pi)!%pi^ci
}
inline ll C(ll n,ll m,ll mod,ll p,ll pk)
//求C(n,m)%mod,其中唯一分解之后质因子为p,总乘积为pk(pi^ci)
{
    cout<<n<<" "<<m<<" "<<mod<<" "<<p<<" "<<pk<<endl;
    if(m>n)return 0;
    ll a=mul(n,p,pk),b=mul(m,p,pk),c=mul(n-m,p,pk),k=0;
    //先求一下n!%pi^ci,m!%pi^ci,(n-m)!%pi^ci
    for(ll i=n;i;i/=p)k+=i/p;
    for(ll i=m;i;i/=p)k-=i/p;
    for(ll i=n-m;i;i/=p)k-=i/p;
    //先除掉n!,m!,(n-m)!在%mod下的质因子p
    ll ans=1ll*a*rev(b,pk)%pk*rev(c,pk)%pk*poww(p,k,pk)%pk;
    //除去质因子p之后直接逆元求组合数(剩余部分)
    return 1ll*ans*(mod/pk)%mod*rev(mod/pk,pk)%mod;
    //找到逆元了再乘回去(CRT合并)
}
int main()
{
    /*这是我在做这个题的时候写的解释
    思路:不妨设sum=∑wi(i:1~m)
    题目很简单,就是要求式子:
    C(n,sum)*C(sum,w1)*C(sum-w1,w2)*...*C(wi,wi)
    但组合数要取模
    自然想到逆元和Lucas定理
    但是模数p不保证是质数,所以要用扩展Lucas
    不妨先把p唯一分解,对于每一个pi^ci都两两互质
    可以求出C(n,m)%pi^ci
    对于求这个,除掉质因子pi然后求逆元
    之后CRT一下乱搞就好啦
    */
    mod=read(),n=read(),m=read();
    for(int i=1;i<=m;i++)
        A[i]=read(),sum+=A[i];
    if(sum>n)//要送出的礼物多于有的礼物显然无解
        {
            printf("Impossible");
            return 0;
        }
    for(ll k=1;k<=m;k++)//枚举每一个人要的礼物
        {
            n-=A[k-1];
            ll now=0,x=mod;
            for(ll i=2;i<=sqrt(mod);i++)
                //找到mod的每一个质因数p
                if(!(x%i))
                 {
                      ll pk=1;
                      while(!(x%i))pk*=i,x/=i;//除掉质因数p
                      now=(now+C(n,A[k],mod,i,pk))%mod;
                      //求出C(n,A[k])%pi^ci累加
                 }
            if(x>1)now=(now+C(n,A[k],mod,x,x))%mod;
            ans=ans*now%mod;//统计答案
        }
    printf("%lld",ans);//愉快的输出答案
    return 0;
}
