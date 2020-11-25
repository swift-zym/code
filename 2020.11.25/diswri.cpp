#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')s[i]='_';
        }
        FILE *share=fopen("share.txt","w");
        fprintf(share,"%s\n",s.c_str());
        fclose(share);
        if(s=="%STOP%"){
            cout<<"exiting...";
            exit(0);
        }
    }
    return 0;
}