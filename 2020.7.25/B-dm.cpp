//
// Created by swift on 2020/7/25.
//

#include<bits/stdc++.h>
using namespace std;
int n=500;
int main(){
    freopen("data.in","w",stdout);
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%int(1e8)<<" ";
    }
    cout<<endl;
    return 0;
}