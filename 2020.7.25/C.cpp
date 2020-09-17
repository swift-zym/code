//
// Created by swift on 2020/7/25.
//
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int s[100001],l[100001],r[100001];
int a[100001];
int n,x,y;
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
struct node{
    int x,v;
    bool operator <(const  node t)const{
        if(v!=t.v)
        return v<t.v;
        else
        return x<t.x;
    }
}b[100001];
void check(){
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++){
        b[i]={i,a[i]};
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            if(b[j]<b[i])swap(b[i],b[j]);
        }
    for(int i=1;i<=n;i++)cout<<"("<<b[i].x<<","<<b[i].v<<")";
    int v=0;
    for(int i=1;i<=n;i++){
        x+=i*s[b[i].x]%MOD;
        x%=MOD;
        v+=i*s[b[i].x]%MOD;
        v%=MOD;
    }
    cout<<endl;
    cout<<v<<endl;
    puts("---");
    y++;
}
void dfs(int deep){
    if(deep==n+1){
        check();
        return;
    }
    for(int i=l[deep];i<=r[deep];i++){
        a[deep]=i;
        dfs(deep+1);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&s[i],&l[i],&r[i]);
    }
    dfs(1);
    cout<<x<<" "<<y<<endl;
    x*=qpow(y,MOD-2);
    x%=MOD;
    printf("%lld\n",x);
    return 0;
}
//2*3*6*5