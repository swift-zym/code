#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int h[600][600];
int w[600][600];
int vis[600][600];
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
void dfs(int x,int y,int v){
    //cout<<x<<" "<<y<<" "<<v<<endl;
    w[x][y]=max(h[x][y],v);
    for(int i=0;i<=3;i++){
        int nx=x+mx[i],ny=y+my[i];
        if(nx<1||nx>n||ny<1||ny>m)continue;
        if(w[nx][ny]<=max(v,h[nx][ny]))continue;
        dfs(nx,ny,max(v,h[nx][ny]));
    }
}
struct node{
    int x,y,v;
    bool operator <(const node &t)const{
        return v<t.v;
    }
};
vector<node>v;
int solve(){
    int val=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        val+=w[i][j]-h[i][j];
    }
    return val;
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        scanf("%d",&h[i][j]);
        v.push_back({i,j,h[i][j]});
        w[i][j]=1e8;
    }
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        memset(vis,0,sizeof(vis));
        dfs(v[i].x,v[i].y,v[i].v);
        ans^=solve();
        //print();
        //cout<<solve()<<endl;
        //system("pause");
    }
    cout<<ans<<endl;
    return 0;
}