#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=200010;
int n,m,q,top,tot,sum,cnt;
int sta[maxn],low[maxn],HEAD[maxn],NEXT[maxn<<1],TO[maxn<<1],head[maxn<<1],_next[maxn<<2],to[maxn<<2];
int s[maxn<<1],fa[19][maxn<<1],Log[maxn<<1],dep[maxn<<1],Q[maxn<<1];
inline void ADD(int a,int b)
{
    TO[cnt]=b,NEXT[cnt]=HEAD[a],HEAD[a]=cnt++;
}
inline void add(int a,int b)
{
    to[cnt]=b,_next[cnt]=head[a],head[a]=cnt++;
}
void tarjan(int x)
{
    dep[x]=low[x]=++tot,sta[++top]=x;
    for(int y,i=HEAD[x],t;i!=-1;i=NEXT[i])
    {
        y=TO[i];
        cout<<x<<"->"<<y<<endl;
        if(!dep[y])
        {
            tarjan(y),low[x]=min(low[x],low[y]);
            if(low[y]>=dep[x])
            {
                sum++;
                do
                {
                    t=sta[top--],add(sum,t),add(t,sum);
                    cout<<sum<<"?"<<t<<endl;
                }while(t!=y);
                add(sum,x),add(x,sum);
                cout<<sum<<"!"<<x<<endl;
            }
        }
        else    low[x]=min(low[x],dep[y]);
    }
}
void dfs(int x)
{
    Q[++Q[0]]=x;
    for(int i=head[x];i!=-1;i=_next[i])  if(to[i]!=fa[0][x]) fa[0][to[i]]=x,dep[to[i]]=dep[x]+1,dfs(to[i]);
}
inline int lca(int a,int b)
{
    int i;
    if(dep[a]<dep[b])    swap(a,b);
    for(i=Log[dep[a]-dep[b]];i>=0;i--)   if(dep[fa[i][a]]>=dep[b])    a=fa[i][a];
    if(a==b)    return a;
    for(i=Log[dep[a]];i>=0;i--)  if(fa[i][a]!=fa[i][b])  a=fa[i][a],b=fa[i][b];
    return fa[0][a];
}
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
int main()
{
    freopen("5.in","r",stdin);
    freopen("5.std.out","w",stdout);
    n=rd(),m=rd(),q=rd(),sum=n;
    memset(head,-1,sizeof(head)),memset(HEAD,-1,sizeof(HEAD));
    int i,j,a,b,c;
    for(i=1;i<=m;i++)    a=rd(),b=rd(),ADD(a,b),ADD(b,a);
    cnt=0,tarjan(1),dep[1]=1,dfs(1);
    for(i=2;i<=sum;i++)  Log[i]=Log[i>>1]+1;
    for(j=1;(1<<j)<=sum;j++)   for(i=1;i<=sum;i++)  fa[j][i]=fa[j-1][fa[j-1][i]];
    for(i=1;i<=q;i++)
    {
        a=rd(),b=rd(),c=lca(a,b);
        s[a]++,s[b]++,s[c]--,s[fa[0][c]]--;
    }
    for(i=sum;i;i--)    a=Q[i],s[fa[0][a]]+=s[a];
    for(i=1;i<=n;i++)    printf("%d\n",s[i]);
    return 0;
}
