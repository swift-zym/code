#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=1;i<=10;i++){
        string cmd="./std ";
        cmd+=to_string(i);
        cmd+=".in ";
        cmd+=to_string(i);
        cmd+=".out";
        cout<<cmd<<endl;
        system(cmd.c_str());
    }
    return 0;
}