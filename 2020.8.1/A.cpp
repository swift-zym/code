//
// Created by swift on 2020/8/1.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int h[100001],l[100001];
int hnum,lnum;
signed main(){
    scanf("%lld%lld",&n,&m);
    int ans=n*n;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        if(!h[x]){
            ans-=(n-lnum);
            h[x]=1;
            hnum++;
        }
        if(!l[y]){
            ans-=(n-hnum);
            l[y]=1;
            lnum++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}