#include<bits/stdc++.h>
using namespace std;
struct tree{
    struct node{
        int l,r,ls,rs,v;
    }a[6000000];
    int tot=-1;
    int newNode(int l,int r){
        a[++tot]={l,r,-1,-1,0};
        return tot; 
    }
    int newNode(int from){
        a[++tot]=a[from];
        return tot;
    }
    int build(int now){
        if(a[now].l==a[now].r)return now;
        int mid=(a[now].l+a[now].r)/2;
        a[now].ls=build(newNode(a[now].l,mid));
        a[now].rs=build(newNode(mid+1,a[now].r));
        return now;
    }
    void build(int l,int r){
        int idx=newNode(l,r);
        build(idx);
    }
    void pushup(int now){
        a[now].v=a[a[now].ls].v+a[a[now].rs].v;
    }
    int add(int now,int pos){
        now=newNode(now);
        if(a[now].l==a[now].r){
            a[now].v+=1;
            return now;
        }
        int mid=(a[now].l+a[now].r)/2;
        if(pos<=mid){
            a[now].ls=add(a[now].ls,pos);
        }
        else{
            a[now].rs=add(a[now].rs,pos);
        }
        pushup(now);
        return now;
    }
    int query(int pre,int now,int k){
        //cout<<pre<<" "<<now<<endl;
        if(a[now].l==a[now].r){
            return a[now].l;
        }
        int mid=(a[now].l+a[now].r)/2;
        int lsiz=a[a[now].ls].v-a[a[pre].ls].v;
        int rsiz=a[a[now].rs].v-a[a[pre].rs].v;
        if(lsiz>k){
            return query(a[pre].ls,a[now].ls,k);
        }
        else if(rsiz>k){
            return query(a[pre].rs,a[now].rs,k);
        }
        else{
            return -1;
        }
    }
}base;
int roots[300001];
int n,c;
int main(){
    scanf("%d%d",&n,&c);
    base.build(1,c);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        roots[i]=base.tot+1;
        base.add(roots[i-1],a);
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        int v=base.query(roots[l-1],roots[r],(r-l+1)/2);
        if(v==-1){
            puts("no");
        }
        else{
            printf("yes %d\n",v);
        }
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}