//
// Created by swift on 2020/8/1.
//

#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    freopen("data.in","w",stdout);
    cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%i+1<<" ";;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%10000000<<" ";
    }
    cout<<endl;
    return 0;
}