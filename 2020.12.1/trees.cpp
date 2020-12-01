#include<bits/stdc++.h>
using namespace std;
vector<int>v[100001];
int n,q,mx[100001][21],fa[100001][21],w[100001],deep[100001];
int dp[100001],ans[100001];
int query(int now,int v){
    v++;
    int val=-1;
    for(int i=20;i>=0;i--){
        if(v>=(1<<i)){
            v-=(1<<i);
            val=max(val,mx[now][i]);
            now=fa[now][i];
        }
    }
    return val;
}
int gf(int now,int v){
    for(int i=20;i>=0;i--){
        if(v>=(1<<i)){
            v-=(1<<i);
            now=fa[now][i];
        }
    }
    return now;
}
struct node{
    int id,pos,val;
};
vector<node>que[100001],del[100001];
void dfs(int now,int f,int d){
    deep[now]=d;
    fa[now][0]=f;mx[now][0]=w[now];
    for(int i=1;i<=20;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
        mx[now][i]=max(mx[now][i-1],mx[fa[now][i-1]][i-1]);
    }
    int l=1,r=1e5+1;
    while(l!=r){
        int mid=(l+r)/2;
        if(query(now,mid)>w[now]){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l!=1e5+1){
        dp[now]=dp[gf(now,l)]+1;
    }
    for(auto s:que[now]){
        l=0;r=1e5+1;
        while(l!=r){
            int mid=(l+r)/2;
            if(query(now,mid)>s.val){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        //cout<<s.id<<" "<<s.pos<<" "<<s.val<<" "<<l<<" "<<query(now,l)<<endl;
        int pre=gf(now,l);
        if(l!=1e5+1&&deep[pre]>=deep[s.pos]){
            //cout<<"OK"<<endl;
            ans[s.id]+=dp[pre]+1;
            del[s.pos].push_back({s.id,0,query(pre,deep[pre]-deep[s.pos])});
        }
    }
    for(auto to:v[now]){
        if(to==f)continue;
        dfs(to,now,d+1);
    }
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=q;i++){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        que[u].push_back({i,v,c});
    }
    dfs(1,1,1);
    for(int i=1;i<=n;i++)
    for(auto s:del[i]){
        int l=1,r=1e5+1;
        while(l!=r){
            int mid=(l+r)/2;
            if(query(i,mid)>s.val){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        if(l!=1e5+1){
            ans[s.id]-=dp[gf(i,l)]+1;
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}