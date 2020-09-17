//
// Created by swift on 2020/7/18.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct xxj{
    int p[65];
    void ins(int x){
        for(int i=60;i>=0;i--){
            if(x&(1ll<<i)){
                if(p[i]==0){
                    p[i]=x;
                    break;
                }
                x^=p[i];
            }
        }
    }
    int ask(){
        int v=p[60];
        for(int i=59;i>=0;i--){
            if((v^p[i])>v){
                v^=p[i];
            }
        }
        return v;
    }
};
struct node{
    vector<int>v;
    int l,r;
}a[2100000];
void build(int now,int l,int r){
    a[now].l=l;
    a[now].r=r;
    if(l==r)return;
    int mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
}
void add(int now,int l,int r,int v){
    int L=a[now].l,R=a[now].r;
    if(l==L&&r==R){
        a[now].v.push_back(v);
        return;
    }
    int mid=(L+R)/2;
    if(l>mid){
        add(now*2+1,l,r,v);
    }
    else if(r<=mid){
        add(now*2,l,r,v);
    }
    else{
        add(now*2,l,mid,v);
        add(now*2+1,mid+1,r,v);
    }
}
int n,v[500001];
unordered_map<int,int>idx;
void dfs(int now,int l,int r,xxj tmp){
    //cout<<l<<"~"<<r<<endl;

    int L=a[now].l,R=a[now].r;
    for(int i=0;i<a[now].v.size();i++){
        tmp.ins(a[now].v[i]);
        //cout<<"add "<<a[now].v[i]<<endl;
    }
    if(l==r){
        printf("%lld\n",tmp.ask());
        return;
    }
    int mid=(L+R)/2;
    dfs(now*2,l,mid,tmp);
    dfs(now*2+1,mid+1,r,tmp);
}
signed main(){
    scanf("%lld",&n);
    build(1,1,n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        if(v[i]>0){
            idx[v[i]]=i;
        }
        else{
            //cout<<"add "<<idx[-v[i]]<<" "<<-v[i]<<endl;
            add(1,idx[-v[i]],i-1,-v[i]);
            idx[-v[i]]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]>0&&idx[v[i]]>0){
            //cout<<"add "<<idx[v[i]]<<" "<<n<<endl;
            add(1,idx[v[i]],n,v[i]);
        }
    }
    dfs(1,1,n,xxj());
    return 0;
}