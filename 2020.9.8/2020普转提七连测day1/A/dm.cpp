#include<bits/stdc++.h>
using namespace std;
void out(int x){
    string tmp=to_string(x)+".in";
    freopen(tmp.c_str(),"w",stdout);
}
int main(){
    for(int i=1;i<=6;i++){
        out(i);
        cout<<500<<" ";
        cout<<rand()%100+400<<endl;
        for(int i=1;i<=500;i++){
            cout<<rand()%400+100<<" ";
        }
        cout<<endl;
    }
    return 0;
}