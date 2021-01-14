#include<iostream>
#include<string>
#include"testdata.h"
using namespace std;
using namespace TestData;
int main(){
    cout<<Random.Int()<<endl;
    cout<<Random.Int(1,100)<<endl;
    cout<<(Random.Bool()?"true":"false")<<endl;
    cout<<Random.LongInt()<<endl;
    cout<<Random.Char()<<endl;
    cout<<Random.String()<<endl;
    Logger.error("file not found");
    Logger.warning("server return status code [302]");
    Logger.log("Opening file...");
    Logger.corret("Accept");
}