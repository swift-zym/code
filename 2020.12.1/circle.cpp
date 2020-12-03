#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<ctime>
#include<set>
using namespace std;
typedef long long ll;
#define N 1010005
const int p=1e9+7;
int n;
ll v[N],w[N],nv[N];
int dp[100002],pp[100002];
inline void rd(ll &x)
{
    x=0;register char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
}
int main()
{freopen("data.in","r",stdin);freopen("user.out","w",stdout);
    scanf("%d",&n);ll mxv=0;
    for(int i=1;i<=n;i++)rd(v[i]),rd(w[i]),mxv=max(mxv,v[i]);
    if(n<=50&&mxv<=50)
    {
        int ans=1e9;
        for(int sv=0;sv<=v[1];sv++)
        {
            for(int i=0;i<=v[1];i++)dp[i]=1e9;
            dp[v[1]]=0;
            for(int i=2;i<=n;i++)
            {
                for(int j=0;j<=v[1];j++)pp[j]=1e9;
                if(v[i]<=sv)continue;
                int nd=w[i]+1-v[i];
                for(int j=0;j+nd<=v[1];j++)pp[j]=min(pp[j],dp[j+nd]);
                for(int j=0;j<=v[1];j++)pp[j]=min(pp[j],dp[j]+1);
                for(int j=0;j<=v[1];j++)dp[j]=pp[j];
            }
            int mn=1e9;
            for(int i=sv;i<=v[1];i++)mn=min(mn,dp[i]);
            ans=min(ans,mn);
        }
        printf("%d\n",ans+1);return 0;
    }
    if(n<=20)
    {
        int ans=1e9;
        for(int i=0;i<(1<<(n-1));i++)
        {
            bool flag=true;
            for(int j=1;j<=n;j++)nv[j]=v[j];
            for(int j=2;j<=n;j++)if(i&(1<<(j-2)))
            {
                int nd=w[j]+1-v[j];
                if(nv[1]<nd){flag=false;break;}
                nv[1]-=nd;nv[j]=0;
            }
            if(!flag)continue;
            int sum=0;
            for(int j=2;j<=n;j++)if(nv[j]>nv[1])sum++;
            ans=min(ans,sum);
        }
        printf("%d\n",ans+1);
    }
}
/*
8
20 1000
32 37
40 1000
45 50
16 16
16 16
14 1000
2 1000
*/