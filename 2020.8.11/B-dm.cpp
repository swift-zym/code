//
// Created by swift on 2020/8/11.
//

#include<bits/stdc++.h>
using namespace std;
int n=10,m=10;
string s="UDLRU";
int main(){
    srand(time(0));
    freopen("B.in","w",stdout);
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<s[rand()%5];
        }
        cout<<endl;
    }
    return 0;
}