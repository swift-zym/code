#include<bits/stdc++.h>
using namespace std;
int n;
string s[300001];
string ans="";
bool cmp(string a,string b){
    return a+b<b+a;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++)ans+=s[i];
    cout<<ans<<endl;
    return 0;
}