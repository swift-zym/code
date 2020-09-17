//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
struct fhq_treap{
    struct fhq{
        int son[2];
        int rnd,val,siz;
        int tag;
    }a[200000];
    int tot,root;
    void upd(int x){
        a[x].siz=a[a[x].son[0]].siz+a[a[x].son[1]].siz+1;
    }
    int New(int x){
        a[++tot].rnd=rand();
        a[tot].val=x;
        a[tot].siz=1;
        return tot;
    }
    int mem(int x,int y){
        //cout<<">"<<x<<" "<<y<<endl;
        if(!x||!y){
            return x|y;
        }
        if(a[x].val<a[y].val){
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
    int pre(int t){
        int x,y;
        spl(root,t,x,y);
        if(!x){
            mem(x,y);
            return inf;
        }
        int now=x;
        while(a[now].son[1]){
            now=a[now].son[1];
        }
        mem(x,y);
        return a[now].val;
    }
    int nxt(int t){
        int x,y;
        spl(root,t-1,x,y);
        if(!y){
            mem(x,y);
            return inf;
        }
        int now=y;
        while(a[now].son[0]){
            now=a[now].son[0];
        }
        mem(x,y);
        return a[now].val;
    }
    void ins(int t){
        int x,y;
        spl(root,t,x,y);
        root=mem(mem(x,New(t)),y);
    }
    void print(int now=-1){
        if(now==-1){
            //printf("root=%d\n",root);
        }
        if(now==-1)now=root;
        pushdown(now);
        if(a[now].son[0])print(a[now].son[0]);
        //printf("%d->%d (%d,%d)\n",now,a[now].val,a[now].son[0],a[now].son[1]);
        printf("%d ",a[now].val);
        if(a[now].son[1])print(a[now].son[1]);
    }
    void del(int t){
        int A,B,C;
        spl(root,t,A,C);
        spl(A,t-1,A,B);
        B=mem(a[B].son[0],a[B].son[1]);
        root=mem(mem(A,B),C);
    }
    void rev(int l,int r){
        int A,B,C;
        spl(root,l-1,A,B);
        spl(B,r-l+1,B,C);
        //cout<<A<<" "<<B<<" "<<C<<endl;
        a[B].tag^=1;

        root=mem(mem(A,B),C);
    }
};
fhq_treap treap;
int n,m;
int ans=0;
unordered_map<int,int>ma;
signed main(){
    srand(time(0));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        //treap.ins(i);
        treap.root=treap.mem(treap.root,treap.New(i));
    }
    for(int i=1;i<=m;i++){
        //treap.print();
        int l,r;
        scanf("%d%d",&l,&r);
        treap.rev(l,r);
    }
    treap.print();
    return 0;
}