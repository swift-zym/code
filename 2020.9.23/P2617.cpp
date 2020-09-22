#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>ma;
int n,m,a[100001];
vector<int>v;
struct query{
    int type,l,r,k,x,y;
}q[100001];
struct node{
    int l,r,ls,rs,v;
}t[10000000];
int tot;
int newNode(int l,int r){
    t[++tot]={l,r,0,0,0};
    return tot;
}
int copyNode(int from){
    t[++tot]=t[from];
    return tot;
}
int main(){
    scanf("%d%d",&n,&m);
    tot=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);v.push_back(a[i]);
    }
    for(int i=1;i<=m;i++){
        char c=getchar();
        while(c!='Q'&&c!='C')c=getchar();
        if(c=='Q'){
            q[i].type=1;
            scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
        }
        else{
            q[i].type=2;
            scanf("%d%d%d",&q[i].x,&q[i].y);
            v.push_back(q[i].y);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ma[v[i]]=i+1;
    }
    for(int i=1;i<=n;i++){
        a[i]=ma[a[i]];
    }
    for(int i=1;i<=m;i++){
        if(q[i].type==2){
            q[i].y=ma[q[i].y];
        }
    }

    return 0;
}