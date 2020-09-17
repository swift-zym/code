//
// Created by swift on 2020/7/21.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct SAM{
    struct node{
        int go[11];
        int fail,val,ans;
    }a[2000000];
    int cnt=1;
    int tmp[2000000];
    int id[2000000];
    int ans,last=1;
    int solve(){
        return ans;
    }
    void add(int num,int x,int last){
        int p=last;
        int np=++cnt;
        id[num]=np;
        a[np].val=a[p].val+1;
        a[np].ans=1;
        last=np;
        while(p&&a[p].go[x]==0){
            a[p].go[x]=np;
            p=a[p].fail;
        }
        if(!p){a[np].fail=1;ans+=a[np].val-a[a[np].fail].val;return;}
        int q=a[p].go[x];
        if(a[q].val==a[p].val+1){
            a[np].fail=q;
            ans+=a[np].val-a[a[np].fail].val;
            return;
        }
        int nq=++cnt;
        a[nq].val=a[p].val+1;
        memcpy(a[nq].go,a[q].go,sizeof(a[q].go));
        a[nq].fail=a[q].fail;
        a[q].fail=nq;
        a[np].fail=nq;
        while(p&&a[p].go[x]==q){
            a[p].go[x]=nq;
            p=a[p].fail;
        }
        ans+=a[np].val-a[a[np].fail].val;
    }
}sam;

signed main(){

    return 0;
}