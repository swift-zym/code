//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>prime;
int np[100001],miu[100001];
void preWork(){
    np[1]=1;
    miu[1]=1;
    for(int i=2;i<=100000;i++){
        if(!np[i]){
            prime.push_back(i);
            miu[i]=-1;
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=100000;j++){
            if(i%prime[j]==0){
                np[i*prime[j]]=1;
                miu[i*prime[j]]=0;
                break;
            }
            else{
                np[i*prime[j]]=1;
                miu[i*prime[j]]=-miu[i];
            }
        }
    }
}
int n,a,b;
signed main(){
    preWork();
    scanf("%lld%lld",&a,&b);
    if(a>b)swap(a,b);
    int ans=0;
    for(int d=1;d<=a;d++)
    for(int i=1;i<=a/d;i++){
        ans+=d*miu[i]*(a/(i*d))*(b/(i*d));
    }
    printf("%lld\n",ans*2-a*b);
    return 0;
}