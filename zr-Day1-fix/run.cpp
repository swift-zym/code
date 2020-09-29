#include<bits/stdc++.h>
using namespace std;
int main(){
    system("g++ std.cpp -o std.exe -std=c++17");
    for(int i=1;i<=10;i++){
        //string cmd="start std.exe >"+to_string(i)+".in <"+to_string(i)+".out";
        string cmd="start cmd.exe";
        system(cmd.c_str());
        system("dir");
        system("pause");
    }
    return 0;
}