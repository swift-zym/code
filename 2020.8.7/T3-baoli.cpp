//
// Created by swift on 2020/8/8.
//

#include<bits/stdc++.h>
#include<cstdio>
#define N 2001001
#define MAX 2001
#define int long long
#define re register
#define inf 1e18
using namespace std;
typedef long long ll;
typedef double db;
const ll mod=1e18;
inline void read(re ll &ret)
{
    ret=0;re char c=getchar();re bool pd=false;
    while(!isdigit(c)){pd|=c=='-';c=getchar();}
    while(isdigit(c)){ret=(ret<<1)+(ret<<3)+(c&15);c=getchar();}
    ret=pd?-ret:ret;
    return;
}
ll n,a[N],num[N],q,m,ans;
signed main()
{
    freopen("3.in","r",stdin);
    freopen("3.ans","w",stdout);
    read(n);
    for(re int i=1;i<=n;i++)
    {
        read(a[i]);
        for(re int j=0;j<=60;j++)
        {
            re bool tmp=((1ll<<j)&a[i]);
            num[j]+=tmp;
        }
    }
    read(q);
    for(re int i=1;i<=q;i++)
    {
        read(m);
        re ll tmp=0;
        re bool flag=false;
        for(re int j=10000;j>=0;j--)
        {
            tmp=0;
            for(re int k=1;k<=n;k++)
            {
                tmp+=j^a[k];
            }
            if(tmp<=m)
            {
                cout<<j<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            puts("-1");
    }
    exit(0);
}