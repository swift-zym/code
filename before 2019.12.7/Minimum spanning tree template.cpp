//最小生成树模板
#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
int n,e,f[5001],cnt2,lowcost[5001],mst[5001],mapp[5001][5001];
struct edge{
    int x,y,w;
}a[200001];
edge out[200001];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int getfa(int now){
    return f[now]==now?now:getfa(f[now]);
}
int kruskal(){
    int ans=0,cnt=0;
    sort(a+1,a+e+1,cmp);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=e&&cnt<n-1;i++){
        int l=a[i].x,r=a[i].y;
        if(getfa(l)!=getfa(r))
        {
            cnt++;
            f[getfa(l)]=r;
            out[++cnt2]=a[i];
            ans+=a[i].w;
        }
    }
    return ans;
}
int prim(int u){
    int ans=0;
    for(int i=1;i<=n;i++){
           lowcost[i]=mapp[1][i];
           mst[i]=u;
    }
    mst[u]=-1;
    for(int i=1;i<n;i++){
        int minn=1<<30,now=-1;
        for(int j=1;j<=n;j++){
            if(mst[j]!=-1&&lowcost[j]<minn){
                minn=lowcost[j];
                now=j;
            }
        }
        if(now!=-1){
        ans+=lowcost[now];
        out[i]=(edge){mst[now],now,lowcost[now]};
        mst[now]=-1;
        for(int j=1;j<=n;j++){
            if(mst[j]!=-1&&lowcost[j]>mapp[now][j]){
                lowcost[j]=mapp[now][j];
                mst[j]=now;
            }
        }
        }
    }
    return ans;
}
int64_t getCurrentTime()
{    
    struct timeval tv;    
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
}    
int main(){
    memset(mapp,0x7f,sizeof(mapp));
    #ifdef WIN32
    cout<<"n<=5000 e<=200000"<<endl;
    #endif
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>a[i].x>>a[i].y>>a[i].w;
        mapp[a[i].x][a[i].y]=mapp[a[i].y][a[i].x]=min(a[i].w,mapp[a[i].y][a[i].x]);
    }
    for(int i=1;i<=n;i++){
        mapp[i][i]=0;
    }
    int type=2;
    long long tmp;
    #ifdef WIN32
    cout<<"kruskal:1 prim:2"<<endl;
    cin>>type;
    tmp=getCurrentTime();
    #endif
    if(type==1){
    #ifdef WIN32
    printf("find min ans=%d use %lld ms\n",kruskal(),getCurrentTime()-tmp);
    for(int i=1;i<n;i++){
        printf("%d to %d\n",out[i].x,out[i].y);
    }
    #endif
    int out_=kruskal();
    printf("%d\n",out_>10000?0:out_);
    }else{
    #ifdef WIN32
    printf("find min ans=%d use %lld ms\n",prim(1),getCurrentTime()-tmp);    
    for(int i=1;i<n;i++){
        printf("%d to %d\n",out[i].x,out[i].y);
    }
    #endif
    int out__=prim(1);
    printf("%d\n",out__);
    }
    #ifdef WIN32
    system("pause");
    #endif
}
