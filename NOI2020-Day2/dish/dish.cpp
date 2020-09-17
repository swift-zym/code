#include<bits/stdc++.h>
#define inf 100000000
#define int long long
using namespace std;
int n,s,t;
int head[201],nxt[10001],to[10001],len[10001];
int cnt=-1;
void clear(){
    memset(head,-1,sizeof(head));
    cnt=-1;
}
void add(int a,int b,int l,bool rev=1){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
    if(rev)add(b,a,0,0);
}
int top[201],dep[201];
bool bfs(){
    queue<int>q;
    for(int i=1;i<=n;i++)dep[i]=inf;
    dep[s]=0;
    top[s]=head[s];
    q.push(s);
    bool flag=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        //cout<<now<<" "<<dep[now]<<endl;
        for(int i=head[now];i!=-1;i=nxt[i]){
            //cout<<">"<<to[i]<<" "<<len[i]<<endl;
            if(dep[to[i]]==inf&&len[i]){
                dep[to[i]]=dep[now]+1;
                top[to[i]]=head[to[i]];
                q.push(to[i]);
                if(to[i]==t)flag=1;
            }
        }
    }
    return flag;
}
int dfs(int now,int sum){
    //cout<<now<<" "<<sum<<endl;
    if(now==t)return sum;
    int num=0;
    for(int i=top[now];i!=-1&&sum;i=nxt[i]){
        top[now] = i;
        //cout<<">"<<to[i]<<" "<<sum<<endl;
        if(dep[to[i]]==dep[now]+1&&len[i]) {
            int v = dfs(to[i],min(sum,len[i]));
            if(v==0)dep[to[i]]=inf;
            len[i]-=v;
            len[i^1]+=v;
            sum-=v;
            num+=v;
        }
    }
    return num;
}
int T;
int N,M,K,d[5001];
int a[5001],b[5001];
bool flag=0;
void check(){
    for(int i=1;i<=M;i++){
        add(n-1,i,K);
    }
    for(int i=1;i<=N;i++){
        add(M+i,n,d[i]);
    }
    for(int i=1;i<=M;i++){
        add(i,a[i]+M,inf);
        if(a[i]!=b[i])
        add(i,b[i]+M,inf);
    }
    int flow=0;
    s=n-1;t=n;
    while(bfs()){
        flow+=dfs(s,inf);
    }
    if(flow!=M*K)return;
    flag=1;
    for(int i=1;i<=M;i++){
        int num=0,id1,val1,id2,val2;
        for(int j=head[i];j!=-1;j=nxt[j]){
            if(to[j]==n-1)continue;
            if(len[j]!=inf){
                num++;
                if(num==1){
                    id1=to[j];val1=inf-len[j];
                }
                else{
                    id2=to[j];val2=inf-len[j];
                }
            }
        }
        if(num==1){
            printf("%lld %lld\n",id1-M,val1);
        }
        else{
            printf("%lld %lld %lld %lld\n",id1-M,val1,id2-M,val2);
        }
    }
}
void dfss(int deep){
    if(deep==M+1){
        //puts("checking");
        clear();
        check();
        return;
    }
    for(int i=1;i<=N;i++)
    for(int j=i;j<=N;j++){
        a[deep]=i;b[deep]=j;
        dfss(deep+1);
        if(flag)return;
    }
}
signed main(){
    freopen("dish.in","r",stdin);
    freopen("dish.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        flag=0;
        scanf("%lld%lld%lld",&N,&M,&K);
        for(int i=1;i<=N;i++)scanf("%lld",&d[i]);
        n=M+N+2;
        dfss(1);
        if(!flag)puts("-1");
    }
    return 0;
}
/*
16
*/