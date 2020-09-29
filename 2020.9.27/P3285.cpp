#include<bits/stdc++.h>
using namespace std;
class tree{
    private:
    struct node{
        int l,r,ls,rs,v,tag;
    }a[10000000];
    int tot;
    public:
    void build(int mi,int mx){
        a[tot++]={mi,mx,-1,-1,0,0};
    }
    void pushup(int now){
        a[now].v=0;
        if(a[now].ls!=-1){
            a[now].v+=a[a[now].ls].v;
        }
        if(a[now].rs!=-1){
            a[now].v+=a[a[now].rs].v;
        }
        //if(a[now].v>a[now].r-a[now].l+1){
        //    system("pause");
        //}
    }
    void set(int x){
        a[x].tag=1;
        a[x].v=a[x].r-a[x].l+1;
    }
    void clear(int x){
        a[x].ls=a[x].rs=-1;
    }
    void pushdown(int now){ 
        int mid=(a[now].l+a[now].r)/2;
        if(mid==a[now].r)mid=a[now].l;
        if(a[now].ls==-1){
            a[now].ls=tot++;
            clear(a[now].ls);
        }
        if(a[now].rs==-1){
            a[now].rs=tot++;
            clear(a[now].rs);
        }
        a[a[now].ls].l=a[now].l;
        a[a[now].ls].r=mid;
        a[a[now].rs].l=mid+1;
        a[a[now].rs].r=a[now].r;
        if(a[now].tag){
            a[now].tag=0;
            set(a[now].ls);
            set(a[now].rs);
        }
    }
    void insert(int now,int pos,int v){
        //cout<<now<<" "<<pos<<" "<<v<<endl;
        //cout<<a[now].l<<" "<<a[now].r<<endl;
        if(a[now].l==a[now].r){
            a[now].v+=v;
            return;
        }
        pushdown(now);
        int mid=(a[now].l+a[now].r)/2;
        if(mid==a[now].r)mid=a[now].l;
        if(pos<=mid){
            insert(a[now].ls,pos,v);
        }
        else{
            insert(a[now].rs,pos,v);
        }
        pushup(now);
    }
    int kth(int now,int k){
        //cout<<a[now].l<<" "<<a[now].r<<" "<<k<<endl;
        //cout<<">"<<a[now].v<<endl;
        if(a[now].l==a[now].r){
            return a[now].l;
        }
        pushdown(now);
        if(a[a[now].ls].v>=k){
            return kth(a[now].ls,k);
        }
        else{
            return kth(a[now].rs,k-a[a[now].ls].v);
        }
    }
    int query(int now,int l,int r){
        //cout<<now<<" "<<l<<" "<<r<<endl;
        //cout<<a[now].l<<" "<<a[now].r<<endl;
        //cout<<">"<<a[now].l<<" "<<a[now].r<<endl;
        if(a[now].l==l&&a[now].r==r){
            //cout<<"+="<<a[now].v<<endl;
            return a[now].v;
        }
        pushdown(now);
        int mid=(a[now].l+a[now].r)/2;
        if(mid==a[now].r)mid=a[now].l;
        if(r<=mid)return query(a[now].ls,l,r);
        else if(l>mid)return query(a[now].rs,l,r);
        else {
            return query(a[now].ls,l,mid)+query(a[now].rs,mid+1,r);
        }
    }
    void add(int now,int l,int r){
        //cout<<now<<" "<<l<<" "<<r<<endl;
        //cout<<">"<<a[now].ls<<" "<<a[now].rs<<endl;
        if(a[now].l==l&&a[now].r==r){
            set(now);
            return;
        }
        pushdown(now);
        int mid=(a[now].l+a[now].r)/2;
        if(mid==a[now].r)mid=a[now].l;
        if(r<=mid)add(a[now].ls,l,r);
        else if(l>mid)add(a[now].rs,l,r);
        else{
            add(a[now].ls,l,mid);
            add(a[now].rs,mid+1,r);
        }
    }
}base;
unordered_map<int,int>height,id;
int n,m;
int a;
int mi,mx;
int main(){
    //freopen("input4.in","r",stdin);
    //freopen("input4.out","w",stdout);
    base.build(-1e9,1e9);
    scanf("%d%d",&n,&m);
    base.add(0,1,n);
    mi=1;mx=n;
    for(int i=1;i<=m;i++){
        int opt;
        scanf("%d",&opt);
        if(opt==1){
            int x,y;
            scanf("%d%d",&x,&y);
            x-=a;y-=a;
            if(height.find(x)==height.end()){
                id[x]=x;
                height[x]=x;
            }
            a=base.query(0,-1e9,height[x]);
            height[y]=height[x];
            id[height[y]]=y;
        }
        else if(opt==2){
            int x;
            scanf("%d",&x);
            x-=a;
            if(height.find(x)==height.end()){
                id[x]=x;
                height[x]=x;
            }
            a=base.query(0,-1e9,height[x]);
            //system("pause");
            base.insert(0,height[x],-1);
            //system("pause");
            height[x]=--mi;
            id[mi]=x;
            //cout<<"set "<<height[x]<<" "<<x<<endl;
            base.insert(0,height[x],1);
        }
        else if(opt==3){
            int x;
            scanf("%d",&x);
            x-=a;
            if(height.find(x)==height.end()){
                id[x]=x;
                height[x]=x;
            }
            a=base.query(0,-1e9,height[x]);
            base.insert(0,height[x],-1);
            height[x]=++mx;
            id[mx]=x;
            base.insert(0,height[x],1);
        }
        else if(opt==4){
            int x;
            scanf("%d",&x);
            x-=a;
            if(height.find(x)==height.end()){
                id[x]=x;
                height[x]=x;
            }
            int tmp=base.kth(0,x);
            if(id.find(tmp)==id.end())a=tmp;
            else a=id[tmp];
        }
        printf("%d\n",a);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}