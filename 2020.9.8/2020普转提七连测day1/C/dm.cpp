#include<bits/stdc++.h>
using namespace std;
void out(int x){
    string tmp=to_string(x)+".in";
    freopen(tmp.c_str(),"w",stdout);
}
long long bigrand(){
    return (long long)rand()*rand();
}
int main(){
    for(int i=1;i<=3;i++){
        out(i);
        cout<<10<<endl;
        for(int i=1;i<=10;i++){
            cout<<rand()%3+1<<" ";
        }
        cout<<endl;
        for(int i=1;i<=10;i++){
            cout<<rand()%1000000+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}