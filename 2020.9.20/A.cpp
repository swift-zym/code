#include<bits/stdc++.h>
using namespace std;
int n,k;string s;
int cmp(string a,string b){
    int len=a.length();
    int num=0;
    for(int i=0;i<len;i++){
        if(a[i]!=b[i]){
            num++;
        }
    }
    return num;
}
int main(){
    cin>>n>>k>>s;
    int ans=0;
    int len=k*2-n;
    if(len<0){
        cout<<cmp(s.substr(k),s.substr(n-k,k))<<endl;
        return 0;
    }
    return 0;
}
/*
xx......xx
*/
/*
--****
    --****
*/