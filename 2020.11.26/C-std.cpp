#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e6+10;
int ls[N],rs[N];
int v[N];

int fa[N],rt[N];
inline int getroot(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=getroot(fa[x]);
}
struct Qus{int opt,x,y,z;}t[N];
pair<int,int>e[N];
int vis[N];
int cnt;
inline void modify(int &pos,int l,int r,int x,int val)
{
    if(pos==0)
        pos=++cnt;
    if(l==r)
    {
        v[pos]+=val;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid) modify(ls[pos],l,mid,x,val);
    else modify(rs[pos],mid+1,r,x,val);
    v[pos]=v[ls[pos]]+v[rs[pos]];
}
inline void merge(int &pos,int pre,int l,int r)
{
    if(pre==0) return ;
    if(pos==0)
    {
        pos=pre;
        return ;
    }
    if(l==r)
    {
        v[pos]+=v[pre];
        return ;
    }
    int mid=l+r>>1;
    merge(ls[pos],ls[pre],l,mid);
    merge(rs[pos],rs[pre],mid+1,r);
    v[pos]=v[ls[pos]]+v[rs[pos]];
}
inline int ask(int pos,int l,int r,int x)
{
    if(pos==0)
        return 0;
    if(l==r)
        return v[pos];
    int mid=l+r>>1;
    if(x<=mid) return ask(ls[pos],l,mid,x);
    return ask(rs[pos],mid+1,r,x);
}
int n,m,q;
int ANS[N],CNT;
const int M=2e6+100;
const long long mod=19260817;
long long inv[M],finv[M],f[M];

signed main()
{
    freopen("mc2.in","r",stdin);
    freopen("mc2.ans","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&q);
    inv[0]=inv[1]=1;
    finv[0]=f[0]=finv[1]=f[1]=1;
    for(int i=2;i<=2000000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=2000000;i++) f[i]=f[i-1]*i%mod,finv[i]=finv[i-1]*inv[i]%mod;
    
    
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        modify(rt[i],1,n,y,x);
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        e[i]=make_pair(x,y);
    }
    int num=0;
    for(int i=1;i<=q;i++)
    {
        int opt,x,y,z;
        scanf("%lld",&opt);
        if(opt==1)
        {
            scanf("%lld%d%d",&x,&y,&z);
            t[i]=Qus{opt,x,y,z};
            modify(rt[getroot(x)],1,n,z,y);
        }
        else if(opt==2)
        {
            scanf("%d",&x);
            t[i].opt=2;
            t[i].x=x;
            vis[x]++;
        }
        else
        {
            scanf("%d%d%d",&x,&y,&z);
            t[i]=Qus{opt,x,y,z};
            num++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x=e[i].first,y=e[i].second;
        if(vis[i]==0)
        {
            x=getroot(x),y=getroot(y);
            if(x!=y)
            {
                int PRE=v[rt[x]]+v[rt[y]];
                merge(rt[x],rt[y],1,n);
                if(PRE!=v[rt[x]]) puts("WRO"),exit(0);
                fa[y]=x;
            }
        }
    }
   
    for(int i=q;i>=1;i--)
    {
        int x,y,z;
        x=t[i].x,y=t[i].y,z=t[i].z;
        if(t[i].opt==1)
        {
            x=getroot(x);
            modify(rt[x],1,n,z,-y);
        }
        else if(t[i].opt==2)
        {
            vis[x]--;
            if(vis[x]==0)
            {
                int fr=e[x].first,to=e[x].second;
                fr=getroot(fr),to=getroot(to);
                if(fr!=to)
                {
                    
                    

                    merge(rt[fr],rt[to],1,n);
                    fa[to]=fr;
                    
                }
            }
        }
        else
        {
            int root=getroot(x);
            int num=v[rt[root]];
            int numz=ask(rt[root],1,n,z);
            if(numz<y) {ANS[++CNT]=0;continue;}
            
            //cout<<">>"<<numz<<"  "<<num<<endl;
            //cout<<">"<<num<<" "<<numz<<endl;
            long long res=f[numz]*f[num-y]%mod*finv[num]%mod*finv[numz-y]%mod;
            ANS[++CNT]=(int)(res);
        }
        
    }
    for(int i=CNT;i>=1;i--)
        printf("%d\n",ANS[i]);
}