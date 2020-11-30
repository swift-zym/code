#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define re register
#define N 100001
#define MAX 2001
using namespace std;
typedef long long ll;
typedef double db;
const ll mod=19260817;
inline void read(re ll &ret)
{
    ret=0;re char c=getchar();re bool pd=false;
    while(!isdigit(c)){pd|=c=='-';c=getchar();}
    while(isdigit(c)){ret=(ret<<1)+(ret<<3)+(c&15);c=getchar();}
    ret=pd?-ret:ret;
    return;
}
ll n,m,q,num[N],iq[N],u[N],v[N],fa[N],cnt[N],x[N],t[N],y[N],s[N],nn[N],op[N],jc[2010001],ans[N];
multiset<ll>st[N];
bool cut[N];
inline ll find(re ll deep)
{
    return fa[deep]==deep?fa[deep]:fa[deep]=find(fa[deep]); 
}
inline ll qpow(re ll a,re ll b,re ll p)
{
    re ll ret=1;
    while(b)
    {
        if(b&1)
            ret*=a,ret%=p;
        b>>=1;
        a*=a;
        a%=mod;
    }
    return ret;
}
inline ll inv(re ll x)
{
    return qpow(x,mod-2,mod);
}
inline ll c(re ll a,re ll b)
{
    if(a<b)
        return 0;
    return jc[a]*inv(jc[b])%mod*inv(jc[a-b])%mod;
}
signed main()
{
    freopen("mc2.in","r",stdin);
    freopen("mc2.std.out","w",stdout);
    read(n);
    read(m);
    read(q);
    jc[0]=1;
    for(re int i=1;i<=2000000;i++)
        jc[i]=jc[i-1]*i%mod;
    for(re int i=1;i<=n;i++)
    {
        read(num[i]);
        read(iq[i]);
    }
    for(re int i=1;i<=m;i++)
    {
        read(u[i]);
        read(v[i]);
    }
    for(re int i=1;i<=q;i++)
    {
        read(op[i]);
        if(op[i]==1)
        {
            read(x[i]);
            read(t[i]);
            read(y[i]);
            for(re int j=1;j<=t[i];j++)
                st[x[i]].insert(y[i]);
        }
        else if(op[i]==2)
        {
            read(s[i]);
            cut[s[i]]=true;
        }
        else
        {
            read(x[i]);
            read(nn[i]);
            read(y[i]);
        }
    }
    for(re int i=1;i<=n;i++)
        fa[i]=i;
    for(re int i=1;i<=m;i++)
        if(!cut[i])
        {
            re ll r1=find(u[i]),r2=find(v[i]);
            if(r1!=r2)
                fa[r1]=r2;
        }
    for(re int i=1;i<=n;i++)
    {
        re ll f=find(i);
        if(f!=i)
        {
            if(st[f].size()<st[i].size())
                swap(st[f],st[i]);
            st[f].insert(st[i].begin(),st[i].end());
            st[i].clear();
        }
        for(re int j=1;j<=num[i];j++)
            st[f].insert(iq[i]);
    }
    for(re int i=q;i;i--)
    {
        if(op[i]==1)
        {
            re ll f=find(x[i]);
            for(re int j=1;j<=t[i];j++)
            {
                re multiset<ll>::iterator it=st[f].find(y[i]);
                if(it!=st[f].end())
                    st[f].erase(it);
            }
        }
        else if(op[i]==2)
        {
            cut[s[i]]=false;
            re ll r1=find(u[s[i]]),r2=find(v[s[i]]);
            if(r1!=r2)
            {
                fa[r1]=r2;
                if(st[r1].size()>st[r2].size())
                    swap(st[r1],st[r2]);
                st[r2].insert(st[r1].begin(),st[r1].end());
                st[r1].clear();
            }
        }
        else
        {
            re ll r=find(x[i]);
            re ll all=st[r].size(),allnum=st[r].count(y[i]);
            cerr<<all<<" "<<allnum<<endl;
            ans[i]=c(allnum,nn[i])*inv(c(all,nn[i]))%mod;
        }
    }
    for(re int i=1;i<=q;i++)
    {
        if(op[i]==3)
            printf("%lld\n",ans[i]);
    }
    exit(0);
}
