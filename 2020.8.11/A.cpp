//
// Created by swift on 2020/8/11.
//

#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
vector<int>prime,val[100001],num[100001];
int np[100001],tmp[100001],bf[100001];
void pre(){
    np[1]=1;
    for(int i=2;i<=100000;i++){
        if(!np[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=100000;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=2;i<=100000;i++){
        int tmp=i;
        for(int j=0;tmp!=1;j++){
            if(!np[tmp]){
                val[i].push_back(tmp);
                num[i].push_back(1);
                break;
            }
            int siz=0;
            while(tmp%prime[j]==0){
                tmp/=prime[j];
                siz++;
            }
            if(siz){
                val[i].push_back(prime[j]);
                num[i].push_back(siz);
            }
        }
    }
}
int n,a[100001],sum;
bool check(int x){
    memcpy(bf,tmp,sizeof(tmp));
    int bfs=sum;
    //cout<<x<<endl;
    for(int i=0;i<prime.size();i++){
        int bas=prime[i],tot=0;
        while(bas<=x&&tot<bf[prime[i]]){
            tot+=x/bas;
            bas*=prime[i];
        }
        bfs-=min(tot,bf[prime[i]]);
        bf[prime[i]]-=min(tot,bf[prime[i]]);
    }
    return bfs==0;
}
signed main(){
    freopen("min19.in","r",stdin);
    freopen("min19.my.out","w",stdout);
    pre();
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<val[a[i]].size();j++){
            tmp[val[a[i]][j]]+=num[a[i]][j];
            //cerr<<val[a[i]][j]<<"+="<<num[a[i]][j]<<endl;
            sum+=num[a[i]][j];
        }
    }
    //cerr<<tmp[2]<<" "<<tmp[5]<<endl;
    int l=1,r=1e18;
    while(l!=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    //cerr<<check(2000005);
    printf("%lld\n",l);
    //cout<<(double)clock()/CLOCKS_PER_SEC;
    return 0;
}
