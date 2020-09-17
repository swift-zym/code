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
    for(int i=7;i<=10;i++){
        out(i);
        cout<<100000<<" "<<(long long)(1e12)<<endl;
        for(int j=1;j<=100000;j++){
            cout<<bigrand()%(long long)(1e12)+1<<" "<<rand()<<endl;
        }
    }
    return 0;
}