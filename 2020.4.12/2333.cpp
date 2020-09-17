
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int mod=1000000007;
const int N=200005;
int g[N],f[N],L[N],R[N],n,tot=0,q[N];
struct node{
    int x,v,vv;
};
node po[N];

int cmp1(const node &a,const node &b){return a.v<b.v;}
int cmp2(const node &a,const node &b){return a.x<b.x;}

void cl()
{
    int i,j;
    int mx=0,mn=tot+1;
    for (i=1;i<=n;i++)  //单调不减
    {
        mx=(po[i].vv>mx) ? po[i].vv:mx;
        R[i]=mx;
    }
    for (i=n;i>=1;i--)
    {
        mn=(po[i].vv<mn) ? po[i].vv:mn;
        L[i]=mn;
    }
    //for (i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
}

void dp()
{
    int sum=0,tou=0,wei=0;
    L[0]=1;R[0]=0;
    f[0]=1;
    q[wei++]=0,sum=1;
    ++n;
    L[n]=R[n]=n;
    for (int i=1;i<=n;i++)  //循环猫的标号
    {
      cout<<sum<<endl;
        while (tou<wei&&L[i]>R[q[tou]]+1)  //用队列
            sum=sum-f[q[tou]],sum%=mod,++tou;  //区间和
        f[i]=sum;
        sum=sum+f[i];
        sum%=mod;
        q[wei++]=i;  //加入队列
    }
    printf("%d",f[n]);
}

int main()
{
    //freopen("xtdoor.in","r",stdin);
    //freopen("xtdoor.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&po[i].x,&po[i].v);
    sort(po+1,po+1+n,cmp1);
    for (int i=1;i<=n;i++)
        if (po[i].v==po[i-1].v) po[i].vv=po[i-1].vv;
        else po[i].vv=++tot;
    sort(po+1,po+1+n,cmp2);
    cl();
    dp();
    return 0;
}
