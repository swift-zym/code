#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[10001];
int vis[10001],num[10001];
int len,s,O;
void dfs(int now,int fa){
    if(++O==1e8){
        puts("No");
        exit(0);
    }
    vis[now]=1;
    len++;
    for(auto i=v[now].begin();i!=v[now].end();i++){
        int to=*i;
        if(to==fa)continue;
        if(to==s){
            num[len]++;
            if(num[len]==3&&len>=2){
                puts("Yes");
                exit(0);

            }
        }
        if(!vis[to])
        dfs(to,now);
    }
    len--;
    vis[now]=0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)vis[i]=1;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);v[b].push_back(a);
    }
    for(s=1;s<=n;s++){
        dfs(s,s);
    }
    puts("No");
    return 0;
}
