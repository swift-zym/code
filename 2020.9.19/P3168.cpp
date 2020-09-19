#include<bits/stdc++.h>
#define int long long
using namespace std;
class tree{
private:
    struct node{
        int l,r,ls,rs,sum,siz;
    }a[10000000];
    int tot;
    int newNode(int l,int r){
        a[++tot]={l,r,-1,-1,0,0};
        return tot;
    }
    int copyNode(int from){
        //cout<<"copy "<<tot+1<<":"<<from<<endl;
        a[++tot]=a[from];
        //cout<<a[tot].l<<" "<<a[tot].r<<endl;
        return tot;
    }
    void pushup(int now){
        a[now].sum=0;
        a[now].siz=0;
        if(a[now].ls!=-1){
            a[now].sum+=a[a[now].ls].sum;
            a[now].siz+=a[a[now].ls].siz;
        }
        if(a[now].rs!=-1){
            a[now].sum+=a[a[now].rs].sum;
            a[now].siz+=a[a[now].rs].siz;
        }
    }
public:
    void build(int MAX_VALUE){
        a[0]={1,MAX_VALUE,-1,-1,0,0};
    }
    int size(){
        return tot;
    }
    int add(int from,int pos,int v,int __copy=1){
        int now;
        if(__copy){
            now=copyNode(from);
        }
        else{
            now=from;
        }
        int l=a[now].l,r=a[now].r;
        int mid=(l+r)/2;
        if(l==r){
            //cout<<"add "<<now<<" "<<v<<endl;
            a[now].sum+=v*l;
            a[now].siz+=v;
            //cout<<"->"<<a[now].siz<<endl;
            return now;
        }
        //cout<<pos<<" "<<mid<<endl;
        if(pos<=mid){
            //cout<<"go left"<<endl;
            if(a[now].ls==-1){
                a[now].ls=newNode(l,mid);
                add(a[now].ls,pos,v,false);
            }
            else
            a[now].ls=add(a[now].ls,pos,v);
        }
        else{
            //cout<<"go right"<<endl;
            if(a[now].rs==-1){
                a[now].rs=newNode(mid+1,r);
                add(a[now].rs,pos,v,false);
            }
            else
            a[now].rs=add(a[now].rs,pos,v);
        }
        pushup(now);
        //cout<<">"<<a[now].ls<<" "<<a[now].rs<<endl;
        return now;
    }
    int query(int now,int k){
        //cout<<now<<" "<<a[now].siz<<endl;
        int l=a[now].l,r=a[now].r;
        /*cout<<">"<<l<<" "<<r\
        <<" "<<a[now].ls<<" "<<a[now].rs<<endl;*/
        if(l==r){
            return min(k*l,a[now].sum);
        }
        if(a[now].siz==k){
            return a[now].sum;
        }
        int lsiz=a[now].ls==-1?0:a[a[now].ls].siz;
        int lsum=a[now].ls==-1?0:a[a[now].ls].sum;
        if(lsiz>=k){
            return query(a[now].ls,k);
        }
        else{
            if(a[now].rs==-1)return lsum;
            return lsum+query(a[now].rs,k-lsiz);
        }
    } 
}base;
int m,n;
vector<int>add[200000],del[200000];
int ver;
int roots[200000];
int times[200000];
int lastans=1;
signed main(){
    scanf("%lld%lld",&m,&n);
    base.build(20000000);
    for(int i=1;i<=m;i++){
        int s,e,p;
        scanf("%lld%lld%lld",&s,&e,&p);
        add[s].push_back(p);
        del[e+1].push_back(p);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<add[i].size();j++){
            roots[ver+1]=base.size()+1;
            base.add(roots[ver],add[i][j],1);
            ver++;
        }
        for(int j=0;j<del[i].size();j++){
            roots[ver+1]=base.size()+1;
            base.add(roots[ver],del[i][j],-1);
            ver++;
        }
        /*cout<<"time %"<<i<<" "\
        <<base.a[roots[ver]].siz<<" "\
        <<base.a[roots[ver]].l\
        <<" "<<base.a[roots[ver]].r\
        <<"("<<roots[ver]<<")"<<endl;*/
        times[i]=roots[ver];
    }
    for(int i=1;i<=n;i++){
        int x,a,b,c;
        scanf("%lld%lld%lld%lld",&x,&a,&b,&c);
        int k=1+(a*lastans+b)%c;
        //cout<<"decode:"<<x<<" "<<k<<endl;
        lastans=base.query(times[x],k);
        printf("%lld\n",lastans);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}