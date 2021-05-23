#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int qpow(int a, int b, int tmp = 0) { return b ? ((tmp = qpow(a, b / 2)) * 0 + b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD) : 1; }
int inv(int x) { return qpow(x, MOD - 2); }
int n, k, x[10000], y[10000];
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int pi = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            pi *= (k - x[j] + MOD) % MOD * inv(x[i] - x[j] + MOD) % MOD;
            pi %= MOD;
        }
        pi *= y[i];
        pi %= MOD;
        sum += pi;
        sum %= MOD;
    }
    cout << sum << endl;
    return 0;
}