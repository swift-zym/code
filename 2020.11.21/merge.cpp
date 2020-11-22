#include<iostream>
#include<vector>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
namespace subtask1{
    int n,m;
    int head[400001],nxt[400001],to[400001],cnt=-1;
    int du[400001];
    int ver[400001];
    void add(int a,int b){
        nxt[++cnt]=head[a];
        to[cnt]=b;
        head[a]=cnt;
    }
    int vis[400001],num;
    vector<int>ans;
    void dfs(int now){
        for(int i=ver[now];i!=-1;i=nxt[i]){
            if(vis[i/2]){
                ver[now]=nxt[i];
                continue;
            }
            vis[i/2]=1;
            dfs(to[i]);
            ans.push_back(i%2?-(i/2+1):i/2+1);
            i=ver[now];
        }
    }
    void solve(){
        memset(head,-1,sizeof(head));
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
            du[a]++;
            du[b]++;
        }
        bool flag=1;
        num=0;int st;
        for(int i=1;i<=m;i++){
            ver[i]=head[i];
            if(du[i]>1)st=i;
        }
        for(int i=1;i<=m;i++){
            if(du[i]%2){
                num++;
                st=i;
            }
        }
        if(num!=0&&num!=2)flag=0;
        if(!flag){
            puts("NO");
            return;
        }
        dfs(st);
        //exit(0);
        if(ans.size()!=n){
            puts("NO");
            return;
        }
        reverse(ans.begin(),ans.end());
        puts("YES");
        for(int i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",ans[i]);
        }
        putchar(10);
    }
};
namespace subtask2{
    int n,m;
    int head[200001],nxt[200001],to[200001],cnt;
    int in[200001],out[200001];
    int ver[200001];
    void add(int a,int b){
        nxt[++cnt]=head[a];
        to[cnt]=b;
        head[a]=cnt;
        out[a]++;in[b]++;
    }
    int vis[200001],num;
    vector<int>tmp;
    vector<int>ans;
    void dfs(int now){
        for(int i=ver[now];i;i=nxt[i]){
            if(vis[i]){
                ver[now]=nxt[i];
                continue;
            }
            vis[i]=1;
            dfs(to[i]);
            ans.push_back(i);
            i=ver[now];
        }
        tmp.push_back(now);
    }
    void solve(){
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        bool flag=1;
        num=0;int st;
        for(int i=1;i<=m;i++){
            ver[i]=head[i];
            if(out[i]>1)st=i;
        }
        for(int i=1;i<=m;i++){
            if(abs(in[i]-out[i])==1){
                num++;
                if(out[i]>in[i]){
                    st=i;
                }
            }
            else if(abs(in[i]-out[i])>1)flag=0;
        }
        if(num!=0&&num!=2)flag=0;
        if(!flag){
            puts("NO");
            return;
        }
        dfs(st);
        //exit(0);
        if(ans.size()!=n){
            puts("NO");
            return;
        }
        reverse(ans.begin(),ans.end());
        puts("YES");
        for(int i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",ans[i]);
        }
        putchar(10);
    }
};
int t;
int main(){
    //freopen("merge13.in","r",stdin);
    cin>>t;
    if(t==1){
        subtask1::solve();
    }
    else{
        subtask2::solve();
    }
    return 0;
}