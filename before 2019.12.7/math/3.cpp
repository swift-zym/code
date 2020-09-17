#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int a=600851475143;
    for(int i=2;i<=sqrt(600851475143);i++){
        while(a%i==0)a/=i;
        if(a==1){
            cout<<i<<endl;
            break;
        }
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}