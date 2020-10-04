#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int h[600][600];
int mi,vis[600][600];
int add[600][600];
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
int col;
struct node{
    int x,y,v;
    bool operator <(const node &t)const{
        return v<t.v;
    }
};
vector<node>q;
void dfs(int x,int y){
    if(x==0||y==0||x>n||y>m){
        vis[x][y]=-1;
        return;
    }
    q.push_back({x,y,0});
    vis[x][y]=col;
    for(int i=0;i<=3;i++){
        int nx=x+mx[i],ny=y+my[i];
        if(vis[nx][ny]==vis[x][y])continue;
        if(h[nx][ny]>=h[x][y]){
            if(vis[nx][ny]==-1){
                mi=min(mi,h[nx][ny]);
            }
            if(!vis[nx][ny])
            dfs(nx,ny);
        }
    }
}
int tmp;
void solve(int x,int y){
    if(mi-h[x][y]>0)
    tmp+=(mi-h[x][y]);
    add[x][y]=1;
    for(int i=0;i<=3;i++){
        int nx=x+mx[i],ny=y+my[i];
        if(add[nx][ny])continue;
        if(vis[x][y]==vis[nx][ny]){
            solve(nx,ny);
        }
    }
}
int sum;
bool cmp(int a,int b){
    return a>b;
}
vector<int>v;
int ans;
vector<node>vv;
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]!=-1){
                cout<<"0 ";
            }
            else if(vis[i][j]==0){
                cout<<"- ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        scanf("%d",&h[i][j]);
        vv.push_back({i,j,h[i][j]});
    }
    for(int i=0;i<=n+1;i++){
        h[i][0]=h[i][m+1]=1e8;
    }
    for(int i=0;i<=m+1;i++){
        h[0][i]=h[n+1][i]=1e8;
    }
    sort(vv.begin(),vv.end());
    for(int i=0;i<vv.size();i++){
        if(!vis[vv[i].x][vv[i].y]){
            ++col;
            mi=1e8;
            dfs(vv[i].x,vv[i].y);
            for(auto j=q.begin();j!=q.end();j++){
                node now=*j;
                for(int j=0;j<=3;j++){
                    int nx=now.x+mx[j],ny=now.y+my[j];
                    if(vis[now.x][now.y]!=vis[nx][ny]&&h[now.x][now.y]>h[nx][ny]){
                        vis[now.x][now.y]=-1;
                        mi=min(mi,h[now.x][now.y]);
                    }
                }
            }
            q.clear();
            tmp=0;
            solve(vv[i].x,vv[i].y);
            sum+=tmp;
            //cout<<vv[i].x<<" "<<vv[i].y<<" "<<tmp<<" "<<mi<<endl;
            //print();
            //system("pause");
            v.push_back(tmp);
        }
    }
    while(v.size()!=n*m)v.push_back(0);
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=k;i++){
        sum-=v[i-1];
        ans^=sum;
        //cout<<sum<<" "<<ans<<endl;
    }
    printf("%d\n",ans);
    return 0;
}