//
// Created by swift on 2020/8/11.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("A.in","w",stdout);
    int n=100000;
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%99999+1<<" ";
    }
    cout<<endl;
    return 0;
}