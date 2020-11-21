#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int l,r;
    bool operator <(const node &t)const{
        return l<t.l;
    }
};
set<node>st;
int n,m,x;
int l[100001],r[100001];
bool check(int x){
    st.clear();
    for(int i=1;i<=x;i++)st.insert({l[i],r[i]});
    int lst=0,ans=0;
    for(auto i:st){
        int len=i.l-lst-1;
        ans+=(len/x);
        if(len%x)ans++;
        lst=i.r;
    }
    int len=n-lst;
    ans+=(len/x);
    if(len%x)ans++;
    return ans<=m;
}
signed main(){
    freopen("ss.txt","r",stdin);
    scanf("%lld%lld%lld",&n,&m,&x);
    for(int i=1;i<=m;i++)scanf("%lld%lld",&l[i],&r[i]);
    int l=1,r=m;
    while(l!=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
    return 0;
}