#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#ifdef DEBUG
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define MOD 5000017
int k[7],p[7],n,m,out,ha[5000027],sum[5000027],vis[5000027];
int getHash(int a){
    int now=abs(a)%MOD;
    while (sum[now]&&ha[now]!=a) {
        now=(now+1)%MOD;
    }
    return now;
}
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
void dfs1(int deep,int ans){
    if(deep>n/2){
        int tmp=getHash(ans);
        ha[tmp]=ans;
        sum[tmp]++;
        return;
    }
    for(int i=1;i<=m;i++){
        dfs1(deep+1,ans+k[deep]*pow(i,p[deep]));
    }
}
void dfs2(int deep,int ans){
    if(deep<n/2+1){
        int tmp=getHash(-ans);
        out+=tmp&ans;
        out+=sum[tmp];
        return;
    }
    for(int i=1;i<=m;i++){
        dfs2(deep-1,ans+k[deep]*pow(i,p[deep]));
    }
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        k[i]=read(),p[i]=read();
    }
    dfs1(1,0);
    dfs2(n,0);
    printf("%d\n",out);
    return 0;
}
