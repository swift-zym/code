//
// Created by swift on 2020/8/2.
//

#include<bits/stdc++.h>
using namespace std;
int k,bas=7,ans=1;
int main(){
    cin>>k;
    bas%=k;
    while(bas!=0){
        bas*=10;
        bas+=7;
        bas%=k;
        ans++;
        if(ans>=10000000){
            puts("-1");
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
//7777777777777777777
//7*111111