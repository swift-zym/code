//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
class FhqTreap{
    public:
    struct Node{
        int ls,rs,siz,v,rnd,id;
    }data[10000001];
    int tot;
    int root;
    stack<int>removedData;
    int newNode(int v,int id){
        int idx;
        if(!removedData.empty()){
            idx=removedData.top();
            removedData.pop();
        }
        else idx=++tot;
        data[idx]={0,0,1,v,rand(),id};
        return idx;
    }
    void removeNode(int idx){
        removedData.push(idx);
    }
    void pushup(int now){
        data[now].siz=data[data[now].ls].siz+data[data[now].rs].siz+1;
    }
    void split(int now,int v,int &x,int &y){
        if(!now){
            x=y=0;
            return;
        }
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
        if(k==data[data[now].ls].siz+1)return now;
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
            data[x].rs=merge(data[x].rs,y);
            pushup(x);
            return x;
        }
        else{
            data[y].ls=merge(x,data[y].ls);
            pushup(y);
            return y;
        }
    }
    int insert(int v,int id){
        int x=0,y=0;
        int idx=newNode(v,id);
        split(root,v,x,y);
        x=merge(x,idx);
        root=merge(x,y);
        return idx;
    }
    int at(int v){
        return data[find(root,v)].id;
    }
    int pre(int v){
        int x=0,y=0;
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
        int x=0,y=0;
        split(root,v,x,y);
        int ans=find(y,1);
        merge(x,y);
        return ans;
    }
    int rank(int v){
        int x=0,y=0;
        split(root,v-1,x,y);
        int ans=data[x].siz+1;
        merge(x,y);
        return ans;
    }
    void remove(int v){
        int x=0,y=0,z=0;
        split(root,v-1,x,y);
        split(y,v,y,z);
        removeNode(y);
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
int mi,mx;
int n,m;
//int h[100000];
//int id[100000];
unordered_map<int,int>h,id;
int lastans;
int main(){
    
    return 0;
}