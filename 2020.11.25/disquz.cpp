#include<cstdio>
#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
string readFromShareFile(){
    FILE *share=fopen("share.txt","r+");
    char s[100];
    fscanf(share,"%s",s);
    if(strcmp(s,"%STOP%")==0){
        cout<<"exiting...";
        exit(0);
    }
    if(strcmp(s,"EOF")!=0){
        fclose(share);
        share=fopen("share.txt","w");
        fprintf(share,"EOF\n");
        fflush(share);
        fclose(share);
        return s;
    }
    fclose(share);
    return "null";
}
int main(){
    while(true){
        Sleep(1000);
        string tmp=readFromShareFile();
        if(tmp=="null")continue;
        cout<<"Sam:"<<tmp<<endl;
    }
    return 0;
}