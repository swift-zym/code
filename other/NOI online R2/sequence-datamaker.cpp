//
// Created by 张成 on 2020/4/25.
//

#include<bits/stdc++.h>
using namespace std;
int a[8];
int main(){
    srand(time(0));
    freopen("sequence.in","w",stdout);
    int n=100;
    cout<<n<<endl;
    for(int i=1;i<=7;i++){
        a[i]=(long long)rand()*(long long)rand()%1000000007;
    }
    for(int i=1;i<=n;i++){
        if(rand()%2){
            cout<<a[rand()%7+1]<<" ";
        }
        else
        cout<<(long long)rand()*(long long)rand()%1000000007<<" ";
    }
    cout<<endl;
    return 0;
}