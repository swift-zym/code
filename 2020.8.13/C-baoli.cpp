#include<bits/stdc++.h>
using namespace std;
map<string,int>ma;
int ans;
int n,m;
string s;
int main(){
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n-m+1;i++){
        string tmp=s.substr(i,m);
        if(!ma[tmp]){
            ma[tmp]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}