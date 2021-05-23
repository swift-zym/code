#include"testlib.h"
#include<iostream>
#include<cstdio>
int main(int argc,char *argv[]){
    registerTestlibCmd(argc,argv);
    int out_a=ouf.readInt(),out_b=ouf.readInt();
    int ans_a=ans.readInt(),ans_b=ans.readInt();
    if(out_a==ans_a){
        if(out_b==ans_b){
            quitf(_ok,"");
            return 0;
        }
        quitp(30,"");
        return 0;
    }
    quitf(_wa,"");
    return 0;
}