#pragma GCC optimize("Ofast")
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
string s,a="",b="",c="";
int mp[100],val[100];
int m,ans;
vector<int>v;
int dis[100][100];
int check(string s){
    int tmp=0;
    for(auto x:s){
        tmp*=10;
        tmp+=val[x-'A'];
    }
    return tmp;
}
int vis[26];
bool solve(int x){
    memset(vis,-1,sizeof(vis));
    vector<int>v;
    while(x){
        v.push_back(x%10);
        x/=10;
    }
    reverse(v.begin(),v.end());
    if(v.size()!=c.length())return 0;
    for(int i=0;i<c.length();i++){
        if(val[c[i]-'A']!=-1&&val[c[i]-'A']!=v[i])return 0;
        if(vis[c[i]-'A']!=-1&&vis[c[i]-'A']!=v[i])return 0;
        if(dis[c[i]-'A'][v[i]])return 0;
        vis[c[i]-'A']=v[i];
    }
    return 1;
}
void dfs(int deep){
    if(val[a[0]-'A']==0||val[b[0]-'A']==0)return;
    if(deep==v.size()){
        if(val[a[0]-'A']==0||val[b[0]-'A']==0)return;
        if(!solve(check(a)+check(b)))return;
        ans++;
        return;
    }
    for(int i=0;i<=9;i++){
        if(dis[v[deep]][i])continue;
        val[v[deep]]=i;
        dfs(deep+1);
    }
}
int main(){
    memset(val,-1,sizeof(val));
    cin>>s;
    int i=0;
    for(;s[i]!='+';i++){
        a+=s[i];
    }
    i++;
    for(;s[i]!='=';i++){
        b+=s[i];
    }
    i++;
    for(;i<s.length();i++){
        c+=s[i];
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        char c;int v;
        cin>>c>>v;
        dis[c-'A'][v]=1;
    }
    for(auto s:a)mp[s-'A']=1;
    for(auto s:b)mp[s-'A']=1;
    //for(auto s:c)mp[s-'A']=1;
    for(int i=0;i<=25;i++){
        if(mp[i])v.push_back(i);
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}