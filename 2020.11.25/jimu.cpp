#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct status{
    vector<string> s;double c;int deep;
};
queue<status>q;
double ans;
int n;
string s;
int main(){
    status tmp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        tmp.s.push_back(s);
    }
    reverse(tmp.s.begin(),tmp.s.end());
    tmp.deep=0;
    tmp.c=1;
    q.push(tmp);
    while(!q.empty()){
        auto now=q.front();q.pop();
        q.push({now.s,now.c/6,now.deep+1});
        bool flag=0;
        for(auto &&s:now.s){
            if(s[1]=='R'&&s[0]!='X'&&s[2]!='X'){
                s[1]='X';flag=1;
            }
        }
        puts("---");
        if(!flag){
            for(auto &&s:now.s){
                if(s[0]=='R'&&s[1]!='X'){
                    s[0]='X';flag=1;
                }
                if(s[2]=='R'&&s[1]!='X'){
                    s[2]='X';flag=1;
                }
            }
        }
        if(!flag){ans+=now.c/6*(now.deep+1);}
        else{
            if(now.s[now.s.size()-1][0]=='X'){
                now.s[now.s.size()-1][0]!='R';
            }
            else if(now.s[now.s.size()-1][1]=='X'){
                now.s[now.s.size()-1][1]!='R';
            }
            else if(now.s[now.s.size()-1][2]=='X'){
                now.s[now.s.size()-1][2]!='R';
            }
            else{
                now.s.push_back("RXX");
            }
            q.push({now.s,now.c/6,now.deep+1});
        }
        flag=0;
        for(auto &&s:now.s){
            if(s[1]=='G'&&s[0]!='X'&&s[2]!='X'){
                s[1]='X';flag=1;
            }
        }
        if(!flag){
            for(auto &&s:now.s){
                if(s[0]=='G'&&s[1]!='X'){
                    s[0]='X';flag=1;
                }
                if(s[2]=='G'&&s[1]!='X'){
                    s[2]='X';flag=1;
                }
            }
        }
        if(!flag){ans+=now.c/3*(now.deep+1);}
        else{
            if(now.s[now.s.size()-1][0]=='X'){
                now.s[now.s.size()-1][0]!='G';
            }
            else if(now.s[now.s.size()-1][1]=='X'){
                now.s[now.s.size()-1][1]!='G';
            }
            else if(now.s[now.s.size()-1][2]=='X'){
                now.s[now.s.size()-1][2]!='G';
            }
            else{
                now.s.push_back("GXX");
            }
            q.push({now.s,now.c/3,now.deep+1});
        }
        flag=0;
        for(auto &&s:now.s){
            if(s[1]=='B'&&s[0]!='X'&&s[2]!='X'){
                s[1]='X';flag=1;
            }
        }
        if(!flag){
            for(auto &&s:now.s){
                if(s[0]=='B'&&s[1]!='X'){
                    s[0]='X';flag=1;
                }
                if(s[2]=='B'&&s[1]!='X'){
                    s[2]='X';flag=1;
                }
            }
        }
        if(!flag){ans+=now.c/3*(now.deep+1);}
        else{
            if(now.s[now.s.size()-1][0]=='X'){
                now.s[now.s.size()-1][0]!='B';
            }
            else if(now.s[now.s.size()-1][1]=='X'){
                now.s[now.s.size()-1][1]!='B';
            }
            else if(now.s[now.s.size()-1][2]=='X'){
                now.s[now.s.size()-1][2]!='B';
            }
            else{
                now.s.push_back("BXX");
            }
            q.push({now.s,now.c/3,now.deep+1});
        }
    }
    cout<<ans<<endl;
    return 0;
}