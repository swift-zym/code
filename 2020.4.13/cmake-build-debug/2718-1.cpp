//
// Created by 张成 on 2020/4/21.
//

#include<bits/stdc++.h>
#define MOD 9901
using namespace std;
int inv[20001],jcinv[20001],jc[20001];
int lucas(int a,int b){
    if(b==0)return 1;
    if(a<MOD){
        return jc[a]*jcinv[b]%MOD*jcinv[a-b]%MOD;
    }
    else{
        return lucas(a/MOD,b/MOD)*lucas(a%MOD,b%MOD)%MOD;
    }
}
 int main(){
    jc[0]=inv[0]=jcinv[0]=1;
    jc[1]=inv[1]=jcinv[1]=1;
    for(int i=2;i<9901;i++){
        jc[i]=jc[i-1]*i;
        jc[i]%=MOD;
        inv[i]=(MOD-MOD/i)*inv[MOD%i];
        inv[i]%=MOD;
        jcinv[i]=jcinv[i-1]*inv[i];
        jcinv[i]%=MOD;
    }
    int n,m;
    cin>>n>>m;
    cout<<lucas(n,m);
    return 0;
}