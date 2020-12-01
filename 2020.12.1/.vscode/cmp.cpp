#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    while(++t){
        system(".\\dm.exe >a.in");
        system(".\\std.exe <a.in >a.out");
        system(".\\baoli.exe <a.in >a.ans");
        cout<<"testcase %"<<t<<": ";
        if(system("fc a.out a.ans")){
            puts("Accept");
        }
        else{
            puts("Wrong Answer");
            break;
        }
    }
    return 0;
}