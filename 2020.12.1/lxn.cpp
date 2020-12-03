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
#define N 210005
const int p=1e9+7;
struct node{int a,b;}c1[N],c2[N];
int n,a[N],b[N],f[20000002],finv[20000002],tot1,tot2;
int dp[9200][9200];
inline int C(int nn,int mm)
{
    if(nn<0||mm<0)return 0;
    if(nn<mm)return 0;
    return 1ll*f[nn]*finv[mm]%p*finv[nn-mm]%p;
}
inline int ksm(int d,int k)
{int ret=1;while(k){if(k&1)ret=1ll*ret*d%p;d=1ll*d*d%p;k>>=1;}return ret;}
int main()
{freopen("gift2.in","r",stdin);
    scanf("%d",&n);int mxab=0,ss=0;
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),mxab=max(mxab,max(a[i],b[i])),ss+=a[i]+b[i];
    f[0]=1;for(  int i=1;i<=20000000;i++)f[i]=1ll*f[i-1]*i%p;
    finv[20000000]=ksm(f[20000000],p-2);
    for(  int i=20000000;i;i--)finv[i-1]=1ll*finv[i]*i%p;
    int blk=sqrt(ss)/2+2;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=blk&&b[i]<=blk)c1[++tot1]=(node){a[i],b[i]};
        else c2[++tot2]=(node){a[i],b[i]};
    }
    int ans=0;
    for(int i=1;i<=tot2;i++)for(int j=1;j<=tot2;j++)if(i^j)
    {
        ans=(ans+C(c2[i].a+c2[i].b+c2[j].a+c2[j].b,c2[i].a+c2[j].a))%p;
    }
    for(int i=1;i<=tot1;i++)dp[blk-c1[i].a][blk-c1[i].b]++;
    for(int i=1;i<=2*blk;i++)dp[0][i]=(dp[0][i]+dp[0][i-1])%p;
    for(int i=1;i<=2*blk;i++)dp[i][0]=(dp[i][0]+dp[i-1][0])%p;
    for(  int i=1;i<=blk*2;i++)
    for(  int j=1;j<=blk*2;j++)dp[i][j]=(1ll*dp[i][j]+dp[i-1][j]+dp[i][j-1])%p;
    for(int i=1;i<=tot1;i++)ans=(ans+dp[blk+c1[i].a][blk+c1[i].b])%p;
    for(int i=1;i<=tot1;i++)ans=(ans-C(c1[i].a+c1[i].b+c1[i].a+c1[i].b,c1[i].a+c1[i].a)+p)%p;
    memset(dp,0,sizeof(dp));
	cerr<<ans<<endl;
    int sum=0;
    for(int i=1;i<=tot2;i++)
    {
        for(  int j=0;j<=2*blk;j++)//dp[j][0]
        {
            dp[j][0]=(dp[j][0]+C(j+c2[i].a-blk+c2[i].b-blk,c2[i].b-blk))%p;
        }
        for(  int j=1;j<=2*blk;j++)//dp[0][j]
        {
            dp[0][j]=(dp[0][j]+C(c2[i].a-blk+j+c2[i].b-blk,c2[i].a-blk))%p;
        }
    }
    for(  int i=1;i<=2*blk;i++)
    for(  int j=1;j<=2*blk;j++)dp[i][j]=(1ll*dp[i][j]+dp[i-1][j]+dp[i][j-1])%p;
    for(int i=1;i<=tot1;i++)sum=(sum+dp[c1[i].a+blk][c1[i].b+blk])%p;
    ans=(ans+2ll*sum%p)%p;
    printf("%d\n",ans);
}