//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
using namespace std;
string base="abacaba";
bool judge_sub(string s,bool type=0){
    //cout<<s<<endl;
    for(int i=0;i<7;i++){
        if(type==0)if(s[i]=='?')continue;
        if(s[i]!=base[i])return 0;
    }
    //cout<<"OK!"<<endl;
    return 1;
}
bool flag=0;
bool judge_fin(string s){
    int len=s.length(),num=0;
    for(int i=0;i<len-6;i++){
        string tmp=s.substr(i,7);
        if(judge_sub(tmp,1)){
            num++;
        }
        if(s[i]=='?')s[i]='z';
    }
    if(num!=1)return 0;
    for(int i=len-6;i<len;i++){
        if(s[i]=='?')s[i]='z';
    }
    flag=1;
    puts("Yes");
    cout<<s<<endl;
}
void judge(string s){
    int len=s.length();
    for(int i=0;i<len-6;i++){
        string tmp=s.substr(i,7);
        //cout<<tmp<<endl;
        if(judge_sub(tmp)){
            string cp=s;
            for(int j=i;j<=i+6;j++){
                cp[j]=base[j-i];
            }
            if(judge_fin(cp))return;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        flag=0;
        int n;
        cin>>n;
        string s;
        cin>>s;
        judge(s);
        if(!flag){
            puts("No");
        }
    }
    return 0;
}