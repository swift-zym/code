//
// Created by swift on 2020/8/8.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[500001],du[500001],nxt[1000001],to[1000001],cnt,len[1000001];
void add(int a,int b){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int v[500001];
int n,m;
namespace subtask1{
    void solve(){
        int sum=n-1;
        for(int i=1;i<=n;i++){
            if(v[i]==0)sum=-1;
        }
        cout<<sum<<endl;
    }
}
namespace subtask2{
    int ans=-1;
    void check(){
        int sum=0;
        for(int i=1;i<=cnt;i++)sum+=len[i];
        for(int i=1;i<=n;i++){
            vector<int>x;
            for(int j=head[i];j;j=nxt[j]){
                x.push_back(len[j]);
            }
            sort(x.begin(),x.end());
            if(x[x.size()/2]>v[i]){
                return;
            }
        }
        ans=max(ans,sum);
    }
    void dfs(int deep){
        if(deep==n){
            check();
            return;
        }
        for(int i=1;i<=m;i++){
            len[deep*2]=len[deep*2-1]=i;
            dfs(deep+1);
        }
    }
    void solve(){
        dfs(1);
        cout<<ans/2<<endl;
    }
}
namespace subtask3{
    void solve(int root){
        vector<int>x;
        int ans=0;
        for(int i=1;i<=n;i++) {
            if (i == root)continue;
            x.push_back(v[i]);
            ans+=v[i];
        }
        sort(x.begin(),x.end());
        if(x[x.size()/2]>v[root]){
            ans-=x.size()/2*(x[x.size()/2]-v[root]);
        }
        cout<<ans<<endl;
    }
}
namespace subtask4{
    void solve(int root){
        int now=root,sum=0,pre=-1;
        for(int i=1;i<n;i++){
            for(int j=head[now];j;j=nxt[j]){
                if(to[j]==pre)continue;;
                sum+=min(v[now],v[to[j]]);
                pre=now;
                now=to[j];
            }
        }
        cout<<sum<<endl;
    }
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        add(a,b);add(b,a);
        du[a]++;du[b]++;
    }
    if(m==1)subtask1::solve();
    else if(max(n,m)<=8) subtask2::solve();
    else {
        for(int i=1;i<=n;i++){
            if(du[i]==n-1){
                subtask3::solve(i);
                return 0;
            }
        }
        for(int i=1;i<=n;i++){
            if(du[i]==1){
                subtask4::solve(i);
                return 0;
            }
        }
        assert(0);
    }
    return 0;
}