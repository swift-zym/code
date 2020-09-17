//
// Created by 张成 on 2020/4/23.
//

#include<bits/stdc++.h>
using namespace std;
string random_string_with_SOS(int len){
    string s="";
    while(s.length()<len){
        s+="sos";
    }
    return s;
}
string random_string(int len){
    string s="";
    while(s.length()<len){
            char c = 'a' + rand() % 26;
            s += c;
    }
    return s;
}
int main(){
    srand(time(0));
    freopen("save10.in","w",stdout);
    cout<<100<<endl;
    for(int i=1;i<=100;i++) {
        cout << random_string(10) << endl;
        cout << random_string_with_SOS(100) << endl;
    }
    return 0;
}