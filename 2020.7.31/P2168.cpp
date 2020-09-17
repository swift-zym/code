//
// Created by swift on 2020/7/31.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int h,v;
    bool operator <(const node &t)const{
        if(v!=t.v)return v>t.v;
        return h>t.h;
    }
};
int n,k;
priority_queue<node>p;
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%lld",&x);
        p.push({1,x});
    }
    while((p.size()-1)%(k-1)!=0)p.push({1,0});
    int t=(p.size()-1)/(k-1);
    int ans=0;
    for(int i=1;i<=t;i++){
        int h=0,v=0;
        for(int j=1;j<=k;j++){
            h=max(h,p.top().h);
            v+=p.top().v;
            p.pop();
        }
        ans+=v;
        p.push({h+1,v});
    }
    printf("%lld\n%lld\n",ans,p.top().h-1);
    return 0;
}