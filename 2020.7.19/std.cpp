//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=300007;
int i,j,k,l,n,m,ans,x;
struct node{
    int mi,sum,bz;
}t[maxn*4];
int a[maxn],b[maxn],c[maxn];
char s[10];
void dfs(int x){
    if(x>30000)return;
    b[++b[0]]=x;
    dfs(x*10+2);dfs(x*10+3);
}
void merge(int x){
    if(t[x*2].mi<t[x*2+1].mi)t[x].mi=t[x*2].mi,t[x].sum=t[x*2].sum;
    if(t[x*2].mi>t[x*2+1].mi)t[x].mi=t[x*2+1].mi,t[x].sum=t[x*2+1].sum;
    if(t[x*2].mi==t[x*2+1].mi)t[x].mi=t[x*2].mi,t[x].sum=t[x*2].sum+t[x*2+1].sum;
}
void build(int x,int l,int r){
    if(l==r){
        c[l]=1;while(b[c[l]]<a[l])c[l]++;
        t[x].mi=b[c[l]]-a[l];t[x].sum=1;
        return;
    }
    int mid=(l+r)/2;
    build(x*2,l,mid);build(x*2+1,mid+1,r);
    merge(x);
}
void down(int x){
    if(t[x].bz){
        t[x*2].bz+=t[x].bz;t[x*2+1].bz+=t[x].bz;
        t[x*2].mi-=t[x].bz;t[x*2+1].mi-=t[x].bz;
        t[x].bz=0;
    }
}
void gai(int x,int l,int r){
    if(t[x].mi>=0)return;
    if(l==r){
        while(t[x].mi<0)t[x].mi+=b[c[l]+1]-b[c[l]],c[l]++;
        return;
    }
    down(x);
    int mid=(l+r)/2;
    gai(x*2,l,mid);gai(x*2+1,mid+1,r);
    merge(x);
}
void change(int x,int l,int r,int y,int z,int o){
    gai(x,l,r);
    if(l==y&&r==z){
        t[x].mi-=o;t[x].bz+=o;
        gai(x,l,r);
        return;
    }
    down(x);
    int mid=(l+r)/2;
    if(z<=mid)change(x*2,l,mid,y,z,o);
    else if(mid<y)change(x*2+1,mid+1,r,y,z,o);
    else change(x*2,l,mid,y,mid,o),change(x*2+1,mid+1,r,mid+1,z,o);
    merge(x);
}
int find(int x,int l,int r,int y,int z){
    if(l==y&&r==z){
        if(!t[x].mi)return t[x].sum;return 0;
    }
    down(x);
    int mid=(l+r)/2;
    if(z<=mid)return find(x*2,l,mid,y,z);
    else if(mid<y)return find(x*2+1,mid+1,r,y,z);
    else return find(x*2,l,mid,y,mid)+find(x*2+1,mid+1,r,mid+1,z);
    merge(x);
}
int main(){
    freopen("hack3.in","r",stdin);
    freopen("hack3.out","w",stdout);
    scanf("%d%d",&n,&m);
    fo(i,1,n)scanf("%d",&a[i]);
    dfs(2);dfs(3);sort(b+1,b+1+b[0]);b[++b[0]]=0x7fffffff;
    build(1,1,n);
    while(m--){
        scanf("%s%d%d",s,&k,&l);
        if(s[0]=='a'){
            scanf("%d",&x);
            change(1,1,n,k,l,x);}
        else printf("%d\n",find(1,1,n,k,l));
    }
}
/*
CF121E
*/