#include<bits/stdc++.h>
using namespace std;
int n,s[21],a[21],b[21],sa,sb;
struct node{
    int x,y;
    bool operator <(const node &t)const{
        if(x!=t.x)
        return x<t.x;
        return y<t.y;
    }
};
vector<node>v;
void dfs(int deep){
    if(deep==n+1){
        int x=0,y=0;
        for(int i=1;i<deep;i++){
            if(s[i])x+=a[i];
            else y+=b[i];
        }
        if(x<=sa&&y<=sb){
            v.push_back({x,y});
        }
        return;
    }
    s[deep]=0;
    dfs(deep+1);
    s[deep]=1;
    dfs(deep+1);
}
int mx=INT_MAX,ax,ay;
void check(int x,int y){
    if(x>sa||y>sb)return;
    if(x+y<mx){
        mx=x+y;
        ax=x;ay=y;
    }
    else if(x+y==mx&&x<ax){
        ax=x;ay=y;
    }
}
int main(){
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];sa+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];sb+=b[i];
    }
    dfs(1);
    sort(v.begin(),v.end());
    int mx=0;
    for(int i=v.size()-1;i>=0;i--){
        check(v[i].x+1,mx+1);
        mx=max(mx,v[i].y);
    }
    cout<<ax<<endl<<ay<<endl;
    return 0;
}