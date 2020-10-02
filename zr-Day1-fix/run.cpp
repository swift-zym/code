#include<bits/stdc++.h>
using namespace std;
int main(){
    system("g++ zr-Day1-fix/std.cpp -o zr-Day1-fix/std -std=c++17");
    for(int i=1;i<=10;i++){
        string cmd="touch zr-Day1-fix/"+to_string(i)+".out";
        cout<<cmd<<endl;
        system(cmd.c_str());
        cmd="./zr-Day1-fix/std <zr-Day1-fix/"+to_string(i)+".in >zr-Day1-fix/"+to_string(i)+".out";
        //string cmd="start cmd.exe";
        cout<<cmd<<endl;
        system(cmd.c_str());
    }
    return 0;
}