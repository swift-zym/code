#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long LL;
struct node
{
    int u,v;
    LL w;
} val[N];
int n,f[N],ans[N];
int getf(int x)
{
    if(x!=f[x])
        f[x]=getf(f[x]);
    return f[x];
}
int cmp(node t1,node t2)
{
    return t1.w<t2.w;
}
int main()
{
    scanf("%d",&n);
    LL sum=0;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d%lld",&val[i].u,&val[i].v,&val[i].w);
        sum+=val[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        ans[i]=1;
    }
    sort(val+1,val+n,cmp);
    for(int i=1; i<n; i++)
    {
        int t1=getf(val[i].u);
        int t2=getf(val[i].v);
        sum+=(LL)(val[i].w+1)*(ans[t1]*ans[t2]-1);
        std::cout<<val[i].w<<" "<<ans[t1]<<" "<<ans[t2]<<std::endl;
        f[t1]=t2;
        ans[t2]+=ans[t1];
    }
    printf("%lld\n",sum);
    return 0;
}
