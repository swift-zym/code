//题目名:树的直径
#include<bits/stdc++.h>
using namespace std;
int head[400001],next_[400000],cnt,to[400000],ans[400001],n,vis[400001];
void dfs(int now,int deep){
     vis[now]=1;
     ans[now]=deep;
     for(int i=head[now];i;i=next_[i]){
         if(!vis[to[i]])
         dfs(to[i],deep+1);
     }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        to[++cnt]=b;
        next_[cnt]=head[a];
        head[a]=cnt;
        to[++cnt]=a;
        next_[cnt]=head[b];
        head[b]=cnt;
    }
    dfs(1,0);
    int maxn=-1,s;
    for(int i=1;i<=n;i++){
        if(ans[i]>maxn){
            maxn=ans[i],s=i;
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(s,0);
    int e;
    maxn=-1;
    for(int i=1;i<=n;i++){
        if(ans[i]>maxn){
            maxn=ans[i],e=i;
        }
    }
    cout<<maxn<<endl;
    #ifdef WIN32
    system("pause");
    #endif
}