#include<bits/stdc++.h>
#define int long long
using namespace std;
struct team{
    int a,b;
    bool operator <(const team &t)const{
        return b-a>t.b-t.a;
    }
}c[300001];
int n,x,y,ans=1e9;
priority_queue<pair<team,int>>p;
bool cmp(team a,team b){
    return a.a<b.a;
}
signed main(){
    freopen("rank.in","r",stdin);
    freopen("rank.out","w",stdout);
    scanf("%lld",&n);n--;
    scanf("%lld%lld",&x,&y);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&c[i].a,&c[i].b);
    sort(c+1,c+n+1,cmp);
    int pos=n,num=0;
    while(1){
        for(;pos&&c[pos].a>x;pos--){p.push(make_pair(c[pos],pos));}
        ans=min(ans,(int)p.size());
        if(p.empty())break;
        auto now=p.top();p.pop();
        if(x>now.first.b-now.first.a){
            x-=(now.first.b-now.first.a+1);
            c[now.second].a=0;
        }
        else break;
    }
    printf("%lld\n",ans+1);
    return 0;
}