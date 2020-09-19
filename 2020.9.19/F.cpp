#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,lans,rans,ans;
    int tag;
}a[200001];
bool isFull(int now){
    return a[now].ans==(a[now].r-a[now].l+1);
}
void setFull(int now){
    a[now].lans=a[now].rans=a[now].ans=a[now].r-a[now].l+1;
    a[now].tag=1;
}
void setNull(int now){
    a[now].lans=a[now].rans=a[now].ans=0;
    a[now].tag=2;
}
void pushdown(int now){
    if(a[now].tag==1){
        a[now].tag=0;
        setFull(now*2);
        setFull(now*2+1);
    }else if(a[now].tag==2){
        a[now].tag=0;
        setNull(now*2);
        setNull(now*2+1);
    }
}
void pushup(int now){

    a[now].lans=isFull(now*2)?a[now*2].ans+a[now*2+1].lans
                             :a[now*2].lans;
    a[now].rans=isFull(now*2+1)?a[now*2+1].ans+a[now*2].rans
                               :a[now*2+1].rans;
    a[now].ans=max(a[now].lans,max(a[now].rans,a[now*2].rans+a[now*2+1].lans));
    a[now].ans=max(a[now].ans,max(a[now*2].ans,a[now*2+1].ans));
}
void add(int now,int l,int r,int v=0){
    //cout<<"set "<<l<<" "<<r<<" "<<v<<endl;
    int L=a[now].l,R=a[now].r;
    if(L==l&&R==r){
        if(!v)
        setFull(now);
        else
        setNull(now);
        return;
    }
    pushdown(now);
    int mid=(L+R)/2;
    if(l>mid)add(now*2+1,l,r,v);
    else if(r<=mid)add(now*2,l,r,v);
    else{
        add(now*2,l,mid,v);
        add(now*2+1,mid+1,r,v);
    }
    pushup(now);
}
int query(int now,int l){
    //cout<<">"<<now<<" "<<a[now].l<<" "<<a[now].r<<endl;
    if(a[now].ans<l){
        return 0;
    }
    pushdown(now);
    //cout<<now<<" "<<a[now].ans<<" "<<a[now].lans<<" "<<a[now].rans<<endl;
    //cout<<">"<<a[now*2].ans<<" "<<a[now*2+1].ans<<endl;
    if(a[now*2].ans>=l){
        return query(now*2,l);
    }
    else if(a[now*2].rans+a[now*2+1].lans>=l){
        int mid=(a[now].l+a[now].r)/2,val=mid-a[now*2].rans+1;
        add(1,mid-a[now*2].rans+1,mid-a[now*2].rans+l,1);
        return val;
    }
    else{
        return query(now*2+1,l);
    }
}
void build(int now,int l,int r){
    a[now].l=l;a[now].r=r;
    int mid=(l+r)/2;
    a[now].lans=a[now].rans=a[now].ans=r-l+1;
    if(l==r)return;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
}
int n,m;
int main(){
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        if(t==1){
            int l;
            scanf("%d",&l);
            printf("%d\n",query(1,l));
        }
        else{
            int x,l;
            scanf("%d%d",&x,&l);
            add(1,x,x+l-1);
        }
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}