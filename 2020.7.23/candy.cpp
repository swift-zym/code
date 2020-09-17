//
// Created by swift on 2020/7/23.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
 * a b c ... 1
 * 100 010 001 ... 2
 * j   j   j
 * 011 101 110 ... 4
 * e   e   e
 * 211 121 112 ... 8
 * 233 323 332 ... 16
 *
 */
namespace DEBUG {
    int num = 0;

    void solve(int a, int b, int c) {
        if (a % 2 || b % 2 || c % 2)return;
        solve(b / 2 + c / 2, a / 2 + c / 2, a / 2 + b / 2);
        num++;
    }

    void test(int n) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    if (i == j && j == k)continue;
                    num = 0;
                    int ans;
                    solve(i, j, k);
                    int bas = 1;
                    for (int ii = 1;; ii++) {
                        bas *= 2;
                        if (i % 2 || j % 2 || k % 2) {
                            ans = 0;
                            break;
                        }
                        if (i % bas != j % bas || j % bas != k % bas) {
                            ans = ii - 1;
                            break;
                        }
                    }
                    if (ans != num) {
                        cout << i << " " << j << " " << k << endl;
                        cout << ans << " " << num << endl;
                        puts("error");
                    }
                }
            }
    }
}
int T;
signed main(){
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int bas = 1,ans;
        if(a==b&&b==c)ans=-1;
        else
        for (int ii = 1;; ii++) {
            bas *= 2;
            if (a % 2 || b % 2 || c % 2) {
                ans = 0;
                break;
            }
            if (a % bas != b % bas || b % bas != c % bas) {
                ans = ii - 1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}