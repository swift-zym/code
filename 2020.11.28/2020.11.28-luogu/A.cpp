#include<bits/stdc++.h>
using namespace std;
vector<int> to16(int x){
    vector<int>tmp;
    while(x){
        tmp.push_back(x%16);
        x/=16;
    }
    while(tmp.size()!=2)tmp.push_back(0);
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
int to10(vector<int>x){
    int bas=1,tmp=0;
    for(auto now:x){
        tmp+=now*bas;
        bas*=16;
    }
    return tmp;
}
string s;
void solve(string s){
    vector<int>x;
    if(s[1]>='0'&&s[1]<='9')x.push_back(s[1]-'0');
    else x.push_back(10+s[1]-'A');
    if(s[0]>='0'&&s[0]<='9')x.push_back(s[0]-'0');
    else x.push_back(10+s[0]-'A');
    x=to16(255-to10(x));
    if(x[0]<=9)putchar('0'+x[0]);
    else putchar('A'+x[0]-10);
    if(x[1]<=9)putchar('0'+x[1]);
    else putchar('A'+x[1]-10);
}
int main(){
    cin>>s;
    putchar('#');
    string tmp="ab";
    tmp[0]=s[1];tmp[1]=s[2];solve(tmp);
    tmp[0]=s[3];tmp[1]=s[4];solve(tmp);
    tmp[0]=s[5];tmp[1]=s[6];solve(tmp);
    putchar(10);
    return 0;
}