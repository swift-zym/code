//题目名称：喷水装置
#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,w;
    double l,r;
}a[15001];
inline bool cmp(node a,node b){
    return a.l<b.l;
}
void preWork(int W,int n,...){
    for(int i=1;i<=n;i++){
        a[i].l=double(a[i].x)-sqrt(double(pow(a[i].w,2))-double(pow(double(W)/2,2)));
        a[i].r=double(a[i].x)+sqrt(double(pow(a[i].w,2))-double(pow(double(W)/2,2)));
        if(a[i].w<double(W)/2.0)a[i].l=a[i].r=1e8;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int l=1;l<=t;l++){
        int n,L,W,ans=1;
        scanf("%d%d%d",&n,&L,&W);
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].w);
        preWork(W,n);
        sort(a+1,a+n+1,cmp);
        int now,id=-1;
        double maxn=-1;
        for(int i=1;i<=n;i++){
            if(a[i].l>0)break;
            if(a[i].r>maxn)maxn=a[i].r,id=i;
        }
        if(id==-1){
            printf("-1\n");
            continue;
        }
        now=id;
        while(a[now].r<L){
            id=-1;
            for(int i=now+1;i<=n;i++){
                if(a[i].l>a[now].r)break;
                if(a[i].r>maxn)maxn=a[i].r,id=i;
            }
            if(id==-1){
            break;
            }
            now=id;
            ans++;
        }
        if(id==-1){
            printf("-1\n");
        }
        else
        printf("%d\n",ans);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}