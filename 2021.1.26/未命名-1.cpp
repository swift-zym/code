#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;
int n, m, idx[3000000];
ll qpow(ll a, ll b) {
  if (b == 0) return 1;
  ll tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
ll a[3000000], b[3000000];
void NTT(ll *x, int len, int f) {
  for (int i = 0; i < len; i++) {
    if (i < idx[i]) swap(x[i], x[idx[i]]);
  }
  for (int mid = 1; mid < len; mid <<= 1) {
    ll bas = qpow(3, (MOD - 1) / (mid << 1));
    if (f == -1) bas = qpow(bas, MOD - 2);
    for (int s = 0, t = (mid << 1); s < len; s += t) {
      ll now = 1;
      for (int k = 0; k < mid; k++, now = (now * bas) % MOD) {
        ll a = x[s + k], b = now * x[s + mid + k] % MOD;
        x[s + k] = (a + b) % MOD;
        x[s + mid + k] = (a - b + MOD) % MOD;
      }
    }
  }
}
void poly_multiply(unsigned *_a, int _n, unsigned *_b, int _m, unsigned *c) {
  n = _n;
  m = _m;
  for (int i = 0; i <= n; i++) a[i] = _a[i];
  for (int i = 0; i <= m; i++) b[i] = _b[i];
  int len = 1, num = 0;
  while (len <= n + m) len <<= 1, num++;
  for (int i = 0; i < len; i++) {
    idx[i] = ((idx[i >> 1] >> 1) | ((i & 1) << (num - 1)));
  }
  NTT(a, len, 1);
  NTT(b, len, 1);
  for (int i = 0; i < len; i++) a[i] = (a[i] * b[i]) % MOD;
  NTT(a, len, -1);
  ll inv = qpow(len, MOD - 2);
  for (int i = 0; i <= n + m; i++) {
    c[i] = a[i] * inv % MOD;
  }
}