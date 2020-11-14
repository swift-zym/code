//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int n;
int f[200001];
int a[200001];
vector<int>g[200001];
int tim;
int v[200001];
pair<int,int> dfs(int now){
    //if(now>75000)cout<<&now<<endl;
    if(!g[now].size()){
        tim++;
        v[tim]=a[now];
        return make_pair(tim,tim);
    }
    int l=1e9,r=-1e9;
    for(auto i:g[now]){

        pair<int,int> tmp=dfs(i);
        l=min(l,tmp.first);
        r=max(r,tmp.second);
        for(int j=tmp.first;j<=tmp.second;j++){
            int val=min(v[tmp.second]-v[j],a[now]);
            v[j]+=val;
            a[now]-=val;
        }
    }
    sort(v+l,v+r+1);
    for(int i=l;i<=r;i++){
        int val=min(v[r]-v[i],a[now]);
        v[i]+=val;
        a[now]-=val;
    }
    if(!a[now])return make_pair(l,r);
    int val=a[now]/(r-l+1);
    for(int i=l;i<=r;i++){
        v[i]+=val;
    }
    a[now]%=(r-l+1);
    for(int i=l;i<l+a[now];i++){
        v[i]++;
    }
    return make_pair(l,r);
}
signed main(){
    freopen("out.txt","r",stdin);
    scanf("%lld",&n);
    for(int i=2;i<=n;i++){
        scanf("%lld",&f[i]);
        g[f[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    pair<int,int> ans=dfs(1);
    sort(v+1,v+tim+1);
    printf("%lld\n",v[ans.second]);
    system("pause");
    return 0;
}