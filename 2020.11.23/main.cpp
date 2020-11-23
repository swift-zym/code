#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("test.ce","r",stdin);
    freopen("test_run.cpp","w",stdout);
    string s;
    int line=0;
    while(getline(cin,s)){
        line++;
        if(s[0]!='!'){
            cout<<s<<endl;
        }
        else if(s=="!all"){
            cout<<"#include<bits/stdc++.h>"<<endl;
            cout<<"using namespace std;"<<endl;
        }
        else if(s=="!main"){
            cout<<"#ifdef int"<<endl;
            cout<<"signed main(int argc,char *argv[]){"<<endl;
            cout<<"#else"<<endl;
            cout<<"int main(int argc,char *argv[]){"<<endl;
            cout<<"#endif"<<endl;
        }
        else if(s=="!!"){
            cout<<"}"<<endl;
        }
        else{
            cerr<<"CE at line "<<line<<" ,can not find command \""<<s<<"\"."<<endl;
            return 1;
        }
    }
    cerr<<"Run command finished.";
    return 0;
}