#include<iostream>
#include<string>
#define MOD 998244353
using namespace std;
int main(){
    string username;
    cin>>username;
    int seed=20061212;
    for(auto c:username){
        seed<<=1;
        seed^=c;
        seed%=MOD;
    }
    short a=seed%256;
    seed>>=8;
    short b=seed%256;
    seed>>=8;
    short c=seed%256;
    seed>>=8;
    short d=seed%256;
    seed>>=8;
    printf("%X-%X-%X-%X\n",a<16?16:a,b<16?16:b,c<16?16:c,d<16?16:d);
    return 0;
}