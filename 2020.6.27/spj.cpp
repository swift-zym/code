//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
FILE *ans,*out;
string s1="",s2="";
int main(int argc,char *argv[]){
    ans=fopen(argv[2],"r");
    out=fopen(argv[3],"r");
    char c;
    while(fscanf(ans,"%c",&c)!=EOF){
        if(c=='\\'||c=='/')
        s1+=c;
    }
    while(fscanf(out,"%c",&c)!=EOF){
        if(c=='\\'||c=='/')
        s2+=c;
    }
    if(s1==s2)
    return 0;
    else
    return -1;
}