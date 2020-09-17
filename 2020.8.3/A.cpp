//
// Created by swift on 2020/8/3.
//

#include<bits/stdc++.h>
#define INF 1e8
using namespace std;
int s,t;
int head[50000],nxt[400000],to[400000],len[400000],cnt=-1;
void add(int a,int b,int l,bool rev=0){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
    if(!rev){
        add(b,a,0,1);
    }
}
int tp[50000],dep[50000];
bool bfs(){
    queue<int>q;
    for(int i=s;i<=t;i++)dep[i]=INF;
    q.push(s);
    tp[s]=head[s];
    dep[s]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];i!=-1;i=nxt[i]){
            if(len[i]>0&&dep[to[i]]==INF){
                dep[to[i]]=dep[now]+1;
                tp[to[i]]=head[to[i]];
                if(to[i]==t){
                    return 1;
                }
                q.push(to[i]);
            }
        }
    }
    return 0;
}
int dinic(int now,int flow){
    //cout<<now<<" "<<flow<<endl;
    int sum=0;
    if(now==t)return flow;
    for(int i=tp[now];i!=-1;i=nxt[i]){
        if(!flow)break;
        tp[now]=i;
        if(dep[to[i]]==dep[now]+1&&len[i]>0){
            int k=dinic(to[i],min(flow,len[i]));
            if(!k){
                dep[to[i]]=INF;
            }
            sum+=k;
            flow-=k;
            len[i]-=k;
            len[i^1]+=k;
        }
    }
    return sum;
}
int n,m;
int a[201][201];
int mx[]={1,-1,1,-1,2,-2,2,-2};
int my[]={2,2,-2,-2,1,1,-1,-1};
int decode(int i,int j){
    return m*(i-1)+j;
}
bool isBlack(int i,int j){
    return (i+j)%2==0;
}
int num=0;
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c!='*'&&c!='#')c=getchar();
            a[i][j]=(c=='*');
        }
    }
    s=0;t=n*m+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(!a[i][j])continue;
            num++;
            if(isBlack(i,j)){
                add(s,decode(i,j),1);
                for(int k=0;k<=7;k++){
                    int x=i+mx[k],y=j+my[k];
                    if(x<1||x>n||y<1||y>m)continue;
                    if(!a[x][y])continue;
                    //printf("(%d,%d)->(%d,%d)\n",i,j,x,y);
                    add(decode(i,j),decode(x,y),1);
                }
            }
            else{
                add(decode(i,j),t,1);
            }
        }
    int ans=0;
    while(bfs()){
        ans+=dinic(s,INF);
    }
    printf("%d\n",num-ans);
    return 0;
}
/*
 * BW*W*W
 * W*WBW*
 * BWBWBW
 * W*WBW*
 * BW*W*W
 */