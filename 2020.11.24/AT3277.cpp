#include<iostream>
#include<map>
#include<queue>
#include<set>
using namespace std;
map<pair<int,int>,int>mp;
queue<pair<int,int> >q;
set<int>st[100001];
int n,f[100001];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n*2-2;i++){
        if(i<=n)f[i]=i;
        int a,b;
        scanf("%d%d",&a,&b);
        st[a].insert(b);
        st[b].insert(a);
        mp[make_pair(a,b)]++;
        mp[make_pair(b,a)]++;
        if(mp[make_pair(a,b)]==2){
            q.push(make_pair(a,b));
        }
    }
    while(!q.empty()){
        auto now=q.front();q.pop();
        int a=gf(now.first),b=gf(now.second);
        if(st[a].size()<st[b].size())swap(a,b);
        st[a].erase(b);st[b].erase(a);
        for(auto to:st[b]){
            mp[make_pair(b,to)]=mp[make_pair(to,b)]=0;
            st[to].erase(b);
            st[to].insert(a);st[a].insert(to);
            mp[make_pair(a,to)]++;
            mp[make_pair(to,a)]++;
            if(mp[make_pair(a,to)]==2){
                q.push(make_pair(a,to));
            }
        }
        st[b].clear();
        f[b]=a;
    }
    int num=0;
    for(int i=1;i<=n;i++)num+=(f[i]==i);
    puts(num==1?"YES":"NO");
    return 0;
}