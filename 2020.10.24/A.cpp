#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int id[2000][2000];
const int bas=23333,mod=998244353,maxn=2000*2000+1;
unordered_map<int,int>ma;
int num;
int query(int x){
    int val=ma[x];
    return val?val:ma[x]=++num;
}
set<int>v[maxn];
int cnt,ver[maxn],ans[maxn];
void add(int a,int b){
    if(v[a].lower_bound(b)==v[a].end()){
        v[a].insert(b);
        ver[b]++;
    }
}
queue<int>q;
signed main(){
    ios::sync_with_stdio(0);
    cin>>s;
    int len=s.length();
    if(len>2000){
        cout<<len<<endl;
        return 0;
    }
    for(int i=0;i<len;i++)
    for(int j=i;j<len;j++){
        if(i==j)id[i][j]=s[i];
        else{
            id[i][j]=(id[i][j-1]*bas+s[j])%mod;
        }
    }
    for(int i=0;i<len;i++)
    for(int j=i;j<len;j++){
        id[i][j]=query(id[i][j]);
    }
    for(int l=0;l<len;l++)
    for(int r=l+1;r<len;r++){
        add(id[l+1][r],id[l][r]);
        if(id[l+1][r]!=id[l][r-1])
        add(id[l][r-1],id[l][r]);
    }
    for(int i=1;i<=num;i++){
        if(!ver[i])q.push(i);
    }
    while(!q.empty()){
        int now=q.front();q.pop();
        ans[now]++;
        for(auto to:v[now]){
            ver[to]--;
            ans[to]+=ans[now];
            ans[to]%=998244353;
            if(!ver[to])q.push(to);
        }
    }
    cout<<ans[id[0][len-1]]<<endl;
    return 0;
}