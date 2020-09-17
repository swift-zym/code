//
// Created by swift on 2020/8/5.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int p,q;
    bool operator <(const node &t)const{
        if(q!=t.q)
        return q<t.q;
        return p<t.p;
    }
}a[50001];
int n,k,m;
priority_queue<int>p;
bool check(int x){
    int ans=0;
    for(int i=1;i<=x;i++){
        ans+=a[i].q;
        p.push(-(a[i].p-a[i].q));
    }
    //cout<<x<<endl;
    for(int i=1;i<=x-k;i++){
        ans-=p.top();
        p.pop();
    }
    while(!p.empty())p.pop();
    return ans<=m;
}
signed main(){
    scanf("%lld%lld%lld",&n,&k,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].p,&a[i].q);
    }
    sort(a+1,a+n+1);
    int l=0,r=n;
    while(l<r-1){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    check(9);
    if(check(r))
        printf("%lld\n",r);
    else
        printf("%lld\n",l);
    return 0;
}