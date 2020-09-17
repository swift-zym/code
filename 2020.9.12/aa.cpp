//
// Created by swift on 2020/7/21.
//

#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
struct fhq_treap{
    struct fhq{
        int son[2];
        int rnd,siz;
        long long val;
        int tag;
        long long sum;
    }a[5001];
    int tot,root;
    void upd(int x){
        a[x].siz=a[a[x].son[0]].siz+a[a[x].son[1]].siz+1;
        a[x].sum=a[a[x].son[0]].sum+a[a[x].son[1]].sum+a[x].val;
    }
    int New(int x){
        a[++tot].rnd=rand();
        a[tot].val=a[tot].sum=x;
        //cout<<">"<<x<<endl;
        a[tot].siz=1;
        return tot;
    }
    int Clone(int x){
        a[++tot]=a[x];
        return tot;
    }
    int mem(int x,int y){
        //cout<<">"<<x<<" "<<y<<endl;
        if(!x||!y){
            return x|y;
        }
        if(a[x].rnd<a[y].rnd){
            pushdown(x);
            a[x].son[1]=mem(a[x].son[1],y);
            upd(x);
            return x;
        }
        else{
            pushdown(y);
            a[y].son[0]=mem(x,a[y].son[0]);
            upd(y);
            return y;
        }
    }
    void spl(int now,int k,int &x,int &y){
        //cout<<endl<<"spl on "<<now<<" "<<a[now].val<<endl;
        if(!now){
            x=0;
            y=0;
            return;
        }
        now=Clone(now);
        pushdown(now);
        if(k>a[a[now].son[0]].siz){
            x=now;
            spl(a[now].son[1],k-a[a[now].son[0]].siz-1,a[now].son[1],y);
        }
        else{
            y=now;
            spl(a[now].son[0],k,x,a[now].son[0]);
        }
        upd(now);
    }
    void pushdown(int now){
        if(!now)return;
        if(!a[now].tag)return;
        if(a[now].son[0])
            a[a[now].son[0]].tag^=1;
        if(a[now].son[1])
            a[a[now].son[1]].tag^=1;
        swap(a[now].son[0],a[now].son[1]);
        a[now].tag=0;
    }
    void ins(int t,int at){
        int x,y;
        spl(root,at,x,y);
        root=mem(mem(x,New(t)),y);
    }
    void print(int now=-1){
        if(now==-1)now=root;
        pushdown(now);
        if(a[now].son[0])print(a[now].son[0]);
        //printf("%d->%d (%d,%d)\n",now,a[now].val,a[now].son[0],a[now].son[1]);
        printf("%d ",a[now].val);
        if(a[now].son[1])print(a[now].son[1]);
    }
    void rev(int l,int r){
        int A,B,C;
        spl(root,l-1,A,B);
        spl(B,r-l+1,B,C);
        //cout<<A<<" "<<B<<" "<<C<<endl;
        a[B].tag^=1;
        root=mem(mem(A,B),C);
    }
    long long sum(int l,int r){
        int x,y,z;
        spl(root,l-1,x,y);
        spl(y,r-l+1,y,z);
        long long tmp=a[y].sum;
        root=mem(mem(x,y),z);
        return tmp;
    }
    void del(int at){
        int x,y,z;
        spl(root,at-1,x,y);
        spl(y,1,y,z);
        root=mem(x,z);
    }
};
fhq_treap treap[5001];
int n,m;
int ans=0;
int roots[200001];
long long lastans;
signed main(){
    //freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    srand(time(0));
    scanf("%d",&m);
    /*for(int i=1;i<=n;i++){
        //treap.ins(i);
        treap.root=treap.mem(treap.root,treap.New(i));
    }*/
    for(int i=1;i<=m;i++){
        //treap.print();
        int v,opt;
        scanf("%d%d",&v,&opt);
        treap[i]=treap[v];
        if(opt==1){
            long long p,x;
            scanf("%lld%lld",&p,&x);
            p^=lastans;
            x^=lastans;
            //cout<<">1 "<<p<<" "<<x<<endl;
            treap[i].ins(x,p);
        }
        else if(opt==2){
            long long p;
            scanf("%lld",&p);
            p^=lastans;
            //cout<<">2 "<<p<<endl;
            treap[i].del(p);
        }
        else if(opt==3){
            long long l,r;
            scanf("%lld%lld",&l,&r);
            l^=lastans;r^=lastans;
            //cout<<">3 "<<l<<" "<<r<<endl;
            treap[i].rev(l,r);
        }
        else{
            long long l,r;
            scanf("%lld%lld",&l,&r);
            l^=lastans;r^=lastans;
            //cout<<">4 "<<l<<" "<<r<<endl;
            printf("%lld\n",lastans=treap[i].sum(l,r));
        }
        //roots[i]=treap.root;
        //treap.print();
    }
    return 0;
}