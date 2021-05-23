//最短路模板
#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
struct node{
    int x,y;
    inline bool operator <(const node &a) const {
     return y>a.y;
    }
}b[1001];
int64_t getCurrentTime()
{    
    struct timeval tv;    
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
}    
int a[1001][1001],n,m,ok[1001][1001],ans[1001],vis[1001];
void floyd(){
    for(int k=1;k<=n;k++){
       for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++){
              if(a[i][j]>a[i][k]+a[k][j]){
                  a[i][j]=a[i][k]+a[k][j];
              }
          }
    }
}
void Dijkstra(int s){
memset(ans,0x3f,sizeof(ans));
priority_queue<node>q;
q.push((node){s,0});
ans[s]=0;
while(!q.empty()){
    node now=q.top();
    q.pop();
    if(ans[now.x]!=now.y)continue;
    for(int i=1;i<=n;i++){
        if(ok[now.x][i]&&ans[i]>ans[now.x]+a[now.x][i]){
            ans[i]=ans[now.x]+a[now.x][i];
            q.push(node{i,ans[i]});
        }
    }
}
}
void SPFA(int s){
memset(ans,0x3f,sizeof(ans));
queue<int>q;
q.push(s);
ans[s]=0;
vis[s]=1;
while(!q.empty()){
    int now=q.front();
    q.pop();
    vis[now]=0;
    for(int i=1;i<=n;i++){
        if(ok[now][i]&&ans[i]>ans[now]+a[i][now]){
            ans[i]=ans[now]+a[i][now];
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
}
int main(){
    cout<<"n<=1000 m<=1000 s,e<=n"<<endl;
    int type,s,e;
    cin>>n>>m>>s>>e;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        a[x][y]=a[y][x]=l;
        ok[x][y]=ok[y][x]=1;
    }
    cout<<"folyd:1,Dijkstra:2,SPFA:3"<<endl;
    cin>>type;
    long long tmp=getCurrentTime();
    if(type==1){
    floyd();
    printf("finish , a[s][e]=%d use %lld ms\n",a[s][e],getCurrentTime()-tmp);
    }
    else if (type==2){
    Dijkstra(s);
    printf("finish , ans[e]=%d use %lld ms\n",ans[e],getCurrentTime()-tmp);
    }
    else{
    SPFA(s);
    printf("finish , ans[e]=%d use %lld ms\n",ans[e],getCurrentTime()-tmp);
    }
    system("pause");
    return 0;
}