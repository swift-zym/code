//
// Created by swift on 2020/7/31.
//

#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,sum,ls,rs;
}a[4000000];
int cnt,rt[100001];
int n,m;
void pushup(int now){
    a[now].sum=a[a[now].ls].sum+a[a[now].rs].sum;
}
int add(int now,int pos,int l,int r,int id){
    if(!now){
        now=++cnt;
    }
    //cout<<now<<"->"<<l<<"->"<<r<<endl;
    if(l==r){
        a[now].sum++;
        a[now].id=id;
        return now;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        a[now].ls=add(a[now].ls,pos,l,mid,id);
    }
    else{
        a[now].rs=add(a[now].rs,pos,mid+1,r,id);
    }
    pushup(now);
    //cout<<now<<"<-"<<a[now].ls<<"<-"<<a[now].rs<<endl;
    return now;
}
int ask(int now,int l,int r,int k){
    if(!now||a[now].sum<k)return -1;
    if(l==r){
        return a[now].id;
    }
    int mid=(l+r)/2;
    if(a[a[now].ls].sum>=k){
        return ask(a[now].ls,l,mid,k);
    }
    else{
        return ask(a[now].rs,mid+1,r,k-a[a[now].ls].sum);
    }
}
int mem(int x,int y,int l,int r){
    if(!x)return y;
    if(!y)return x;
    int mid=(l+r)/2;
    a[x].sum+=a[y].sum;
    a[x].ls=mem(a[x].ls,a[y].ls,l,mid);
    a[x].rs=mem(a[x].rs,a[y].rs,mid+1,r);
    pushup(x);
    return x;
}
int f[100001];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
int main(){
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        rt[i]=add(rt[i],x,1,n,i);
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x=gf(x);y=gf(y);
        if(x!=y){
            f[y]=x;
            rt[x]=mem(rt[x],rt[y],1,n);
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        char c=getchar();
        while(c!='Q'&&c!='B')c=getchar();
        int x,y;
        scanf("%d%d",&x,&y);
        if(c=='Q'){
            x=gf(x);
            printf("%d\n",ask(rt[x],1,n,y));
        }
        else{
            x=gf(x);y=gf(y);
            if(x!=y){
                f[y]=x;
                rt[x]=mem(rt[x],rt[y],1,n);
            }
        }
    }
    return 0;
}