#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int l,r,siz,sum,ls,rs;
};
node data[20000000];
struct node_manager{
    int cnt;
    int new_node(int l,int r){
        data[cnt]={l,r,0,0,-1,-1};
        return cnt++;
    }
}base;
struct tree{
    int root;
    void build(int n){
        root=base.new_node(1,n);
    }
    void pushup(int now){
        data[now].sum=data[now].siz=0;
        if(data[now].ls!=-1){
            data[now].sum+=data[data[now].ls].sum;
            data[now].siz+=data[data[now].ls].siz;
        }
        if(data[now].rs!=-1){
            data[now].sum+=data[data[now].rs].sum;
            data[now].siz+=data[data[now].rs].siz;
        }
    }
    void add(int now,int pos,int v){
        //cout<<now<<" "<<pos<<":"<<v<<endl;
        if(data[now].l==data[now].r){
            data[now].siz+=v;
            data[now].sum=data[now].l*data[now].siz;
            return;
        }
        int mid=(data[now].l+data[now].r)/2;
        if(pos<=mid){
            if(data[now].ls==-1){
                int v=base.new_node(data[now].l,mid);
                //cout<<"!!"<<v<<endl;
                data[now].ls=v;
                //data[now].ls=build_node(data[now].l,mid);
                //cout<<"set l "<<data[now].ls<<endl;
            }
            //cout<<"goto l"<<" "<<data[now].ls<<endl;
            add(data[now].ls,pos,v);
        }
        else{ 
            if(data[now].rs==-1){
                int v=base.new_node(mid+1,data[now].r);
                data[now].rs=v;
            }
            //cout<<"goto r"<<endl;
            add(data[now].rs,pos,v);
        }
        pushup(now);
    }
    int rank(int now,int pos){
        if(data[now].l==data[now].r){
            return 1;
        }
        int mid=(data[now].l+data[now].r)/2;
        if(pos<=mid){
            int ans=rank(data[now].ls,pos);
            if(data[now].rs!=-1){
                ans+=data[data[now].rs].siz;
            }
            return ans;
        }
        else{
            return rank(data[now].rs,pos);
        }
    }
    int kth(int now,int pos){
        if(data[now].l==data[now].r){
            return data[now].l;
        }
        int rsiz=data[now].rs==-1?0:data[data[now].rs].siz;
        if(rsiz>=pos){
            return kth(data[now].rs,pos);
        }
        else{
            return kth(data[now].ls,pos-rsiz);
        }
    }
    int kth_sum(int now,int pos){
        //cout<<now<<" "<<pos<<endl;
        //cout<<">"<<data[now].ls<<" "<<data[now].rs<<endl;
        if(data[now].l==data[now].r){
            //cout<<"Add "<<now<<" "<<data[now].sum<<endl;
            return data[now].l*min(pos,data[now].siz);
        }
        int rsiz=data[now].rs==-1?0:data[data[now].rs].siz;
        int rsum=data[now].rs==-1?0:data[data[now].rs].sum;
        if(rsiz>=pos){
            if(data[now].rs==-1)return 0;
            return kth_sum(data[now].rs,pos);
        }
        else{
            if(data[now].ls==-1)return rsum;
            //cout<<"Add "<<rsum<<endl;
            return kth_sum(data[now].ls,pos-rsiz)+rsum;
        }
    }
}trees[300001];
int n,m;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
#undef int
signed main(int argc,char *argv[]){
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    #define int long long
    //freopen("ex_grimoire2.in","r",stdin);
    //freopen("ex_grimoire2.my.out","w",stdout);
    for(int i=0;i<=300000;i++)trees[i].build(1000000000);
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        char c=getchar();
        while(c!='R'&&c!='B')c=getchar();
        int t=read(),p=read();
        if(c=='B'){
            trees[t].add(trees[t].root,p,1);
            if(trees[t].rank(trees[t].root,p)<=t){
                trees[0].add(trees[0].root,p,1);
                if(data[trees[t].root].siz>t){
                    trees[0].add(trees[0].root,trees[t].kth(trees[t].root,t+1),-1);
                }
            }
        }
        else{
            if(trees[t].rank(trees[t].root,p)<=t){
                trees[0].add(trees[0].root,p,-1);
                if(data[trees[t].root].siz>t){
                    trees[0].add(trees[0].root,trees[t].kth(trees[t].root,t+1),1);
                }
            }
            trees[t].add(trees[t].root,p,-1);
        }
        //cout<<">"<<trees[0].data[0].siz<<endl;
        printf("%lld\n",trees[0].kth_sum(trees[0].root,n));
    }   
    return 0;
}
//120478