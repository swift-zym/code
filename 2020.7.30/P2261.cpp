//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
signed main(){
    cin>>n>>k;
    int ans=n*k;
    for(int i=1,j;i<=n;i=j+1){
        j=(k/i==0)?n:min(n,k/(k/i));
        ans-=(k/i)*(i+j)*(j-i+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}