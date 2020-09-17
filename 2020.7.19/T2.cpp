//
// Created by swift on 2020/7/19.
//
#include<bits/stdc++.h>
using namespace std;
int n,m,judge[20001];
int a[310000],t[310000],ok[310000];
void add(int x,int v){
    for(int i=x;i<=n;i+=i&-i){
        t[i]+=v;
    }
}
int ask(int x){
    int v=0;
    for(int i=x;i;i-=i&-i){
        v+=t[i];
    }
    return v;
}
bool jud(int a){
    if(!a)return 0;
    while(a){
        int v=a%10;
        if(v!=4&&v!=7)return 0;
        a/=10;
    }
    return 1;
}
int main(){
    for(int i=1;i<=20000;i++)judge[i]=jud(i);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(ok[i]=judge[a[i]])add(i,1);
    }
    for(int i=1;i<=m;i++){
        char s[10];
        scanf("%s",s);
        if(s[0]=='c'){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",ask(r)-ask(l-1));
        }
        else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            for(int j=l;j<=r;j++){
                a[j]+=x;
                bool flag=judge[a[j]];
                if(flag!=ok[j]){
                    add(j,flag?1:-1);
                    ok[j]=flag;
                }
            }
        }
    }
    return 0;
}