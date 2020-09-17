#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
inline int rd(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return ;
}
int n,m;
int head[100006];
int nxt[200006],to[200006];
int total=0;
void add(int x,int y){
    total++;
    to[total]=y;
    nxt[total]=head[x];
    head[x]=total;
    return ;
}
int dfn[100006],low[100006];
int tot=0;
int num[100006];
void Tarjan(int x,int fa){
    dfn[x]=low[x]=++tot;
    for(int e=head[x];e;e=nxt[e]){
        if(!dfn[to[e]]){
            Tarjan(to[e],x);
            low[x]=min(low[x],low[to[e]]);
            if(low[to[e]]>=dfn[x]) num[x]++;
        }
        else if(to[e]!=fa) low[x]=min(low[x],dfn[to[e]]);
    }
    return ;
}
int main(){
    freopen("e.in","r",stdin);
    while(1){
        memset(dfn,0,sizeof(dfn));
        memset(head,0,sizeof(head));
        memset(num,0,sizeof(num));
        total=tot=0;
        n=rd();
        m=rd();
        if(!n&&!m) break;
        for(int i=1;i<=m;i++){
            int x=rd(),y=rd();
            add(x,y),add(y,x);
        }
        int cnt=0;
        int maxn=-999999;
        for(int i=0;i<n;i++){
            if(!dfn[i]){
                cnt++;
                Tarjan(i,-1);
                num[i]--;
            }
        }
        for(int i=0;i<n;i++){
            maxn=max(maxn,num[i]);
        }
        if(n==10000&&m==9999){
          printf("--%d,%d,%d--\n",num[100],maxn,cnt);
        }
        write(cnt+maxn);
        puts("");
    }
    return 0;
}
