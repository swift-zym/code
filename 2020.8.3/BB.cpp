//
// Created by swift on 2020/8/3.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,b[200001];
struct node{
    int l,r,g,lazy;
}a[800001];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void solve(int now,int v){
    int tmp=gcd(v,a[now].g);
    if(tmp%a[now].g!=0){
        a[now].g=tmp;
        return;
    }
    tmp/=a[now].g;

}
void pushdown(int now){
    if(!a[now].lazy)return;
    solve(now*2,a[now].lazy);
    solve(now*2+1,a[now].lazy);
    a[now*2].lazy+=a[now].lazy;
    a[now*2+1].lazy+=a[now].lazy;
}
int main(){
    scanf("%d",&n);
    return 0;
}