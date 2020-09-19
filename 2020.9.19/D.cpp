#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
struct node{
    int x,y;
    node operator -(const node &t){
        node tmp={x-t.x,y-t.y};
        return tmp;
    }
    node operator +(const node &t){
        node tmp={x+t.x,y+t.y};
        return tmp;
    }
}a,b;
int f[50000];
node l[50000];
int mxdep[50000];
void init(){
    for(int i=1;i<=n;i++){
        f[i]=i;
        l[i]={0,0};
    }
}
node query(int x){
    node lx={0,0};
    while(f[x]!=x){
        lx=lx+l[x];
        x=f[x];
    }
    return lx;
}
int gf(int x){
    return f[x]==x?x:gf(f[x]);
}
void mem(int x,int y,node len){
    //cout<<x<<" "<<y<<"{"<<len.x<<" "<<len.y<<"}"<<endl;
    node lx=len,ly={0,0};
    while(f[x]!=x){
        lx=lx-l[x];
        x=f[x];
    }
    while(f[y]!=y){
        ly=ly+l[y];
        y=f[y];
    }
    //{7,0}
    //{15,0}
    //{}
    if(mxdep[x]<mxdep[y]){
        f[x]=y;
        l[x]=lx+ly;
    }
    else{
        mxdep[x]=max(mxdep[x],mxdep[y]+1);
        f[y]=x;
        node tmp=lx+ly;
        tmp.x=-tmp.x;
        tmp.y=-tmp.y;
        l[y]=tmp;
    }
}
struct que{
    int f1,f2,id;
};
vector<que>q[50000];
int s[50000],e[50000];
node tmp[50000];
node make(int len,char c){
    if(c=='N'){return {len,0};}
    if(c=='S'){return {-len,0};}
    if(c=='E'){return {0,len};}
    if(c=='W'){return {0,-len};}
}
int ans[50000];
int main(){
    //freopen("navigate.in","r",stdin);
    //freopen("navigate.out","w",stdout);
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<n;i++){
        int v;
        scanf("%d%d%d",&s[i],&e[i],&v);
        char c=getchar();
        while(c!='N'&&c!='E'&&c!='S'&&c!='W')c=getchar();
        tmp[i]=make(v,c);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int f1,f2,j;
        scanf("%d%d%d",&f1,&f2,&j);
        q[j].push_back({f1,f2,i});
    }
    for(int i=1;i<n;i++){
        mem(s[i],e[i],tmp[i]);
        for(int j=0;j<q[i].size();j++){
            if(gf(q[i][j].f1)!=gf(q[i][j].f2)){
                ans[q[i][j].id]=-1;
                continue;
            }
            node l1=query(q[i][j].f1),l2=query(q[i][j].f2);
            //cout<<gf(q[i][j].f1)<<" "<<l1.x<<" "<<l1.y<<" "<<l2.x<<" "<<l2.y<<endl;
            //cout<<">"<<q[i][j].f1<<" "<<q[i][j].f2<<endl;
            l1=l1-l2;
            ans[q[i][j].id]=abs(l1.x)+abs(l1.y);
        }
        /*puts("----");
        for(int i=1;i<=n;i++){
            cout<<gf(i)<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<query(i).x<<" "<<query(i).y<<",";
        }
        cout<<endl;
        puts("----");*/
    }
    for(int i=1;i<=k;i++){
        printf("%d\n",ans[i]);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
/*
8 7
1 2 1 S
3 4 5 S
5 6 8 S
7 8 2 S
3 2 3 N
7 6 13 N
5 4 7 N
4
1 3 1
1 4 5
3 4 2
4 5 7
*/