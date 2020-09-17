//
// Created by swift on 2020/8/8.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=min(c+d,d*2);
    if(a==b&&a==0){
        ans=0;
    }
    if(a==0||b==0){
        ans=min(ans,d);
    }
    if(a==b){
        ans=min(ans,c);
    }
    cout<<ans<<endl;
    return 0;
}
