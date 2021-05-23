#include<bits/stdc++.h>
using namespace std;
int main(){
    string name;
    cin>>name;
    for(int i=1;i<=10;i++){
        string cmd="start std.exe ";
        cmd+=name+"\\"+to_string(i)+".in "+name+"\\"+to_string(i)+".out";
        system(cmd.c_str());
    }
    return 0;
}