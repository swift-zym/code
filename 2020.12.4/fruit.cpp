#include<bits/stdc++.h>
using namespace std;
struct fruit{
    int a,b;
    bool operator <(const fruit &f)const{
        return a<f.a;
    }
};
vector<fruit>f[2];
int n,p,t[100001],a[100001],b[100001];
priority_queue<int>q[2];
int solve(int x){
    f[0].clear();f[1].clear();
    while(!q[0].empty())q[0].pop();
    while(!q[1].empty())q[1].pop();
    for(int i=1;i<=n;i++){
        f[t[i]].push_back({a[i],b[i]});
    }
    sort(f[0].begin(),f[0].end());
    sort(f[1].begin(),f[1].end());
    int p1=0,p2=0;
    while(p1<f[0].size()&&f[0][p1].a<=p)q[0].push(f[0][p1++].b);
    while(p2<f[1].size()&&f[1][p2].a<=p)q[1].push(f[1][p2++].b);
    int num=0;
    while(!q[x].empty()){
        p+=q[x].top();q[x].pop();num++;
        while(p1<f[0].size()&&f[0][p1].a<=p)q[0].push(f[0][p1++].b);
        while(p2<f[1].size()&&f[1][p2].a<=p)q[1].push(f[1][p2++].b);
        x^=1;
    }
    return num;
}
int main(){
    freopen("fruit.in","r",stdin);
    freopen("fruit.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&t[i],&a[i],&b[i]);
    int bk=p,ans=solve(0);
    p=bk;ans=max(ans,solve(1));
    printf("%d\n",ans);
    return 0;
}
