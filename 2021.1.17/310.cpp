
// Problem: #310. 【UNR #2】黎明前的巧克力
// Contest: UOJ
// URL: https://uoj.ac/problem/310
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
void fwt(int *a, int len, int f = 1) {
  for (int l = 1; l < len; l <<= 1)
    for (int s = 0; s < len; s += (l << 1))
      for (int k = 0; k < l; k++) {
        int x = a[s + k], y = a[s + l + k];
        a[s + k] = (x + y) * f % MOD;
        a[s + l + k] = (x - y + MOD) % MOD * f % MOD;
      }
}
int n, a[2000000], b[2000000];
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    b[0] += 1;
    b[a[i]] += 2;
  }
  fwt(b, 1 << 20);
  int inv4 = qpow(4, MOD - 2);
  for (int i = 0; i < (1 << 20); i++) {
    int x = (3ll * n % MOD - b[i] + MOD) % MOD * inv4 % MOD;
    b[i] = ((x % 2 ? -1 : 1) * qpow(3, n - x) + MOD) % MOD;
  }
  fwt(b, 1 << 20, (MOD + 1) >> 1);
  cout << (b[0] - 1 + MOD) % MOD << endl;
  return 0;
}