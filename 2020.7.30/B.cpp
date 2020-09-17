//
// Created by swift on 2020/7/30.
//
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,m;
int u[2001],v[2001];
struct trie{
    int cnt;
    int son[15000000][2],end[15000000];
    void ins(int a){
        int bf=a;
        vector<int>v;
        while(a){
            v.push_back(a%2);
            a/=2;
        }
        while(v.size()<29){
            v.push_back(0);
        }
        int now=0;
        for(int i=28;i>=0;i--){
            if(!son[now][v[i]]){
                son[now][v[i]]=++cnt;
                now=cnt;
            }
            else{
                now=son[now][v[i]];
            }
        }
        end[now]=bf;
    }
    int ask(int a){
        int bf=a;
        vector<int>v;
        while(a){
            v.push_back(a%2);
            a/=2;
        }
        while(v.size()<29){
            v.push_back(0);
        }
        int now=0;
        for(int i=28;i>=0;i--){
            if(son[now][v[i]^1]){
                now=son[now][v[i]^1];
            }
            else if(son[now][v[i]]){
                now=son[now][v[i]];
            }
            else{
                return 0;
            }
        }
        return bf^end[now];
    }
}tr;
int sumu[2001],sumv[2001];
int ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&u[i]);
    for(int i=1;i<=m;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)sumu[i]=(sumu[i-1]^u[i]);
    for(int i=1;i<=m;i++)sumv[i]=(sumv[i-1]^v[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            ans=max(ans,sumu[j]^sumu[i-1]);
            if((j-i)%2==0){
                tr.ins(sumu[j]^sumu[i-1]);
            }
        }
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++){
            ans=max(ans,sumv[j]^sumv[i-1]);
            if((j-i)%2==0){
                ans=max(ans,tr.ask(sumv[j]^sumv[i-1]));
            }
        }
    printf("%d\n",ans);
    return 0;
}
/*
 * 1^1 1^2 1^3 1^4
 * 2^1 2^2 2^3 2^4
 * 3^1 3^2 3^3 3^4
 * 4^1 4^2 4^3 4^4
 */
/*
 * h%2->v
 * else->0
 * w%2->v
 * else->0
 */
