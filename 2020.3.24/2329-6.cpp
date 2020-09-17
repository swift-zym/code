#include<bits/stdc++.h>
using namespace std;
int head[50001],nxt[200001],to[200001],len[200001],n,m,s,cnt,vis[50001],ans[50001][6];
int tmp[6];
int a[6];
int main(){
    scanf("%d%d",&n,&m);
    memset(ans,0x3f,sizeof(ans));
    tmp[0]=1;
    a[0]=0;
    for(int i=1;i<=5;i++){
      a[i]=i;
      scanf("%d",&tmp[i]);
    }
    for(int i=1;i<=m;i++){
        int f,g,w;
        scanf("%d%d%d",&f,&g,&w);
        to[++cnt]=g;
        len[cnt]=w;
        nxt[cnt]=head[f];
        head[f]=cnt;
        to[++cnt]=f;
        len[cnt]=w;
        nxt[cnt]=head[g];
        head[g]=cnt;
    }
    queue<int>q;
    for(int idx=0;idx<=5;idx++){
    q.push(tmp[idx]);
    vis[tmp[idx]]=1;
    memset(vis,0,sizeof(vis));
    ans[tmp[idx]][idx]=0;
    while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=head[now];i;i=nxt[i]){
        if(ans[now][idx]+len[i]<ans[to[i]][idx]){
            ans[to[i]][idx]=ans[now][idx]+len[i];
            if(!vis[to[i]]){
                q.push(to[i]);
                vis[to[i]]=1;
            }
        }
    }
    }
    }
    int mi=1e8;
    do{
      int sum=0;
      for(int i=0;i<=4;i++){
        sum+=ans[tmp[a[i+1]]][a[i]];
      }
      mi=min(mi,sum);
    }while(next_permutation(a+1,a+6));
    printf("%d\n",mi);
    return 0;
}
