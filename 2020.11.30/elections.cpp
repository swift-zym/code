#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
int solve(string a){
    int vis[a.length()+1],x=0,y=0,ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<a.length();i++){
        x+=(a[i]=='C');y+=(a[i]=='T');
        if(y>x){
            vis[i]=1;
            ans++;
            y--;
        }
    }
    x=y=0;
    for(int i=a.length()-1;i>=0;i--){
        if(vis[i])continue;
        x+=(a[i]=='C');y+=(a[i]=='T');
        if(y>x){
            vis[i]=1;
            ans++;
            y--;
        }
    }
    return ans;
}
int main(){
    freopen("elections.in","r",stdin);
    freopen("elections.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>s>>q;
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;l--;r--;
        cout<<solve(s.substr(l,r-l+1))<<endl;
    }
    return 0;
}