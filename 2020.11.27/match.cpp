#include<iostream>
#define int long long
#define MOD 1000000007
using namespace std;
int n,m,p[1000000],vis[1000000];
int solve(int l,int r){
    if(l==r)return 1;
    bool flag=1;
    int mid=(l+r)/2+1;
    for(int i=0;i<mid-l;i++){
        if(p[l+i]!=p[mid+i])flag=0;
    }
    if(flag)return solve(l,mid-1)*2%MOD;
    flag=1;
    for(int i=l;i<mid;i++)vis[p[i]]=1;
    for(int i=mid;i<=r;i++){
        if(vis[p[i]])flag=0;
    }
    for(int i=l;i<mid;i++)vis[p[i]]=0;
    if(flag)return solve(l,mid-1)*solve(mid,r)%MOD;
    return 0;
}
signed main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%lld%lld",&m,&n);
    for(int i=0;i<(1<<m);i++)scanf("%lld",&p[i]);
    printf("%lld\n",solve(0,(1<<m)-1));
    return 0;
}