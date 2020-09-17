#include<bits/stdc++.h>
#define ll long long
#define ls o*2
#define rs o*2+1
#define mid (l+r)/2
#define MOD 1000000007
using namespace std;
ll tree[4*1000005],tag[4*1000005],qtree[4*1000005];
ll a[1000005];
int n;
void pushdown(int o,int l,int r)
{
    if(!tag[o]||l==r) return ;
    qtree[ls]+= 2*tag[o]%MOD*tree[ls]%MOD + tag[o]%MOD*tag[o]%MOD*(mid-l+1)%MOD;
    qtree[ls]%=MOD;
    qtree[rs]+= 2*tag[o]%MOD*tree[rs]%MOD + tag[o]%MOD*tag[o]%MOD*(r-mid)%MOD;
    qtree[rs]%=MOD;
    tree[ls]+=tag[o]%MOD*(mid-l+1)%MOD;
    tree[ls]%=MOD;
    tree[rs]+=tag[o]%MOD*(r-mid)%MOD;
    tree[rs]%=MOD;
    tag[ls]+=tag[o];
    tag[ls]%=MOD;
    tag[rs]+=tag[o];
    tag[rs]%=MOD;
    tag[o]=0;
}
void up(int o,int l,int r,int ql,int qr,ll v)
{
    if(ql<=l&&r<=qr)
    {
        qtree[o]+= 2*tree[o]%MOD*v%MOD + v%MOD*v%MOD*(r-l+1)%MOD;
        qtree[o]%=MOD;
        tree[o]+= v*(r-l+1)%MOD;
        tree[o]%=MOD;
        tag[o]+=v;
        tag[o]%=MOD;
        return ;
    }
    pushdown(o,l,r);
    if(ql<=mid) up(ls,l,mid,ql,qr,v);
    if(mid<qr) up(rs,mid+1,r,ql,qr,v);
    tree[o]=tree[ls]+tree[rs];
    tree[o]%=MOD;
    qtree[o]=qtree[ls]+qtree[rs];
    qtree[o]%=MOD;
    return ;
}
ll qu_sum(int o,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        return tree[o];
    }
    pushdown(o,l,r);
    ll ans=0;
    if(ql<=mid) ans+=qu_sum(ls,l,mid,ql,qr),ans%=MOD;
    if(mid<qr) ans+=qu_sum(rs,mid+1,r,ql,qr),ans%=MOD;
    return ans;
}
ll qu_qtree(int o,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        return qtree[o];
    }
    pushdown(o,l,r);
    ll ans=0;
    if(ql<=mid) ans+=qu_qtree(ls,l,mid,ql,qr),ans%=MOD;
    if(mid<qr) ans+=qu_qtree(rs,mid+1,r,ql,qr),ans%=MOD;
    return ans;
}
map<int,int>ma;
ll ans=0;
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        up(1,1,n,ma[tmp]+1,i,1);
        ans+=qu_qtree(1,1,n,1,i);
        ans%=MOD;
        ma[tmp]=i;
    }
    printf("%lld\n",ans);
    return 0;
}