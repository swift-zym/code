//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
int phi(int n){
    int v=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            v=v/i*(i-1);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        v=v/n*(n-1);
    }
    return v;
}
int n,ans=0;
signed main(){
    cin>>n;
    for(int i=1;i*i<n;i++){
        if(n%i==0)
        ans+=i*phi(n/i)+(n/i)*phi(i);
    }
    int v=sqrt(n);
    if(v*v==n){
        ans+=v*phi(v);
    }
    cout<<ans<<endl;
    return 0;
}