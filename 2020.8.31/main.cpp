#include<bits/stdc++.h>
#define MAX_SIZE 10000
using namespace std;
class tree{
private:
    struct node{
        int l,r,sum,tag;
    }nodes[MAX_SIZE];
public:
    class node_helper{
        int get_size(node &x){return x.r-x.l+1;}
        void pushup(node &x,node &ls,node &rs){
            x.sum=ls.sum+rs.sum;
        }
        void pushdown(node &x,node &ls,node &rs){
            ls.sum+=get_size(ls)*x.tag;
            rs.sum+=get_size(rs)*x.tag;
            ls.tag+=x.tag;rs.tag+=x.tag;
            x.tag=NULL;
        }
        node init_node(int l,int r,int sum,int tag=0){
            node new_node;
            new_node.l=l;new_node.r=r;new_node.sum=sum;
            return new_node;
        }
    }base;
private:
    int node_size=-1;
    int root=1;
    void build(int now,int l,int r,vector<int>values=vector<int>()){
        nodes[now].l=l;nodes[now].r=r;
        int mid=(l+r)>>1;
        if(l==r){
            return;
        }
        build(now*2,l,mid,values);
        build(now*2+1,mid+1,r,values);
    }
public:
    tree(int size){
        node_size=size;
        build(root,1,node_size);
    }
    tree(){
        node_size=MAX_SIZE+1;
        build(root,1,node_size);
    }
};
int main(){
    
    return 0;
}