//珂朵莉树模板
#include<bits/stdc++.h>
using namespace std;
#define  lt long long
#define IT set<node>::iterator
#define pir pair<lt,int>
#define mkp(x,y) make_pair(x,y)
lt seed,vmax;
lt rnd(){
    lt res=seed;
    seed=(seed*7+13)%1000000007;
    return res;
}

const int maxn=100010;
int n,m;
lt  a[maxn];
struct node{
    int ll,rr;
    mutable lt val;
    node(int L,int R=-1,lt V=0): ll(L),rr(R),val(V){}
    bool operator <(const node &tt)const {return ll<tt.ll;}
};
set<node> st;

lt qpow(lt a,lt k,lt p){
    lt res=1;a%=p;
    while(k>0){
        if(k&1)res=(res*a)%p;
        a=(a*a)%p; k>>=1;
    }
    return res;
}
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
void add(int ll,int rr,int val){
    IT itr=split(rr+1),itl=split(ll);
    for(;itl!=itr;++itl)itl->val+=val;
}
lt kth(int ll,int rr,int k){
    vector<pir>vec;
    IT itr=split(rr+1),itl=split(ll);
    for(;itl!=itr;++itl)
    vec.push_back(pir(itl->val,itl->rr-itl->ll+1));
    sort(vec.begin(),vec.end());
    for(vector<pir>::iterator it=vec.begin();it!=vec.end();++it){
        k-=it->second;
        if(k<=0)return it->first;
    }
    return -1;
}

lt qsum(int ll,int rr,lt x,lt y){
    lt res=0;
    IT itr=split(rr+1),itl=split(ll);
    for(;itl!=itr;++itl)
    res+=(qpow(itl->val,x,y)*((itl->rr-itl->ll+1)%y))%y,res%=y;
    return res;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%lld",&seed);
    scanf("%lld",&vmax);
    for(int i=1;i<=n;i++){
        a[i]=(rnd()%vmax)+1;
        st.insert(node(i,i,a[i]));
    }
    for(int i=1;i<=m;i++){
        int op=(rnd()%4)+1;
        int ll=(rnd()%n)+1,rr=(rnd()%n)+1;
        lt x,y;
        if(ll>rr)swap(ll,rr);
        if(op==3)x=(rnd()%(rr-ll+1))+1;
        else x=(rnd()%vmax)+1;
        if(op==4) y=(rnd()%vmax)+1;

        if(op==1)add(ll,rr,x);
        else if(op==2)assign(ll,rr,x);
        else if(op==3)printf("%lld\n",kth(ll,rr,x));
        else if(op==4)printf("%lld\n",qsum(ll,rr,x,y));
    }
    #ifdef WIN32
    system("pause");
    #endif
}