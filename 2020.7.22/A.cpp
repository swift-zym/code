//
// Created by swift on 2020/7/22.
//

#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int qpow(int a,int b,int mod){
    if(b==0)return 1;
    int tmp=qpow(a,b/2,mod);
    return b%2?tmp*tmp%mod*a%mod:tmp*tmp%mod;
}
int a,b;
signed main(){
    cin>>a>>b;
    cout<<qpow(a,qpow(a,b-1,MOD-1),MOD)<<endl;
    return 0;
}