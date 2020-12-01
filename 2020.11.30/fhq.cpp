#include<bits/stdc++.h>
using namespace std;
class FhqTreap{
    public:
    struct Node{
        int ls,rs,siz,v,rnd,num;
    }data[30000000];
    int tot;
    int root;
    int clone(int x){
        data[++tot]=data[x];
        return tot;
    }
    int newNode(int v){
        data[++tot]={0,0,1,v,rand()};
        return tot;
    }
    void pushup(int now){
        data[now].siz=data[data[now].ls].siz+data[data[now].rs].siz+1;
    }
    void split(int now,int v,int &x,int &y){
        if(!now){
            x=y=0;
            return;
        }
        now=clone(now);
        if(v>=data[now].v){
            x=now;
            split(data[now].rs,v,data[x].rs,y);
        }
        else{
            y=now;
            split(data[now].ls,v,x,data[y].ls);
        }
        pushup(now);
    }
    int find(int now,int k){
        //cout<<now<<" "<<k<<endl;
        if(k==data[data[now].ls].siz+1)return data[now].v;
        if(k<=data[data[now].ls].siz){
            return find(data[now].ls,k);
        }
        else{
            return find(data[now].rs,k-data[data[now].ls].siz-1);
        }
    }
    public:
    int merge(int x,int y){
        if(x==0||y==0){
            return x|y;
        }
        if(data[x].rnd<data[y].rnd){
            x=clone(x);
            data[x].rs=merge(data[x].rs,y);
            pushup(x);
            return x;
        }
        else{
            y=clone(y);
            data[y].ls=merge(x,data[y].ls);
            pushup(y);
            return y;
        }
    }
    void insert(int v){
        int x,y;
        split(root,v,x,y);
        x=merge(x,newNode(v));
        root=merge(x,y);
    }
    int at(int v){
        return find(root,v);
    }
    int pre(int v){
        int x,y;
        split(root,v-1,x,y);
        /*puts("----");
        print(x);
        puts("\n---");
        print(y);
        puts("");*/
        int ans=find(x,data[x].siz);
        merge(x,y);
        return ans;
    }
    int nxt(int v){
        int x,y;
        split(root,v,x,y);
        int ans=find(y,1);
        merge(x,y);
        return ans;
    }
    int rank(int v){
        int x,y;
        split(root,v-1,x,y);
        int ans=data[x].siz+1;
        merge(x,y);
        return ans;
    }
    void remove(int v){
        int x,y,z;
        split(root,v-1,x,y);
        split(y,v,y,z);
        y=merge(data[y].ls,data[y].rs);
        x=merge(x,y);
        root=merge(x,z);
    }
    void print(int now){
        if(now==-1)now=root;
        if(data[now].ls)print(data[now].ls);
        cout<<data[now].v<<" ";
        if(data[now].rs)print(data[now].rs);
    }
}fhqTreap;
int roots[500001];
int main(){
    //freopen("P3369.out","w",stdout);
    srand(time(0));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int v,opt,x;
        scanf("%d%d%d",&v,&opt,&x);
        fhqTreap.root=roots[v];
        switch (opt){
        case 1:
            fhqTreap.insert(x);
            break;
        case 2:
            fhqTreap.remove(x);
            break;
        case 3:
            printf("%d\n",fhqTreap.rank(x));
            break;
        case 4:
            printf("%d\n",fhqTreap.at(x));
            break;
        case 5:
            printf("%d\n",fhqTreap.pre(x));
            break;

        default:
            printf("%d\n",fhqTreap.nxt(x));
            break;
        }
        roots[i]=fhqTreap.root;
        //fhqTreap.print(-1);
        //puts("");
    }
    #ifdef WIN32
    //system("pause");
    #endif
    return 0;
}