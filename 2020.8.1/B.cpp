//
// Created by swift on 2020/8/1.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>pre[100001],len[100001];
int n,k,f[100001],w[100001];
int mi[100001],sum[100001],rt,siz,tim;
void dfs(int now,int m=1e8,int s=0,int dep=0){
    //cout<<">"<<now<<" "<<m<<" "<<s<<endl;
    siz++;
    mi[dep]=m;sum[dep]=s;
    if(now==rt)tim++;
    if(now==rt&&tim==2)return;
    dfs(f[now],min(m,w[now]),s+w[now],dep+1);
}
int ans1[100001],ans2[100001];
int vis[100001];
int fm[100001][21],fs[100001][21],ff[100001][21];
void solve(int now,int m=1e8,int s=0,int dep=0){
    //cout<<">"<<now<<" "<<m<<" "<<s<<endl;
    vis[now]=1;
    int v=k-dep;
    if(v<0){
        int kk=k;
        ans2[now]=1e8;
        int tp=now;
        for(int i=20;i>=0;i--){
            if(kk>=(1<<i)){
                kk-=(1<<i);
                ans1[now]+=fs[tp][i];
                ans2[now]=min(ans2[now],fm[tp][i]);
                tp=ff[tp][i];
            }
        }
    }
    else if(v<=siz){
        ans1[now]=s+sum[v];
        ans2[now]=min(m,mi[v]);
        //cout<<now<<":type1 "<<ans1[now]<<" "<<ans2[now]<<endl;
    }
    else{
        ans1[now]=s+(v/siz)*sum[siz]+sum[(v%siz)];
        ans2[now]=min(m,mi[siz]);
        //cout<<now<<":type2 "<<ans1[now]<<" "<<ans2[now]<<endl;
    }
    for(int i=0;i<pre[now].size();i++){
        if(pre[now][i]!=rt)
        solve(pre[now][i],min(m,len[now][i]),s+len[now][i],dep+1);
    }
}
int instack[100001],istail[100001],checked[100001];
stack<int>s;
void check(int now){
    instack[now]=1;
    checked[now]=1;
    s.push(now);
    if(instack[f[now]]){
        int tp;
        do{
            tp=s.top();s.pop();
            instack[tp]=0;
            istail[tp]=1;
        }while(tp!=f[now]);
    }
    else{
        if(!checked[f[now]])
        check(f[now]);
    }
    if(instack[now]) {
        instack[now] = 0;
        s.pop();
    }
}
signed main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&f[i]);
        f[i]++;
        ff[i][0]=f[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        fm[i][0]=fs[i][0]=w[i];
    }
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++){
            ff[j][i]=ff[ff[j][i-1]][i-1];
            fm[j][i]=min(fm[j][i-1],fm[ff[j][i-1]][i-1]);
            fs[j][i]=fs[j][i-1]+fs[ff[j][i-1]][i-1];
        }
    for(int i=1;i<=n;i++){
        pre[f[i]].push_back(i);
        len[f[i]].push_back(w[i]);
    }
    for(int i=1;i<=n;i++){
        if(!checked[i]) {
            check(i);
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<istail[i]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        if(istail[i]&&pre[i].size()>1){
            siz=0;
            rt=i;
            tim=0;
            dfs(i);
            siz--;
            solve(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(istail[i]&&!vis[i]){
            siz=0;
            rt=i;
            tim=0;
            dfs(i);
            siz--;
            solve(i);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld %lld\n",ans1[i],ans2[i]);
    }
    return 0;
}
/*
8 3
1 2 3 4 5 4 2 7
6 3 1 1 4 2 2 3
 */