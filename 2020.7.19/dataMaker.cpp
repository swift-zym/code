//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    srand(time(0));
    freopen("hack3.in","w",stdout);
    n=m=50000;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        cout<<2333<<" ";
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        if(rand()%2){
            cout<<"count 1 "<<n<<endl;
        }
        else{
            cout<<"add 1 "<<n<<" 0"<<endl;
        }
    }
    return 0;
}