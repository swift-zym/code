#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=1,b=2,total=2;
    while(a+b<=4000000){
        swap(a,b);
        b=a+b;
        if(b%2==0)total+=b;
    }
    printf("%d\n",total);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}