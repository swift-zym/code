#pragma GCC optimize(2)
#include<iostream>
#include<vector>
#define int long long
#define MOD 1000000007
using namespace std;
vector<int>v[300001];
int n,a[300001];
int x,k;
void dfs(int now,int deep=0){
    a[now]+=x-deep*k%MOD;
    a[now]+=MOD;
    a[now]%=MOD;
    for(auto to:v[now]){
        dfs(to,deep+1);
    }
}
signed main(){
    scanf("%lld",&n);
    for(int i=2;i<=n;i++){
        int f;
        scanf("%lld",&f);
        v[f].push_back(i);
    }
    int m;
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int opt,s;
        scanf("%lld",&opt);
        if(opt==1){
            scanf("%lld%lld%lld",&s,&x,&k);
            dfs(s);
        }
        else{
            scanf("%lld",&s);
            printf("%lld\n",a[s]);
        }
    }
    return 0;
}