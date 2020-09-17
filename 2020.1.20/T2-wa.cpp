#include<bits/stdc++.h>
#define kk (k<<1)
using namespace std;
inline int read()
{
    int f=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')f=(f<<1)+(f<<3)+ch-'0',ch=getchar();
    return f*w;
}
struct node {int l,r,num,d;}a[2][400001];
int n,m;
inline void pushdown(int k,int p)
{
    if(!a[p][k].d)return;
    a[p][kk].d=a[p][k].d;
    a[p][kk].num=a[p][k].d;
    a[p][kk+1].d=a[p][k].d;
    a[p][kk+1].num=a[p][k].d;
    a[p][k].d=0;
}
void change(int k,int x,int y,int s,int p)
{
    if(a[p][k].r<x||a[p][k].l>y)return;
    if(x<=a[p][k].l&&a[p][k].r<=y)
    {
        a[p][k].d=s;
        a[p][k].num=s;
        return;
    }
    pushdown(k,p);
    change(kk,x,y,s,p);
    change(kk+1,x,y,s,p);
}
void build(int k,int x,int y,int s,int p)
{
    a[p][k].l=x;a[p][k].r=y;a[p][k].num=s;
    if(x==y)return;
    int mid=(x+y)>>1;
    build(kk,x,mid,s,p);
    build(kk+1,mid+1,y,s,p);
}
int query(int k,int x,int p)
{
    if(a[p][k].r<x||a[p][k].l>x)return 0;
    if(a[p][k].l==x&&a[p][k].r==x)return a[p][k].num;
    pushdown(k,p);
    return query(kk,x,p)+query(kk+1,x,p);
}
int main()
{
    freopen("T2.in","r",stdin);
    freopen("T2.out","w",stdout);
    n=read();m=read();
    build(1,1,n,1,0);
    build(1,1,n,n,1);
    while(m--)
    {
        int opr=read();
        if(opr==1)
        {
            int x=read(),y=read();
            change(1,x,y,-1,1);
            change(1,x,y,-1,0);
            if(x>1)
            {
                int q=query(1,x-1,0);
                if(q!=-1)change(1,q,x-1,x-1,1);
            }
            if(y<n)
            {
                int w=query(1,y+1,1);
                if(w!=-1)change(1,y+1,w,y+1,0);
            }
        }
        else if(opr==2)
        {
            int x=read(),y=read();
            int q,w;
            if(x>1)
            {
                q=query(1,x-1,0);
                if(q==-1)q=x;
            }
            else q=x;
            if(y<n)
            {
                w=query(1,y+1,1);
                if(w==-1)w=y;
            }
            else w=y;
            change(1,q,w,q,0);
            change(1,q,w,w,1);
        }
        else
        {
            int x=read();
            int q=query(1,x,0),w=query(1,x,1);
            if((q==1&&w!=-1)||(q!=-1&&w==n))printf("INF\n");
            else if(q==-1||w==-1)printf("0\n");
            else printf("%d\n",q-w+1);
        }
    }
}
/*
5 5
1 2 4
3 1
3 4
2 3 3
3 3
*/
