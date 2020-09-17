//题目名：序列操作
#include<bits/stdc++.h>
using namespace std;
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
    st.erase(tmp);
    st.insert(node{L,pos-1,V});
    return st.insert(node{pos,R,V}).first;
}
void change1(int l,int r,int v){
    IT b=split(r+1),a=split(l);
    st.erase(a,b);
    st.insert(node{l,r,v});
}
void change2(int l,int r){
    IT b=split(r+1),a=split(l);
    for(;a!=b;a++){
        if(a->vaule==1)a->vaule=0;
        else a->vaule=1;
    }
}
int ask1(int l,int r){
    int ans=0;
    IT b=split(r+1),a=split(l);
    for(;a!=b;a++){
        if(a->vaule==1){
            ans+=a->r-a->l+1;
        }
    }
    return ans;
}
int ask2(int l,int r){
    int ans=0;
    IT b=split(r+1),a=split(l);
    int total=0;
    for(;a!=b;a++){
        if(a->vaule==1){
            total+=a->r-a->l+1;
            ans=max(ans,total);
        }
        else{
            total=0;
        }
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        st.insert(node(i,i,a));
    }
    for(int i=1;i<=m;i++){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        l++;r++;
        if(op==0){
            change1(l,r,0);
        }
        else if(op==1){
            change1(l,r,1);
        }
        else if(op==2){
            change2(l,r);
        }
        else if(op==3){
            printf("%d\n",ask1(l,r));
        }
        else{
            printf("%d\n",ask2(l,r));
        }
    }
    #ifdef WIN32
    system("pause");
    #endif
}