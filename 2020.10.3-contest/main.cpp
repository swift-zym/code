#include<bits/stdc++.h>
using namespace std;
fstream in;
fstream code,error;
bool autoRun=0;
string subreplace(string resource_str, string sub_str, string new_str){
    string::size_type pos = 0;
    while((pos = resource_str.find(sub_str)) != string::npos) {
        resource_str.replace(pos, sub_str.length(), new_str);
    }
    return resource_str;
}
int main(){
    string s;
    int len=0;
    system("powershell rm name.cpp");
    system("powershell ni name.cpp");
    system("powershell rm name.error.txt");
    system("powershell ni name.error.txt");
    in.open("name.z");
    code.open("name.cpp");
    error.open("name.error.txt");
    while(getline(in,s)){
        string pre="";
        while(s[0]==' ')pre+=" ",s.erase(s.begin());
        cout<<pre<<endl;
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
            code<<" "<<s.substr(1,s.length()-1)<<";"<<endl;
        }
        else if(s[0]=='#'){
            code<<"/""/"<<s<<endl;
        }
        else if(s.substr(0,5)=="print"){
            string tmp=s.substr(6,s.length()-7);
            code<<"cout<<("<<tmp<<")<<endl;"<<endl;
        }
        else if(s.substr(0,5)=="input"){
            string tmp=s.substr(6,s.length()-7);
            code<<"cin>>"<<tmp<<";"<<endl;
        }
        else if(s=="pause()"){
            code<<"system(\"pause\");"<<endl;
        }
        else{
            s=subreplace(s,"var","auto");
            s=subreplace(s,"let","const auto");
            code<<s+";"<<endl;
        }
    }
    if(autoRun){
        system("g++ name.cpp -o name");
        system("start name.exe");
    }
    return 0;
}