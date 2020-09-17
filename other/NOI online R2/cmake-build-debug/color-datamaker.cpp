//
// Created by 张成 on 2020/4/25.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","w",stdout);
    srand(time(0));
    cout<<100000<<endl;
    for(int i=1;i<=100000;i++){
        cout<<rand()<<" "<<rand()<<" "<<10<<endl;
    }
    return 0;
}