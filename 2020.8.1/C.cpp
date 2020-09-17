//
// Created by swift on 2020/8/1.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
__int128 k,p;
__int128 read(){
    __int128 a=0;
    char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){
        a*=10;
        a+=(c-'0');
        c=getchar();
    }
    return a;
}
void print(__int128 a){
    if(a==0){
        cout<<0<<endl;
        return;
    }
    vector<char>c;
    while(a){
        c.push_back('0'+a%10);
        a/=10;
    }
    for(int i=c.size()-1;i>=0;i--){
        putchar(c[i]);
    }
    putchar(10);
}
__int128 ans;
signed main(){
    k=read();
    p=read();
    ans+=k*p*(p+1);
    ans+=p*k*(k-1);
    ans/=2;
    ans%=p*p;
    print(ans);
    return 0;
}
/*
 * 1 3 6->2
 * 1 5 15->3
 * 1 7 28->4
 * 1 11 66->6
 * 1 13 91->7
 * 1 17 153->9
 */