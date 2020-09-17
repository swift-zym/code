//
// Created by swift on 2020/7/20.
//

#include<bits/stdc++.h>
using namespace std;
int head[110000],nxt[110000],to[110000],cnt,f[110000],ff[110000][40];
int minnode[110000];
bool cmp(int a,int b){
    return minnode[a]<minnode[b];
}
vector<int>v[110000];
void add(int a,int b){
    //cout<<"add "<<a<<" "<<b<<endl;
    nxt[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}
int n,q;
void dfs(int now){
    minnode[now]=now;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]!=f[i]){
            dfs(to[i]);
            minnode[now]=min(minnode[now],minnode[to[i]]);
        }
    }
}
int root;
int idx[110000],T;
int val[110000],num[110000],dep[110000];
priority_queue<int,vector<int>,greater<int> >p;
void dfs2(int now,int deep=0){
    dep[now]=deep;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==f[now])continue;
        dfs2(to[i],deep+1);
    }
    idx[++T]=now;
    //cout<<T<<" "<<now<<endl;
    num[now]=T;
}
int ins(int x) {
    int tmp;
    for (int i = 1; i <= x; i++) {
        tmp = idx[p.top()];
        p.pop();
        val[tmp] = 1;
    }
    return tmp;
}
int rem(int x){
    int ans=0;
    int xx=x;
    for(int i=20;i>=0;i--){
        if(val[ff[x][i]]){
            ans+=dep[x]-dep[ff[x][i]];
            x=ff[x][i];
        }
    }
    val[x]=0;
    p.push(num[x]);
    return ans;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        if(f[i]){
            add(f[i],i);
            v[f[i]].push_back(i);
        }
        else{
            root=i;
        }
        p.push(i);
    }
    dfs(root);
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()){
            sort(v[i].begin(),v[i].end(),cmp);
        }
        for(int j=v[i].size()-1;j>=0;j--){
            add(i,v[i][j]);
        }
    }
    dfs2(root);
    f[root]=root;
    for(int i=1;i<=n;i++){
        ff[i][0]=f[i];
    }
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++){
            ff[j][i]=ff[ff[j][i-1]][i-1];
        }
    for(int i=1;i<=q;i++){
        int x,k;
        scanf("%d%d",&x,&k);
        if(x==1){
            printf("%d\n",ins(k));
        }
        else{
            printf("%d\n",rem(k));
        }
    }
    return 0;
}