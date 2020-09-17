#include<bits/stdc++.h>
using namespace std;
int n,g;
vector<int>v[100001],s[100001];
int vis[100001];
int siz[100001];
int ans;
int main(){
    scanf("%d%d",&n,&g);
    for(int i=1;i<=g;i++){
        scanf("%d",&siz[i]);
        int flag=0;
        for(int j=1;j<=siz[i];j++){
            int tmp;
            scanf("%d",&tmp);
            if(tmp==1)flag=1;
            v[tmp].push_back(i);
            s[i].push_back(tmp);
        }
        siz[i]-=flag;
    }
    queue<int>q;
    ans=1;
    vis[1]=1;
    for(int i=1;i<=g;i++){
        if(siz[i]==1){
            q.push(i);
        }       
    }
    while(!q.empty()){
        int now=q.front();q.pop();
        int idx;
        for(int i=0;i<s[now].size();i++){
            if(!vis[s[now][i]]){
                vis[s[now][i]]=1;
                ans++;
                int tmp=s[now][i];
                for(int j=0;j<v[tmp].size();j++){
                    siz[v[tmp][j]]--;
                    if(siz[v[tmp][j]]==1)q.push(v[tmp][j]);
                }
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}