//
// Created by 张成 on 2020/5/24.
//
#include<bits/stdc++.h>
#define int long long
/*
 * a b c d e->0
 * s^a s^b s^c s^d s^e->1
 * s^a s^b s^c s^d s^e
 * ...
 */
/*
 * a b c d->0
 * s^a s^b s^c s^d->1
 * a b c d
 * ...
 */
using namespace std;
int n,m,q,f[1001],a[1001],ans[1001],mx,tmp[1001];
vector<int>v[1001];
signed main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&q);
    int s=0;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&f[i]);
        s^=f[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=q;i++){
        scanf("%lld",&a[i]);
        mx=max(mx,a[i]);
    }
    if(m==n*(n-1)/2){
        for(int i=1;i<=q;i++){
            if(n%2==0){
                if(a[i]%2==0){
                    printf("%lld\n",f[1]);
                }
                else{
                    printf("%lld\n",s^f[1]);
                }
            }
            else{
                if(a[i]==0){
                    printf("%lld\n",f[1]);
                }
                else{
                    printf("%lld\n",s^f[1]);
                }
            }

        }
    }
    else{
        ans[0]=f[1];
        for(int i=1;i<=mx;i++){
            memset(tmp,0,sizeof(tmp));
            for(int j=1;j<=n;j++){
                for(int k=0;k<v[j].size();k++){
                    tmp[j]^=f[v[j][k]];
                }
            }
            for(int j=1;j<=n;j++){
                f[j]=tmp[j];
            }
            ans[i]=f[1];
        }
        for(int i=1;i<=q;i++){
            printf("%lld\n",ans[a[i]]);
        }
    }
    return 0;
}