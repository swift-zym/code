#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IT set<node>::iterator
struct node{
    int l,r;
    mutable int vaule;
    node(int L,int R=-1,int V=0):l(L),r(R),vaule(V){}
    bool operator <(const node &a)const {return l<a.l;}
};
set<node>st;
IT split(int pos){
    IT tmp=st.lower_bound(node(pos));
    if(tmp!=st.end()&&pos==tmp->l)return tmp;
    tmp--;
    int L=tmp->l,R=tmp->r,V=tmp->vaule;
    //cout<<">"<<V<<endl;
    st.erase(tmp);
    st.insert(node{L,pos-1,V});
    return st.insert(node{pos,R,V}).first;
}
bool insert(int l,int r,int v){
    int ans=0;
    IT b=split(r+1),a=split(l);
    int total=0;
    for(;a!=b;a++){
        a->vaule=max(a->vaule,v);
    }
}
void change(int l,int r,int v){
    IT b=split(r+1),a=split(l);
    st.erase(a,b);
    st.insert(node{l,r,v});
}
int n;
struct query{
    int a,b,h;
    bool operator <(const query &t)const{
        return h<t.h;
    }
};
vector<query>v;
signed main(){
    freopen("horizon.in","r",stdin);
    freopen("horizon.out","w",stdout);
    scanf("%lld",&n);
    st.insert({1,1000000000,0});
    for(int i=1;i<=n;i++){
        int a,b,h;
        scanf("%lld%lld%lld",&a,&b,&h);
        v.push_back({a,b-1,h});
    }
    sort(v.begin(),v.end());
    for(auto i=v.begin();i!=v.end();i++){
        change(i->a,i->b,i->h);
    }
    int ans=0;
    for(IT i=st.begin();i!=st.end();i++){
        //cout<<i->l<<" "<<i->r<<" "<<i->vaule<<endl;
        if(i->r>=i->l)
        ans+=(i->r-i->l+1)*i->vaule;
    }
    printf("%lld\n",ans);
    #ifdef WIN32
    system("pause");
    #endif  
    return 0;
}