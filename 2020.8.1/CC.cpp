//
// Created by swift on 2020/8/1.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,p,mod;
int qpow(int a,int b){
    if(!b)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%mod*a%mod:tmp*tmp%mod;
}
int ans;
signed main(){

    while(cin>>k>>p) {
        ans=0;
        mod = p * p;
        for (int i = 1; i <= k * p; i++) {
            ans += qpow(i, 2 * p - 1);
            ans %= mod;
        }
        cout << ans << endl;
    }
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
/*
 * 2 3 6
 * 2 5 10
 * 2 7 14
 * 2 9 18
 * 2 11 22
 * 2 13 26
 * 2 17 34
 */
/*
 * 3 3 0 0
 * 3 5 10 2
 * 3 7 7  1
 * 3 11 110 10
 * 3 13 143 11
 * 3 15 90 6
 * 3 17 221 13
 * 3 21 0 0
 * 3 23 368 16
 */
/*
 * 4 3 6 2
 * 4 5 15 3
 * 4 7 7 1
 * 4 9 54 6
 * 4 11 88 8
 * 4 13 104 8
 * 4 15 60 4
 * 4 17 136 9
 */