// Problem: D - Sky Reflector
// Contest: AtCoder - AtCoder Regular Contest 113
// URL: https://atcoder.jp/contests/arc113/tasks/arc113_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD 998244353
int n, m, k, ans, v[1000000], s[1000000];
int qpow(int a, int b) {
  if (b == 0) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
signed main() {
  cin >> n >> m >> k;
  if (n > m) swap(n, m);
  if (n == 1) {
    cout << qpow(k, m) << endl;
    return 0;
  }
  v[1] = s[1] = 1;
  for (int i = 2; i <= k; i++) {
    v[i] = (qpow(i, n) - s[i - 1] + MOD) % MOD;
    s[i] = (s[i - 1] + v[i]) % MOD;
  }
  for (int i = 1; i <= k; i++) {
    ans += qpow(k - i + 1, m) * v[i] % MOD;
    ans %= MOD;
  }
  // testlib_
  cout << ans << endl;
  return 0;
}