//LUOGU U73954
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll a,ll b){
    if(b==0)return 1;
    ll tmp=qpow(a,b/2);
    return b%2?tmp*tmp*a:tmp*tmp;
}
int main(){
   string s;
   cin>>s;
   cout<<s.length()<<endl;
   if(s.length()%2){
       cout<<"-l";
   }
   else{
       cout<<qpow(s.length(),s.length()/2)<<endl;
       cout<<"sxz love 2019dxlx05";
   }
   #ifdef WIN32
   system("pause");
   #endif
}