#include<bits/stdc++.h>
#define int long long
using namespace std;
#define  lt long long
#define IT set<node>::iterator
int n,m,x;
struct node{
    int ll,rr;
    mutable lt val;
    node(int L,int R=-1,lt V=0): ll(L),rr(R),val(V){}
    bool operator <(const node &tt)const {return ll<tt.ll;}
};
set<node> st;

IT split(int pos){
    IT it=st.lower_bound(node(pos));
    if(it!=st.end()&&it->ll==pos)return it;
    --it;
    int ll=it->ll,rr=it->rr;
    lt val=it->val;
    st.erase(it);
    st.insert(node(ll,pos-1,val));
    return st.insert(node(pos,rr,val)).first;
}

void assign(int ll,int rr,lt val){
    IT itr=split(rr+1),itl=split(ll);
    st.erase(itl,itr);
    st.insert(node(ll,rr,val));
}
int a[100001],b[100001];
bool check(int v){
    st.clear();
    for(int i=1;i<=v;i++){
        assign(a[i],b[i],1);
    }
    int lst=0,ans=0;
    for(auto i:st){
        if(i.val==0)continue;
        int len=i.rr-i.ll+1;
        if(x==0&&len!=0)return 0;
        ans+=(len/x);
        if(len%x)ans++;
        lst=i.rr;
    }
    return ans<=m;
}
signed main(){
    st.insert({1,1000000000ll*1000000000ll,0});
    scanf("%lld%lld%lld",&n,&m,&x);
    for(int i=1;i<=m;i++)scanf("%lld%lld",&a[i],&b[i]);
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
}