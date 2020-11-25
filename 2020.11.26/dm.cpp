#include<iostream>
using namespace std;
string makeLao(){
    string tmp="l";
    while(tmp.length()<=5){
        string nxt="";
        for(auto s:tmp){
            if(s=='l')
            switch (rand()%4){
                case 0:
                    nxt+="lt";                
                    break;
                case 1:
                    nxt+="ltl";
                    break;
                default:
                    nxt+=s;
                    break;
            }
            else{
                nxt+=s;
            }
        }
        tmp=nxt;
    }
    return tmp;
}
string makeTui(){
    string tmp="l";
    while(tmp.length()<=5){
        string nxt="";
        for(auto s:tmp){
            if(s=='l')
            switch (rand()%4){
            case 0:
                nxt+="lt";                
                break;
            case 1:
                nxt+="ltl";
            case 2:
                nxt+="tl";
                break;
            default:
                nxt+=s;
                break;
            }
            else{
                nxt+=s;
            }
        }
        tmp=nxt;
    }
    return tmp;
}
FILE *in,*ans;
int main(){
    int t=10;
    ans=fopen("laotui.ans","w+");
    in=fopen("laotui.in","w+");
    fprintf(in,"%d\n",t);
    for(int i=1;i<=t;i++){
        if(rand()%2){
            fprintf(ans,"0\n");
            fprintf(in,"%s\n",makeLao().c_str());
        }
        else{
            fprintf(ans,"1\n");
            fprintf(in,"%s\n",makeTui().c_str());
        }
    }
    return 0;
}