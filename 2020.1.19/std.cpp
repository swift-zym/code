#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 200000
#define MOD 1000000
int tot;
inline int read()
{
    register int x=0,t=1;
    register char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-'){t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*t;
}
struct Node
{
    int ch[2];
    int val;
    int ff;
}t[MAX];
int root;
inline void rotate(int x)
{
    int y=t[x].ff;
    int z=t[y].ff;
    int k=(x==t[y].ch[1]);
    t[z].ch[y==t[z].ch[1]]=x;
    t[x].ff=z;
    t[y].ch[k]=t[x].ch[k^1];
    t[t[x].ch[k^1]].ff=y;
    t[x].ch[k^1]=y;
    t[y].ff=x;
}
inline void splay(int x,int goal)
{
    //if(x==0)return;
    while(t[x].ff!=goal)
    {
        int y=t[x].ff;
        int z=t[y].ff;
        if(z!=goal)
            (t[z].ch[0]==y)^(t[y].ch[0]==x)?rotate(x):rotate(y);
        rotate(x);
    }
    if(goal==0)root=x;
}
inline void insert(int x)
{
    int u=root,ff=0;
    while(u&&t[u].val!=x)
    {
        ff=u;
        u=t[u].ch[t[u].val<x];
    }
    if(u);
    else
    {
        u=++tot;
        if(ff)t[ff].ch[t[ff].val<x]=u;
        t[u].ff=ff;
        t[u].ch[0]=t[u].ch[1]=0;
        t[u].val=x;
    }
    splay(u,0);
}
inline void find(int x)
{
    int u=root;
    if(!u)return;
    while(t[u].ch[x>t[u].val]&&x!=t[u].val)
        u=t[u].ch[x>t[u].val];
    splay(u,0);
}
inline int Next(int x,int f)
{
    find(x);
    int u=root;
    if(t[u].val>=x&&f)return u;
    if(t[u].val<=x&&!f)return u;
    u=t[u].ch[f];
    while(t[u].ch[f^1])u=t[u].ch[f^1];
    return u;
}
inline int Next_une(int x,int f)
{
    find(x);
    int u=root;
    if(t[u].val>x&&f)return u;
    if(t[u].val<x&&!f)return u;
    u=t[u].ch[f];
    while(t[u].ch[f^1])u=t[u].ch[f^1];
    return u;
}
inline void Delete(int x)
{
    int lt=Next_une(x,0);
    int nt=Next_une(x,1);
    splay(lt,0);splay(nt,lt);
    t[nt].ch[0]=0;
}
int main()
{
    freopen("pet1.in","r",stdin);
    freopen("pet1.out.ac","w",stdout);
    int n=read();
    int cnt=0,ans=0;
    insert(+214748364);
    insert(-214748364);
    while(n--)
    {
        int k=read(),x=read();
        if(x==1)
            x=1;
        if(cnt==0){//空树
            insert(x);
            cout<<"ins"<<endl;
        }
        if(cnt>0)//宠物树
        {
            if(k==0){
              cout<<"ins"<<endl;
              insert(x);
            }
            else//新来顾客
            {
                int a1=t[Next(x,0)].val;//前驱
                int a2=t[Next(x,1)].val;//后继
                cout<<a1<<" "<<a2<<endl;
                if(abs(a1-x)<=abs(a2-x))
                {
                    ans+=abs(a1-x);
                    Delete(a1);
                }
                else
                {
                    (ans+=abs(a2-x))%=MOD;
                    Delete(a2);
                }
            }
        }
        if(cnt<0)//顾客树
        {
            if(k==1){
              insert(x);
              cout<<"ins"<<endl;
            }
            else//新来宠物
            {
                int a1=t[Next(x,0)].val;
                int a2=t[Next(x,1)].val;
                cout<<a1<<" "<<a2<<endl;
                if(abs(a1-x)<=abs(a2-x))
                {
                    (ans+=abs(a1-x))%=MOD;
                    Delete(a1);
                }
                else
                {
                    (ans+=abs(a2-x))%=MOD;
                    Delete(a2);
                }
            }
        }
        cnt=cnt+(k==0?1:-1);
    }
    printf("%d\n",ans);
    return 0;
}
