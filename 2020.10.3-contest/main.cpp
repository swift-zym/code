#include<bits/stdc++.h>
using namespace std;
fstream in;
fstream code,error;
bool autoRun=0;
int main(){
    string s;
    int len=0;
    in.open("name.z");
    code.open("name.cpp");
    error.open("name.error.txt");
    while(getline(in,s)){
        len++;
        if(s[0]=='@'){
            string cmd=s.substr(1,s.length()-1);
            if(cmd=="Main"){
                code<<"int main(int argc,char *argv[]){"<<endl;
            }
            else if(cmd=="All"){
                code<<"#include<bits/stdc++.h>"<<endl;
                code<<"using namespace std;"<<endl;
            }
            else if(cmd=="AutoRun"){
                autoRun=1;
            }
            else if(cmd.length()==0){
                code<<"}"<<endl;
            }
            else{
                error<<"Too many '@' at len "<<len<<"!"<<endl;
                return 1;
            }
        }
        else if(s[0]=='~'){
            code<<s.substr(1,s.length()-1)<<";"<<endl;

        }
    }
    if(autoRun){
        system("g++ name.cpp -o name");
        system("start name.exe");
    }
    return 0;
}