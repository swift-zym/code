#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tree{
    struct node{
        int l,r,siz,sum,ls,rs;
    };
    vector<node>data;
    void build(int n){
        data.push_back({1,n,0,0,-1,-1});
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
    int build_node(int l,int r){
        data.push_back({l,r,0,0,-1,-1});
        //cout<<"return "<<data.size()-1<<endl;
        return data.size()-1;
    }
    void add(int now,int pos,int v){
        if(now==-1){
            cerr<<"add error";
            exit(0);
        }
        //cout<<now<<" "<<pos<<":"<<v<<endl;
        if(data[now].l==data[now].r){
            data[now].siz+=v;
            data[now].sum=data[now].l*data[now].siz;
            return;
        }
        int mid=(data[now].l+data[now].r)/2;
        if(pos<=mid){
            if(data[now].ls==-1){
                int v=build_node(data[now].l,mid);
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
                int v=build_node(mid+1,data[now].r);
                data[now].rs=v;
            }
            //cout<<"goto r"<<endl;
            add(data[now].rs,pos,v);
        }
        pushup(now);
    }
    int rank(int now,int pos){
        if(now==-1){
            cerr<<"rank error";
            exit(0);
        }
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
        if(now==-1){
            cerr<<"kth error";
            exit(0);
        }
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
        if(now==-1){
            cerr<<"kth_sum error";
            exit(0);
        }
        //cout<<now<<" "<<pos<<endl;
        //cout<<">"<<data[now].ls<<" "<<data[now].rs<<endl;
        if(data[now].l==data[now].r){
            //cout<<"Add "<<now<<" "<<data[now].sum<<endl;
            return data[now].sum;
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
signed main(){
    freopen("ex_grimoire2.in","r",stdin);
    freopen("ex_grimoire2.my.out","w",stdout);
    for(int i=0;i<=300000;i++)trees[i].build(1000000000);
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        char c=getchar();
        while(c!='R'&&c!='B')c=getchar();
        int t=read(),p=read();
        if(c=='B'){
            trees[t].add(0,p,1);
            if(trees[t].rank(0,p)<=t){
                //cout<<"case 1"<<endl;
                //cout<<"add "<<p<<endl;
                trees[0].add(0,p,1);
                if(trees[t].data[0].siz>t){
                    //cout<<"case 2"<<endl;
                    trees[0].add(0,trees[t].kth(0,t+1),-1);
                }
            }
        }
        else{
            if(trees[t].rank(0,p)<=t){
                trees[0].add(0,p,-1);
                if(trees[t].data[0].siz>t){
                    trees[0].add(0,trees[t].kth(0,t+1),1);
                }
            }
            trees[t].add(0,p,-1);
        }
        //cout<<">"<<trees[0].data[0].siz<<endl;
        printf("%lld\n",trees[0].kth_sum(0,n));
    }   
    return 0;
}
