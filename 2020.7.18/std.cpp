//
// Created by swift on 2020/7/18.
//
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<iomanip>
using namespace std;
inline int read(){
    int i=0,f=1;
    char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar())
        if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar())
        i=(i<<3)+(i<<1)+(ch^48);
    return i*f;
}
int buf[1024];
inline void write(int x){
    if(!x){putchar('0');return ;}
    if(x<0){putchar('-');x=-x;}
    while(x){buf[++buf[0]]=x%10,x/=10;}
    while(buf[0]) putchar(buf[buf[0]--]+48);
    return ;
}
#define stan 555555
struct Treap{
    Treap* son[2];
    int val,weight,sze;bool flip;
    Treap(){
        val=-999999999;sze=0;weight=rand();flip=false;
        return ;
    }
    inline void update(){
        sze=son[1]->sze+son[0]->sze+1;
        return ;
    }
}*null=new Treap(),*root=null,*stack[stan],*x,*last;
typedef pair<Treap*,Treap*> D;
int n,m,sta,en;
inline void maintain_flip(Treap* pos){
    if(pos==null) return ;
    pos->flip^=1;
    return ;
}
inline void pushdown(Treap* pos){
    if(pos==null) return ;
    if(pos->flip){
        pos->flip^=1;
        maintain_flip(pos->son[0]);
        maintain_flip(pos->son[1]);
        swap(pos->son[0],pos->son[1]);
    }
    return ;
}
inline Treap* newtreap(int val){
    Treap *pos=new Treap();
    pos->son[1]=pos->son[0]=null;pos->weight=rand();
    pos->val=val;pos->sze=1;pos->flip=0;
    return pos;
}
inline Treap* merge(Treap* a,Treap* b){
    if(a==null) return b;
    if(b==null) return a;
    pushdown(a);pushdown(b);
    if(a->weight<b->weight){
        a->son[1]=merge(a->son[1],b);
        a->update();
        return a;
    }else{
        b->son[0]=merge(a,b->son[0]);
        b->update();
        return b;
    }
}
inline D split(Treap* pos,int k){
    if(pos==null) return D(null,null);
    D y;pushdown(pos);
    if(pos->son[0]->sze>=k){
        y=split(pos->son[0],k);
        pos->son[0]=y.second;
        pos->update();
        y.second=pos;
    }else{
        y=split(pos->son[1],k-1-pos->son[0]->sze);
        pos->son[1]=y.first;
        pos->update();
        y.first=pos;
    }
    return y;
}
inline Treap* build(){
    int p=0;
    for(int i=1;i<=n;++i){
        x=newtreap(i);last=null;
        while(p&&stack[p]->weight>x->weight){
            stack[p]->update();
            last=stack[p];
            stack[p--]=null;
        }
        if(p) stack[p]->son[1]=x;
        x->son[0]=last;stack[++p]=x;
    }
    while(p) stack[p--]->update();
    return stack[1];
}
inline void reverse(){
    sta=read();en=read();
    D x=split(root,sta-1);
    D y=split(x.second,en-sta+1);
    maintain_flip(y.first);
    root=merge(x.first,merge(y.first,y.second));
    return ;
}
inline void write_in_order(Treap* pos){
    if(pos==null) return;
    pushdown(pos);
    write_in_order(pos->son[0]);
    write(pos->val);putchar(' ');
    write_in_order(pos->son[1]);
    return ;
}
signed main(){
    n=read();m=read();
    root=build();
    while(m--) {write_in_order(root),putchar(10),reverse();};
    write_in_order(root);
    return 0;
}
