//
// Created by swift on 2020/7/22.
//

#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll n,m,i,j,a[1000001],b[1000001],minn=1e15,l,r;
bool f=false,ff=false;
struct sequence
{
    ll x,y;
}c[1000001];
bool cmp(sequence qwe,sequence rty)
{
    return qwe.y<rty.y;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
//  freopen("sequence7.in","r",stdin);
//  freopen("seq.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=b[i-1]+a[i];
        c[i].y=c[i-1].y+a[i];
        c[i].x=i;
        if(abs(a[i])&1)
        {
            f=true;
        }
        else
        {
            ff=true;
        }
    }
/*  if(n<=10000)
    {
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(minn>b[j]-b[i-1]&&b[j]-b[i-1]>=1&&(b[j]-b[i-1])&1)
                {
                    minn=b[j]-b[i-1];
                    l=i;
                    r=j;
                }
            }
        }
        if(minn==1e15)
        {
            cout<<-1;
            return 0;
        }
        printf("%lld %lld %lld",minn,l,r);
        return 0;
    }*/
    sort(c+1,c+n+1,cmp);
    if(!f||!ff)
    {
        cout<<-1;
        return 0;
    }
/*  for(i=1;i<=n;i++)
    {
        printf("c[%lld].x=%lld ",i,c[i].x);
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("c[%lld].y=%lld ",i,c[i].y);
    }*/
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(c[j].y-c[i-1].y>minn)
            {
                break;
            }
            if(c[j].x>c[i-1].x&&(c[j].y-c[i-1].y)&1&&(c[j].y-c[i-1].y)>0&&c[j].y-c[i-1].y<minn)
            {
                minn=min(minn,c[j].y-c[i-1].y);
                l=c[i-1].x+1;
                r=c[j].x;
            }
        }
    }
    if(minn==1e15)
    {
        cout<<-1;
        return 0;
    }
    cout<<minn<<" "<<l<<" "<<r;
    return 0;
}