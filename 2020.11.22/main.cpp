#include<iostream>
using namespace std;
int main(int argc,char *argv[]){
    if(argc<3){
        puts("Too few argv");
        return 1;
    }
    int a,b;
    sscanf(argv[1],"%d",&a);
    sscanf(argv[2],"%d",&b);
    cout<<a+b<<endl;
    return 0;
}