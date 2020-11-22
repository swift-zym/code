#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD; 
}
signed main(){
    //freopen("magic.in","r",stdin);
    //freopen("magic.txt","w",stdout);
    int n;
    string s;
    cin>>n;
    cin>>s;
    int l=s.length();
    if(n==l){
        cout<<(qpow(26,n)-1+MOD)%MOD<<endl;
        return 0;
    }
    cout<<(qpow(26,n)-qpow(26,n-l)-l*25%MOD*qpow(26,n-l-1)%MOD+(long long)MOD*10)%MOD<<endl;
    return 0;
}