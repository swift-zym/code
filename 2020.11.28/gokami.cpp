#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
struct edge{
    int u,v,w;
    bool operator <(const edge &e)const{
        return w<e.w;
    }
};
int n,a[100001],c[100001],f[100001];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
vector<edge>e;
signed main(){
    freopen("gokami.in","r",stdin);
    freopen("gokami.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        e.push_back({i,j,c[i]+c[j]-a[i]*a[j]});
    }
    sort(e.begin(),e.end());
    int ans=0;
    for(auto s:e){
        int x=gf(s.u),y=gf(s.v);
        if(x==y)continue;
        f[x]=y;
        ans+=s.w;
    }
    printf("%lld\n",ans);
    return 0;
}